#include "s21_grep.h"
// 3 массива:  один под файлы, другой под шаблоны (то что ищем), третий под файлы (двумерные), один под флаги одномерный
void parsing(int argc, char **argv);
int main(int argc, char **argv) {

    parsing( argc,  argv);
    return 0;
}


void parsing(int argc, char **argv) {
    int error_cnt, flag_options;
    
    while ((flag_options = getopt_long(argc, argv, "e:ivclnhsf:o", NULL, NULL )) != -1) {
        printf("%c\n", flag_options);
        //printf ("%d\n", optind);
        //printf("%c\n", optarg);
        if (flag_options == e) {

        }
        if else (flag_options == i ) {

        }
        if else (flag_options == v ) {
            
        }
        if else (flag_options == c) {
            
        }
        if else (flag_options == l ) {
            
        }
        if else (flag_options == n ) {
            
        }
        if else (flag_options == h) {
            
        }
        if else (flag_options == s) {
            
        }
        if else (flag_options == f ) {
            
        }
        if else (flag_options == o ) {
            
        }
    }
}

