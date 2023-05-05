#include <stdio.h>
int file_position(int argc, char **argv);
void read_all_files(int argc, char **argv, int file_post, int *arr_flags);
int search_all_flags(char **argv, int file_post, int *arr_flags);

int main(int argc, char **argv) {
  int arr_flags[8] = {0};
  int file_post = file_position(argc, argv);
  int flags = search_all_flags(argv, file_post, arr_flags);
  if (flags != 1) {
    read_all_files(argc, argv, file_post, arr_flags);
    for (int i = 0; i < 8; i++) {
      printf("%d", arr_flags[i]);
    }
    printf("\n");
  }

  return 0;
}

int file_position(int argc, char **argv) {
  int i;
  for (i = 1; i < argc, argv[i][0] == '-'; i++)
    ;

  return i;
}

void read_all_files(int argc, char **argv, int file_post, int *arr_flags) {
  for (int i = file_post; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    int iter = 1;
    int end_line = 0;
    if (file == NULL) {
      printf("cat: %s: No such file or directory\n", argv[i]);
    } else {
      char content;
      while ((content = fgetc(file)) != EOF) {
        if ((arr_flags[4] == 1) && (content == '\t')) /* flag -t*/ {
          printf("^I");
        } else if ((arr_flags[1] == 1) && (content == '\n')) /* flag -e */ {
          printf("$\n");

        } else if ((arr_flags[2] == 1) &&
                   (end_line != 0 || iter == 1)) /* flag -n */ {
          printf("%6d\t", iter);
          printf("%c", content);
          iter++;
        } else {
          printf("%c", content);
        }
        if (content == '\n') {
          end_line++;
        } else {
          end_line = 0;
        }
      }
    }
    fclose(file);
  }
}

int search_all_flags(char **argv, int file_post, int *arr_flags) {
  int res = 0;
  char flags_amount[8] = {'b', 'e', 'n', 's', 't', 'v', 'E', 'T'};
  for (int i = 1; i < file_post; i++) {
    for (int j = 1; argv[i][j] != '\0'; j++) {
      int success = 0;
      for (int k = 0; k < 8; k++) {
        if (argv[i][j] == flags_amount[k]) {
          success = 1;
          arr_flags[k] = 1;
        }
      }
      if (success == 0) {
        res = 1;
        printf("cat: illegal option -- %c\n", argv[i][j]);
      }
    }
  }

  return res;
}
