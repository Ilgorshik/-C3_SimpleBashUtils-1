#include "s21_grep.h"
void files_samples(int argc, char **argv, char arr_templates[1000][1000],
                   int *counter);
void parsing(int argc, char **argv, int *counter);

int file_counter(int argc, char **argv);

int template_find(char arr_flags[10], char **arr_templates, char **arr_files,
                  char *arr_line_buffer);

int main(int argc, char **argv) {
  int counter = 0;
  char arr_flags[10], **arr_templates, **arr_files;

  parsing(argc, argv, &counter);
  file_opening(arr_flags, arr_templates, arr_files);
  return 0;
}

void parsing(int argc, char **argv, int *counter) {
  int flag_options, i = 0, n = 0;
  char arr_flags[10] = {0};
  char arr_templates[1000][1000] = {0};
  char arr_files[1000][1000] = {0};
  while ((flag_options = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) !=
         -1) {
    if (strchr(arr_flags, flag_options) == 0 && (flag_options != '?')) {
      arr_flags[i] = flag_options;
      i++;
    }
    if (flag_options == 'e') {
      strcpy(arr_templates[*counter], optarg);
      (*counter)++;
    } else if (flag_options == 'f') {
      files_samples(argc, argv, arr_templates, counter);
    }
  }
  if ((strchr(arr_flags, 'e') == 0) && (strchr(arr_flags, 'f')) == 0) {
    strcpy(arr_templates[0], argv[optind]);
    printf("%d\n", optind);
    strcpy(arr_files[0], argv[optind + 1]);

  } else {
    for (int k = 0; k < argc && optind < argc; k++ && optind++) {
      strcpy(arr_files[k], argv[optind]);
    }
  }
  printf("%s\n", arr_flags);
  printf("%s\n", arr_templates[0]);
  printf("%s\n", arr_files[0]);
}

void files_samples(int argc, char **argv, char arr_templates[1000][1000],
                   int *counter) {
  size_t n = 0;
  char *arr_line_buffer = {0};
  FILE *file = fopen(optarg, "r");
  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", optarg);
  } else {
    char current_line;
    while ((current_line = getline(&arr_line_buffer, &n, file)) != -1) {
      char *line_pos = strchr(arr_line_buffer, '\n');
      if (line_pos != 0) {
        *line_pos = '\0';
      }

      strcpy(arr_templates[*counter], arr_line_buffer);

      (*counter)++;
    }
    free(arr_line_buffer);
  }
}
int template_find(char arr_flags[10], char **arr_templates, char **arr_files,
                  char *arr_line_buffer) {
  regex_t regex;
  regcomp(&regex, arr_templates, 0);
  if (regexec(&regex, arr_line_buffer, 0, NULL, 0) == 0) {
    printf("Yes!"); //прописать вывод всего 
  }
  regfree(&regex);
  return 0;
}
// int flags_content(int flag_options) {
//   if (flag_options == e) {
//   }
//   if
//     else(flag_options == i) {
//     }
//   if
//     else(flag_options == v) {
//     }
//   if
//     else(flag_options == c) {
//     }
//   if
//     else(flag_options == l) {
//     }
//   if
//     else(flag_options == n) {
//     }
//   if
//     else(flag_options == h) {
//     }
//   if
//     else(flag_options == s) {
//     }
//   if
//     else(flag_options == f) {
//     }
//   if
//     else(flag_options == o) {
//     }
// }

int file_opening(char arr_flags[10], char **arr_templates, char **arr_files) {
  size_t n = 0;
  char *arr_line_buffer = {0};

  FILE *file = fopen(**arr_files, "r");
  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", **arr_files);
  } else {
    char current_line;
    while ((current_line = getline(&arr_line_buffer, &n, file)) != EOF) {
      template_find(arr_flags, arr_templates, arr_files, arr_line_buffer);
    }
  }
  fclose(file);
}
