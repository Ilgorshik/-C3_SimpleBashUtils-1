#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
#include <getopt.h>

struct grep_opt {
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
};