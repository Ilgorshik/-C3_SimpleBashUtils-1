#include "s21_grep.h"

int main(int argc, char **argv) {
  storage_arrays all_arrays = {0};
  if (argc > 2) {
    parsing(argc, argv, &all_arrays);
    // printing(all_arrays);
    file_opening(all_arrays);
  }
  return 0;
}

void parsing(int argc, char **argv, storage_arrays *all_arrays) {
  int flag_options, i = 0;
  while ((flag_options = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) !=
         -1) {
    if (strchr(all_arrays->arr_flags, flag_options) == 0 &&
        (flag_options != '?')) {
      all_arrays->arr_flags[i] = flag_options;
      i++;
    }
    if (flag_options == 'e') {
      strcpy(all_arrays->arr_templates[all_arrays->counter_templates], optarg);
      (all_arrays->counter_templates)++;
    } else if (flag_options == 'f') {
      flag_f(all_arrays);
    }
  }
  if ((strchr(all_arrays->arr_flags, 'e') == 0) &&
      (strchr(all_arrays->arr_flags, 'f')) == 0) {
    strcpy(all_arrays->arr_templates[0], argv[optind]);
    all_arrays->counter_templates++;
    for (all_arrays->counter_files = 0;
         ((all_arrays->counter_files) < argc) && (optind + 1 < argc);
         ((all_arrays->counter_files)++), (optind++)) {
      strcpy(all_arrays->arr_files[all_arrays->counter_files],
             argv[optind + 1]);
    }
  } else {
    for (all_arrays->counter_files = 0;
         ((all_arrays->counter_files) < argc) && (optind < argc);
         ((all_arrays->counter_files)++), (optind++)) {
      strcpy(all_arrays->arr_files[all_arrays->counter_files], argv[optind]);
    }
  }
}

void flag_f(storage_arrays *all_arrays) {
  size_t n = 0;
  char *arr_line_buffer = {0};
  FILE *file = fopen(optarg, "r");
  if (file == NULL) {
    if (strchr(all_arrays->arr_flags, 's') == 0) {
      fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
    }
  } else {
    char current_line;
    while ((current_line = getline(&arr_line_buffer, &n, file)) != -1) {
      char *line_pos = strchr(arr_line_buffer, '\n');
      if (line_pos != 0 && strlen(arr_line_buffer) > 1) {
        *line_pos = '\0';
      }

      strcpy(all_arrays->arr_templates[all_arrays->counter_templates],
             arr_line_buffer);

      (all_arrays->counter_templates)++;
    }
    if (arr_line_buffer) {
      free(arr_line_buffer);
    }
    fclose(file);
  }
}

int template_find(storage_arrays *all_arrays, char *line) {
  int compilation = 0;
  int find = 0;
  regex_t regex;
  regmatch_t pmatch[10];
  size_t nmatch = 1;
  for (int i = 0; i < (all_arrays->counter_templates); i++) {
    if (strchr(all_arrays->arr_flags, 'i') != 0) {
      compilation = regcomp(&regex, all_arrays->arr_templates[i], REG_ICASE);
    } else {
      compilation = regcomp(&regex, all_arrays->arr_templates[i], 0);
    }
    if ((compilation == 0) && regexec(&regex, line, nmatch, pmatch, 0) == 0) {
      find = 1;
      get_subtext(all_arrays->subtext, line, pmatch->rm_so, pmatch->rm_eo);
      all_arrays->subtext_count = subtext_count(all_arrays->subtext, line);
    }
    regfree(&regex);
  }
  if ((strchr(all_arrays->arr_flags, 'v') != 0 && find == 0) ||
      (strchr(all_arrays->arr_flags, 'v') == 0 && find == 1)) {
    find = 1;
  } else {
    find = 0;
  }

  return find;
}

void file_opening(storage_arrays all_arrays) {
  size_t n = 0;
  char *line = NULL;
  for (int i = 0; i < all_arrays.counter_files; i++) {
    FILE *file = fopen(all_arrays.arr_files[i], "r");
    if (file == NULL) {
      if (strchr(all_arrays.arr_flags, 's') == 0) {
        fprintf(stderr, "grep: %s: No such file or directory\n",
                all_arrays.arr_files[i]);
      }
    } else {
      char current_line = 0;
      int match_count = 0;
      int find = 0;
      int line_number = 0;
      while ((current_line = getline(&line, &n, file)) != -1) {
        line_number++;
        find = template_find(&all_arrays, line);
        result_printing(all_arrays, find, line, &match_count, 0,
                        all_arrays.arr_files[i], line_number);
      }
      result_printing(all_arrays, find, line, &match_count, 1,
                      all_arrays.arr_files[i], line_number);

      fclose(file);
    }
  }
  if (line) {
    free(line);
  }
}

void printing(storage_arrays all_arrays) {
  printf("flags:\n");
  printf("%s\n", all_arrays.arr_flags);
  printf("templates:\n");
  for (int m = 0; m < all_arrays.counter_templates; m++) {
    printf("%s\n", all_arrays.arr_templates[m]);
  }
  printf("files:\n");
  for (int l = 0; l < all_arrays.counter_files; l++)
    printf("%s\n", all_arrays.arr_files[l]);
}

void result_printing(storage_arrays all_arrays, int find, char *line,
                     int *match_count, int after_while, char *filename,
                     int line_number) {
  if (find == 1 && strchr(all_arrays.arr_flags, 'c') == 0 &&
      strchr(all_arrays.arr_flags, 'l') == 0 && after_while == 0) {
    if (all_arrays.counter_files > 1 &&
        strchr(all_arrays.arr_flags, 'h') == 0) {
      printf("%s:", filename);
    }
    if (strchr(all_arrays.arr_flags, 'n') != 0) {
      printf("%d:", line_number);
    }
    if (strchr(all_arrays.arr_flags, 'o') != 0 &&
        strchr(all_arrays.arr_flags, 'v') == 0) {
      for (int i = 0; i < all_arrays.subtext_count; i++) {
        printf("%s\n", all_arrays.subtext);
      }
    } else {
      if (strchr(line, '\n') == 0) {
        printf("%s\n", line);
      } else {
        printf("%s", line);
      }
    }
  }
  if (find == 1 && after_while == 0) {
    (*match_count)++;
  }
  if (after_while == 1) {
    if (strchr(all_arrays.arr_flags, 'l') != 0 && (*match_count) != 0) {
      *match_count = 1;
    }
    if (strchr(all_arrays.arr_flags, 'c') != 0) {
      if (all_arrays.counter_files > 1 &&
          strchr(all_arrays.arr_flags, 'h') == 0) {
        printf("%s:", filename);
      }
      printf("%d\n", *match_count);
    }
    if (strchr(all_arrays.arr_flags, 'l') != 0 && (*match_count) != 0) {
      printf("%s\n", filename);
    }
  }
}

void get_subtext(char *subtext, char *text, int start, int end) {
  int i = 0;
  for (i = 0; i < (end - start); i++) {
    subtext[i] = text[start + i];
  }
  subtext[i] = '\0';
}

int subtext_count(char *subtext, char *text) {
  int count = 0;
  int j = 0;
  for (int i = 0; i <= (int)(strlen(text) - strlen(subtext)); i++) {
    for (j = 0; j < (int)strlen(subtext) && subtext[j] == text[i + j]; j++) {
    }
    if (j == (int)strlen(subtext)) {
      count++;
    }
  }
  return count;
}