#include <stdio.h>
int file_position(int argc, char **argv);
void read_all_files(int argc, char **argv, int file_post);
int search_all_flags(char **argv, int file_post, int *arr_flags);

int main(int argc, char **argv) {
  int arr_flags[8] = {0};
  int file_post = file_position(argc, argv);
  int flags = search_all_flags(argv, file_post, arr_flags);
  if (flags != 1) {
    read_all_files(argc, argv, file_post);
    for (int i = 1; i < 8; i++) {
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

void read_all_files(int argc, char **argv, int file_post) {
  for (int i = file_post; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      printf("Error. File does not exist or can't be opened.\n");
    } else {
      char content;
      while ((content = fgetc(file)) != EOF) printf("%c", content);
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
        if (argv[i][j] == flags_amount[k]){
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