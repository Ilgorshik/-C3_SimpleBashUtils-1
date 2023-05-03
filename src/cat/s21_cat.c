#include <stdio.h>
int file_position(int argc, char argv[][]);
void read_all_files(int argc, char argv[][], int file_post);

int main(int argc, char argv[][]) {
  int file_post = file_position(argc, argv[][]);
  read_all_files(argc, argv[][], file_post);

  return 0;
}

int file_position(int argc, char argv[][]) {
  int i;
  for (i = 1; i < argc, argv[i][0] == '-'; i++)
    ;

  return i;
}

void read_all_files(int argc, char argv[][], int file_post) {
  for (i = file_post; i < argc - 1; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      printf("Error. File does not exist or can't be opened.\n");
    } else {
      char content;
      while ((content = fgets(file)) = !EOF) printf("%c", content);
    }
    fclose(file);
  }
}