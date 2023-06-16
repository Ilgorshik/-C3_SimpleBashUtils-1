#include "s21_grep.h"
void files_samples(int argc, char **argv, char arr_templates[100][100],
                   int *counter_templates, int *counter_files);
void parsing(int argc, char **argv, int *counter_templates, int *counter_files);

int file_counter_templates(int argc, char **argv);

int template_find(char arr_flags[10], char **arr_templates,
                  char *arr_line_buffer, int *counter_templates);
int file_opening(char arr_flags[10], char **arr_templates, char **arr_files, int *counter_templates, int *counter_files);

int main(int argc, char **argv) {
  int counter_templates = 0;
  int counter_files = 0;
  char arr_flags[10], **arr_templates, **arr_files;

  parsing(argc, argv, &counter_templates, &counter_files);

  
  file_opening(arr_flags, arr_templates, arr_files, &counter_templates, &counter_files);
  return 0;
}

void parsing(int argc, char **argv, int *counter_templates, int *counter_files) {
  int flag_options, i = 0;
  char arr_flags[10] = {0};
  char arr_templates[100][100] = {0}; //не нужно создавать в парсинге а нужно из мейна передать в функцию, лучше всего создать структуры куда запихать все массивы и везде таскать (создать в заголовке)
  char arr_files[100][100] = {0};
  while ((flag_options = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL)) !=
         -1) {
    if (strchr(arr_flags, flag_options) == 0 && (flag_options != '?')) {
      arr_flags[i] = flag_options;
      i++;
    }
    if (flag_options == 'e') {
      strcpy(arr_templates[*counter_templates], optarg);
      (*counter_templates)++;
    } else if (flag_options == 'f') {
      files_samples(argc, argv, arr_templates, counter_templates, counter_files);
    }
  }
  if ((strchr(arr_flags, 'e') == 0) && (strchr(arr_flags, 'f')) == 0) {
    strcpy(arr_templates[0], argv[optind]);
    printf("%d\n", optind);
    for (*counter_files = 0; ((*counter_files) < argc) && (optind + 1 < argc); ((*counter_files)++) , (optind++)) {
      strcpy(arr_files[*counter_files], argv[optind+1]);
    
    }
  } else {
    for (*counter_files = 0; ((*counter_files) < argc) && (optind < argc); ((*counter_files)++) , (optind++)) {
      strcpy(arr_files[*counter_files], argv[optind]);
    }
  }
  printf("%s\n", arr_flags);
  for (int m = 0; m <= *counter_templates; m++) {
  printf("%s\n", arr_templates[m]);
  }
  printf("files:\n");
  for (int l = 0; l < *counter_files; l++)
  printf("%s\n", arr_files[l]);
}

void files_samples(int argc, char **argv, char arr_templates[1000][1000],
                   int *counter_templates, int *counter_files) {
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

      strcpy(arr_templates[*counter_templates], arr_line_buffer);

      (*counter_templates)++;
    }
    free(arr_line_buffer);
  }
}
int template_find(char arr_flags[10], char **arr_templates,
                  char *arr_line_buffer, int *counter_templates) {
  regex_t regex;
  for (int i = 0; i < (*counter_templates); i++) {
    regcomp(&regex, arr_templates[i], 0);
    if (regexec(&regex, arr_line_buffer, 0, NULL, 0) == 0) {
      printf("Yes!"); //прописать вывод всего 
      //flags_content(flag_options);
    }
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

int file_opening(char arr_flags[10], char **arr_templates, char **arr_files, int *counter_templates, int *counter_files) {
  size_t n = 0;
  char *arr_line_buffer = {0};
  for (int i = 0; i < *counter_files; i++) {
  FILE *file =fopen(arr_files[i], "r");
  if (file == NULL) {
    fprintf(stderr, "grep: %s: No such file or directory\n", *arr_files);
  } else {
    char current_line;
    while ((current_line = getline(&arr_line_buffer, &n, file)) != EOF) {
      template_find(arr_flags, arr_templates, arr_line_buffer, counter_templates);
     
    }
  }
  fclose(file);
  }
}
