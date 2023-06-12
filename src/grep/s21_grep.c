#include "s21_grep.h"
char files_samples(int argc, char **argv, char arr_templates[1000][1000],
                   int *j);
void parsing(int argc, char **argv, int *j);

int file_counter(int argc, char **argv);

int main(int argc, char **argv) {
  int j = 0;
  char arr_flags[10], **arr_templates, **arr_files;

  parsing(argc, argv, &j);
  return 0;
}

void parsing(int argc, char **argv, int *j) {
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
      strcpy(arr_templates[*j], optarg);
      (*j)++;
    } else if (flag_options == 'f') {
      files_samples(argc, argv, arr_templates, j);
    }
    

  }

  //printf("%s\n", arr_flags);

  for (int k = 0; k < (*j); k++) {
    
    //printf("%s\n", arr_templates[k]);
  }
  if ((strchr(arr_flags, 'e') == 0) || (strchr(arr_flags, 'f')) == 0) {
    strcpy(arr_templates[0], argv[optind]);
    strcpy(arr_files[0], argv[optind+1]);
    printf("%s", arr_templates[0]);
    printf("%s", arr_files[0]);
  }
  // для флага ф и е, просто оптинд, сделать условие отдельно тут ниже.  массивы с флагами шаблонами файлами передавать в regex, а regex передается в функцию где открывается файл
}


char files_samples(int argc, char **argv, char arr_templates[1000][1000],
                   int *j) {
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

      strcpy(arr_templates[*j], arr_line_buffer);

      (*j)++;
    }
    free(arr_line_buffer);
  }
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

// int template_find(int argc, char **argv) {
//   regex_t regex;
//   regcomp(&regex, "int", 0);
//   if (regexec(&regex, "int main() {", 0, NULL, 0) == 0) {
//     printf("Yes!");
//   }
//   regfree(&regex);
//   return 0;
// }
// int file_opening(int argc, char **argv, ) {
//   if (flag_options != f || flag_options != e)
//     for (int i = argv[optind]; i < argc; i++) {
//       FILE *file = fopen(argv[i], "r");
//       if (file == NULL) {
//         fprintf(stderr, "grep: %s: No such file or directory\n", argv[i]);
//       } else {
//         char current_line;
//         while ((current_content = getline(file)) != EOF) {

//         }
//       }
//     }
// }