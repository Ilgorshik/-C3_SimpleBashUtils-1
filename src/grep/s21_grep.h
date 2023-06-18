#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct storage_arrays {
  char arr_flags[10];
  char arr_templates[100][100];
  int counter_templates;
  int counter_files;
  char arr_files[100][100];
  char subtext[100];
  int subtext_count;
} storage_arrays;

void parsing(int argc, char **argv, storage_arrays *all_arrays);
void printing(storage_arrays all_arrays);
void flag_f(storage_arrays *all_arrays);

int file_counter_templates(int argc, char **argv);

int template_find(storage_arrays *all_arrays, char *arr_line_buffer);
void file_opening(storage_arrays all_arrays);
void result_printing(storage_arrays all_arrays, int find, char *line,
                     int *match_count, int after_while, char *filename,
                     int line_number);
void get_subtext(char *subtext, char *text, int start, int end);
int subtext_count(char *subtext, char *text);