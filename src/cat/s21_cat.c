#include <stdio.h>
#include <string.h>

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
      //printf("%d", arr_flags[i]);
    }
  }

  return 0;
}

int file_position(int argc, char **argv) {
  int i;
  for (i = 1; i < argc && argv[i][0] == '-'; i++)
    ;

  return i;
}

void read_all_files(int argc, char **argv, int file_post, int *arr_flags) {
  for (int i = file_post; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    int iter = 1;
    int end_line = 1;
    int first_end_line = -1;
    int position_char = 0;
    if (file == NULL) {
      fprintf(stderr, "cat: %s: No such file or directory\n", argv[i]);
    } else {
      char current_content;
      while ((current_content = fgetc(file)) != EOF) {
        
        if ((arr_flags[3] == 1) && end_line > 1 && current_content == '\n') { //flag -s 
          continue;
        }

        if ((arr_flags[0] == 1) && (current_content != '\n') &&
            (end_line >= 1 || iter == 1)) { /* flag -b */
          printf("%6d\t", iter);
          iter++;
        } else if ((arr_flags[2] == 1 && arr_flags[0] == 0) &&
                   (end_line != 0 || iter == 1)) { /* flag -n */
          printf("%6d\t", iter);
          iter++;
        }

        if ((arr_flags[4] == 1 || arr_flags[7] == 1) && (current_content == '\t')) { /* flag -t, T*/
          printf("^I");
        }
      
        else if ((arr_flags[1] == 1 || arr_flags[6] == 1) &&
                   (current_content == '\n')) { /* flag -e, E */
          printf("$\n");
        } else if (arr_flags[5] == 1 || arr_flags[1] == 1 || arr_flags[4] == 1) {
          if (current_content >= 0 && current_content < 32 &&
              (current_content != 9) && (current_content != 10)) {
            printf("^%c", current_content + 64);
          }
          if (current_content == 127) {
            printf("^?");
          }
          if ((current_content >= 32 && current_content < 127) ||
              current_content == 9 || current_content == 10) {
            printf("%c", current_content);
          }
          if (current_content < 0) {
            current_content &=
                127;  // бинарное (побитовое) умножение, отбрасывающее
                      // отрицательный знак в первом бите
            int new_current_content = current_content + 128;

            if (new_current_content >= 128 && new_current_content < 160) {
              printf("M-^%c", new_current_content - 64);
            }
            if (new_current_content == 255) {
              printf("^?");
            }
            if (new_current_content >= 160 && new_current_content < 255) {
              printf("%c", new_current_content);
            }
          }

        }  else {
          printf("%c", current_content);
        }

        if (current_content == '\n') {
          end_line++;
          if (first_end_line == -1) {
            first_end_line = position_char;
          }
          position_char = -1;
        } else {
          first_end_line = -1;
          end_line = 0;
        }
        position_char++;
        
      }
    }
    fclose(file);
  }
}

int search_all_flags(char **argv, int file_post, int *arr_flags) {
  int res = 0;
 
  
  char linux_flags[][25] = {"--number-nonblank", "--number", "--squeeze-blank"};
  char flags_amount[8] = {'b', 'e', 'n', 's', 't', 'v', 'E', 'T'}; // t и s поменять местами
  for (int i = 1; i < file_post; i++) {
    if(argv[i][1] == '-') { 
      for (int k = 0; k < 3; k++) {
        if (strcmp(argv[i], linux_flags[k]) == 0) {
          arr_flags[k * 2] = 1;
        }
      }
    } else {
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
          fprintf(stderr, "cat: illegal option -- %c\n", argv[i][j]);
        }
      }

    }
  }

  return res;
}
