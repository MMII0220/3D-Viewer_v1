#ifndef SRC_L_H_
#define SRC_L_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define SIZE 1000
#define SIZE2 2000
#define CORRECTLY 1
#define ERROR 0

typedef struct axiss {
  double x_min;
  double x_max;
  double y_min;
  double y_max;
  double z_min;
  double z_max;
} axis;

typedef struct center {
  double x_center;
  double y_center;
  double z_center;
} cntr;

typedef struct data {
  unsigned int count_veretex;
  double *veretex;
  unsigned int count_index;
  unsigned int *index;
  cntr cntr;
  axis axis;
} obj;

typedef struct settings {
  double red;
  double green;
  double blue;
  double redl;
  double greenl;
  double bluel;
  double redv;
  double greenv;
  double bluev;
  int projection_type;
  int line_type;
  int vert_type;
  int vert_size;
  double thickness;
} set;

int open_file(char *path, obj *information);
int check_v(char *str);
int check_input_value(const char *str_x);
int check_f(char *str);
int check_number_top(char *str);
int open_file2(char *path, obj *information);
void parsing_v(char *str, obj *information, int *k);
void parsing_f(char *str, obj *information, int *l);
void start(obj *information, char *path);
int check_input_value_positiv_number(char *str_x);
void correct(obj *information);
void end(obj *information);

void writing_to_file(set *info);
int read_file(set *info);
void zapis_double(FILE *f, double *s);
void zapis_int(FILE *f, int *s);

double axis_maxdist(obj *res);
void rescale_obj(obj *data, double scale);
// void init_rescale(obj *data, double scale);

void move_x(obj *data, double val);
void move_y(obj *data, double val);
void move_z(obj *data, double val);
void rotate_x(obj *data, double rotate);
void rotate_y(obj *data, double rotate);
void rotate_z(obj *data, double rotate);
#endif  // SRC_L_H_