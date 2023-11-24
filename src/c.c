#include "l.h"

void start(obj *information, char *path) {
  if (open_file(path, information)) {
    information->veretex =
        (double *)calloc(information->count_veretex * 3, sizeof(double));
    information->index =
        (unsigned int *)calloc(information->count_index, sizeof(unsigned int));
    if (open_file2(path, information)) {
      correct(information);
    }
  }
}

void end(obj *information) {
  if (information->count_veretex) {
    free(information->veretex);
  }
  if (information->index) {
    free(information->index);
  }
}

void correct(obj *information) {
  double max = fabs(information->veretex[0]);
  for (unsigned int i = 0; i < information->count_veretex * 3; i++) {
    if (fabs(information->veretex[i]) > max)
      max = fabs(information->veretex[i]);
  }
  if (max > 1) {
    for (unsigned int i = 0; i < information->count_veretex * 3; i++) {
      information->veretex[i] *= 0.9 / max;
    }
  } else if (max < 1) {
    int k = 1 / max;
    for (unsigned int i = 0; i < information->count_veretex * 3; i++) {
      information->veretex[i] *= k;
    }
  }
}

int check_number_top(char *str) {
  int res_code = CORRECTLY;
  size_t i = 0, countslash = 0;
  while (str[i]) {
    if ((str[i] < '0' || str[i] > '9') && str[i] != '/') {
      res_code = ERROR;
    }
    if (str[i] == '/') {
      countslash++;
    }
    if (countslash > 2) {
      res_code = ERROR;
      break;
    }
    i++;
  }
  return res_code;
}

int check_input_value(const char *str_x) {
  int res_code = 1;
  int i = 0, flag_point = 0;
  while (str_x[i] != '\0') {
    if ((str_x[i] == '+' || str_x[i] == '-') && i != 0) {
      res_code = 0;
    } else if (str_x[i] < '0' && str_x[i] != '+' && str_x[i] != '-' &&
               str_x[i] != '.') {
      res_code = 0;
    } else if (str_x[i] > '9') {
      res_code = 0;
    }
    if (str_x[i] == '.') {
      if (flag_point) {
        res_code = 0;
      }
      if (str_x[i - 1] == '+' || str_x[i - 1] == '-') {
        res_code = 0;
      }
      flag_point = 1;
    }
    i++;
  }
  return res_code;
}

int check_v(char *str) {
  int res_code = ERROR;
  if (str[0] == 'v' && str[1] == ' ') {
    res_code = CORRECTLY;
    int j = 0;
    for (size_t i = 2; i < strlen(str); i++) {
      char tmp[SIZE];
      while (((str[i] >= '0' && str[i] <= '9') || str[i] == '+' ||
              str[i] == '-' || str[i] == '.') &&
             i < strlen(str)) {
        tmp[j] = str[i];
        j++;
        i++;
      }
      tmp[j] = '\0';
      if (!check_input_value(tmp)) {
        res_code = ERROR;
        break;
      }
      j = 0;
    }
  }
  return res_code;
}

int check_f(char *str) {
  int count = 0;
  if (str[0] == 'f' && str[1] == ' ') {
    char tmp[SIZE];
    int j = 0;
    for (size_t i = 2; i < strlen(str); i++) {
      while (((str[i] >= '0' && str[i] <= '9') || str[i] == '/') &&
             i < strlen(str)) {
        tmp[j] = str[i];
        j++;
        i++;
      }
      tmp[j] = '\0';
      if (check_number_top(tmp)) {
        count++;
      } else {
        count = 0;
        break;
      }
      j = 0;
    }
  }
  return count;
}

void parsing_f(char *str, obj *information, int *l) {
  int j = 0, count = 0, flag = 0, f = 0;
  double s1 = 0, s = 0;
  for (size_t i = 2; i < strlen(str); i++) {
    int m = 0;
    char tmp[SIZE];
    while (((str[i] >= '0' && str[i] <= '9') || str[i] == '/') &&
           i < strlen(str)) {
      tmp[j] = str[i];
      j++;
      i++;
      m = 1;
    }
    if (m) {
      char tmp2[SIZE2];
      count++;
      tmp[j] = '\0';
      j = 0;
      for (size_t k = 0; k < strlen(tmp); k++) {
        if (tmp[k] == '/') flag = 1;
      }
      if (flag) {
        while (tmp[j] != '/') {
          tmp2[j] = tmp[j];
          j++;
        }
      } else {
        while (tmp[j]) {
          tmp2[j] = tmp[j];
          j++;
        }
      }
      tmp2[j] = '\0';
      sscanf(tmp2, "%lf", &s1);
      information->index[*l] = s1 - 1;
      (*l)++;
      if (count > 1) {
        information->index[*l] = s1 - 1;
        (*l)++;
      }
      if (count == 1) {
        sscanf(tmp2, "%lf", &s);
        f = 1;
      }
      j = 0;
      flag = 0;
    }
  }
  if (f) {
    information->index[*l] = s - 1;
    (*l)++;
  }
}

void parsing_v(char *str, obj *information, int *k) {
  int j = 0, m = 0;
  double s1 = 0;
  for (size_t i = 2; i < strlen(str); i++) {
    char tmp[SIZE];
    while (i < strlen(str) && (str[i] != ' ')) {
      tmp[j] = str[i];
      j++;
      i++;
      m = 1;
    }
    if (m) {
      tmp[j] = '\0';
      sscanf(tmp, "%lf", &s1);
      information->veretex[*k] = s1;
      (*k)++;
      j = 0;
    }
  }
}

int open_file2(char *path, obj *information) {
  int res_code = 1;
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("No file\n");
    res_code = 0;
  } else {
    char str[SIZE];
    int k = 0, l = 0;
    while (fgets(str, SIZE - 1, file)) {
      if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
      if (check_v(str)) {
        parsing_v(str, information, &k);
      }
      if (check_f(str)) {
        parsing_f(str, information, &l);
      }
    }
    fclose(file);
  }
  return res_code;
}

int open_file(char *path, obj *information) {
  int res_code = 1;
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("No file\n");
    res_code = 0;
  } else {
    char str[SIZE];
    while (fgets(str, SIZE - 1, file)) {
      if ((str[strlen(str) - 1] == '\n') || (str[strlen(str) - 1] == 13))
        str[strlen(str) - 1] = '\0';
      if (check_v(str)) {
        information->count_veretex++;
      }
      if (check_f(str)) {
        information->count_index += check_f(str);
      }
    }
    fclose(file);
  }
  information->count_index *= 2;
  return res_code;
}

int read_file(set *info) {
  double s = 0;
  int s1 = 0, marker = 1;
  FILE *f;
  if ((f = fopen("/Users/deathstl/Desktop/save.txt", "r")) == NULL) {
    marker = 0;
  } else {
    zapis_double(f, &s);
    info->red = s;
    zapis_double(f, &s);
    info->green = s;
    zapis_double(f, &s);
    info->blue = s;
    zapis_double(f, &s);
    info->redl = s;
    zapis_double(f, &s);
    info->greenl = s;
    zapis_double(f, &s);
    info->bluel = s;
    zapis_double(f, &s);
    info->redv = s;
    zapis_double(f, &s);
    info->greenv = s;
    zapis_double(f, &s);
    info->bluev = s;
    zapis_int(f, &s1);
    info->projection_type = s1;
    zapis_int(f, &s1);
    info->line_type = s1;
    zapis_int(f, &s1);
    info->vert_type = s1;
    zapis_int(f, &s1);
    info->vert_size = s1;
    zapis_double(f, &s);
    info->thickness = s;
    fclose(f);
  }
  return marker;
}

void zapis_double(FILE *f, double *s) {
  char str[100];
  fgets(str, 100 - 1, f);
  if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
  sscanf(str, "%lf", s);
}

void zapis_int(FILE *f, int *s) {
  char str[100];
  fgets(str, 100 - 1, f);
  if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
  sscanf(str, "%d", s);
}

void writing_to_file(set *info) {
  FILE *f;
  f = fopen("/Users/deathstl/Desktop/save.txt", "w+");
  fprintf(f, "%lf\n", info->red);
  fprintf(f, "%lf\n", info->green);
  fprintf(f, "%lf\n", info->blue);
  fprintf(f, "%lf\n", info->redl);
  fprintf(f, "%lf\n", info->greenl);
  fprintf(f, "%lf\n", info->bluel);
  fprintf(f, "%lf\n", info->redv);
  fprintf(f, "%lf\n", info->greenv);
  fprintf(f, "%lf\n", info->bluev);
  fprintf(f, "%d\n", info->projection_type);
  fprintf(f, "%d\n", info->line_type);
  fprintf(f, "%d\n", info->vert_type);
  fprintf(f, "%d\n", info->vert_size);
  fprintf(f, "%lf\n", info->thickness);
  fclose(f);
}

double axis_maxdist(obj *data) {
  double result = 0.0;
  double x_dist = data->axis.x_max - data->axis.x_min;
  double y_dist = data->axis.y_max - data->axis.y_min;
  double z_dist = data->axis.z_max - data->axis.z_min;
  if (x_dist > y_dist) {
    if (x_dist > z_dist) {
      result = x_dist;
    } else {
      result = z_dist;
    }
  } else {
    if (y_dist > z_dist) {
      result = y_dist;
    } else {
      result = z_dist;
    }
  }
  return result;
}

void rescale_obj(obj *data, double scale) {
  data->axis.x_max *= scale;
  data->axis.x_min *= scale;
  data->axis.y_max *= scale;
  data->axis.y_min *= scale;
  data->axis.z_max *= scale;
  data->axis.z_min *= scale;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    data->veretex[i] *= scale;
    data->veretex[i + 1] *= scale;
    data->veretex[i + 2] *= scale;
  }
}

// void init_rescale(obj *data, double scale) {
//   double upscale = (scale - (scale * (-1))) / axis_maxdist(data);
//   rescale_obj(data, upscale);
// }

void move_x(obj *data, double val) {
  data->axis.x_max += val;
  data->axis.x_min += val;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    data->veretex[i] += val;
  }
}

void move_y(obj *data, double val) {
  data->axis.y_max += val;
  data->axis.y_min += val;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    data->veretex[i + 1] += val;
  }
}

void move_z(obj *data, double val) {
  data->axis.z_max += val;
  data->axis.z_min += val;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    data->veretex[i + 2] += val;
  }
}

void rotate_x(obj *data, double rotate) {
  double sin_x = sin(rotate);
  double cos_x = cos(rotate);
  double temp_y_max = data->axis.y_max;
  double temp_y_min = data->axis.y_min;
  double temp_z_max = data->axis.z_max;
  double temp_z_min = data->axis.z_min;
  data->axis.y_max = cos_x * temp_y_max - sin_x * temp_z_max;
  data->axis.y_min = cos_x * temp_y_min - sin_x * temp_z_min;
  data->axis.z_max = sin_x * temp_y_max + cos_x * temp_z_max;
  data->axis.z_min = sin_x * temp_y_min + cos_x * temp_z_min;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    double temp_y = data->veretex[i + 1];
    double temp_z = data->veretex[i + 2];
    data->veretex[i + 1] = cos_x * temp_y - sin_x * temp_z;
    data->veretex[i + 2] = sin_x * temp_y + cos_x * temp_z;
  }
}

void rotate_y(obj *data, double rotate) {
  double sin_y = sin(rotate);
  double cos_y = cos(rotate);
  double temp_x_max = data->axis.x_max;
  double temp_x_min = data->axis.x_min;
  double temp_z_max = data->axis.z_max;
  double temp_z_min = data->axis.z_min;
  data->axis.x_max = cos_y * temp_x_max + sin_y * temp_z_max;
  data->axis.x_min = cos_y * temp_x_min + sin_y * temp_z_min;
  data->axis.z_max = sin_y * (-temp_x_max) + cos_y * temp_z_max;
  data->axis.z_min = sin_y * (-temp_x_min) + cos_y * temp_z_min;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    double temp_x = data->veretex[i + 0];
    double temp_z = data->veretex[i + 2];
    data->veretex[i + 0] = cos_y * temp_x + sin_y * temp_z;
    data->veretex[i + 2] = sin_y * (-temp_x) + cos_y * temp_z;
  }
}

void rotate_z(obj *data, double rotate) {
  double sin_z = sin(rotate);
  double cos_z = cos(rotate);
  double temp_x_max = data->axis.x_max;
  double temp_x_min = data->axis.x_min;
  double temp_y_max = data->axis.y_max;
  double temp_y_min = data->axis.y_min;
  data->axis.x_max = cos_z * temp_x_max - sin_z * temp_y_max;
  data->axis.x_min = cos_z * temp_x_min - sin_z * temp_y_min;
  data->axis.y_max = sin_z * temp_x_max + cos_z * temp_y_max;
  data->axis.y_min = sin_z * temp_x_min + cos_z * temp_y_min;
  for (unsigned int i = 0; i < data->count_veretex * 3; i += 3) {
    double temp_x = data->veretex[i + 0];
    double temp_y = data->veretex[i + 1];
    data->veretex[i + 0] = cos_z * temp_x - sin_z * temp_y;
    data->veretex[i + 1] = sin_z * temp_x + cos_z * temp_y;
  }
}