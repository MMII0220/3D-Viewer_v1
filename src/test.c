#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "l.h"

START_TEST(incorrect_input) {
  obj a;
  int a_code = open_file("o.obj", &a);
  ck_assert_int_eq(a_code, 0);
}
END_TEST

START_TEST(correct_input) {
  obj a;
  int a_code = open_file("cube.obj", &a);
  ck_assert_int_eq(a_code, 1);
}
END_TEST

START_TEST(read_color_file) {
  set a;
  int check = read_file(&a);
  ck_assert_int_eq(check, 1);
}
END_TEST

START_TEST(axis_maxdist_test) {
  obj a;
  double check = axis_maxdist(&a);
  ck_assert_double_eq_tol(check, 0.000000, 1e-6);
}
END_TEST

START_TEST(writing_to_file_test) {
  set a;
  writing_to_file(&a);
  ck_assert_double_eq_tol(a.red, 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.green, 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.blue, 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.redl, 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.bluel, 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.greenv, 0.000000, 1e-6);
}
END_TEST

START_TEST(move_test) {
  obj a;
  start(&a, "cube.obj");
  double val = 2;
  move_x(&a, val);
  move_y(&a, val);
  move_z(&a, val);
  ck_assert_double_eq_tol(a.veretex[0], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[1], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[2], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[3], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[4], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[5], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[6], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[7], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[8], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[9], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[10], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[11], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[12], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[13], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[14], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[15], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[16], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[17], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[18], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[19], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[20], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[21], 1.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[22], 3.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[23], 1.000000, 1e-6);
  end(&a);
}
END_TEST

START_TEST(move_test2) {
  obj a;
  start(&a, "cube.obj");
  double val = -1;
  move_x(&a, val);
  move_y(&a, val);
  move_z(&a, val);
  ck_assert_double_eq_tol(a.veretex[0], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[1], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[2], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[3], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[4], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[5], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[6], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[7], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[8], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[9], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[10], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[11], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[12], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[13], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[14], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[15], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[16], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[17], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[18], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[19], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[20], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[21], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[22], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[23], -2.000000, 1e-6);
  end(&a);
}
END_TEST

START_TEST(rescale_rescale_test) {
  obj a;
  start(&a, "cube.obj");
  double scale = 2;
  rescale_obj(&a, scale);
  move_x(&a, scale);
  ck_assert_double_eq_tol(a.veretex[0], 4.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[1], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[2], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[3], 4.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[4], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[5], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[6], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[7], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[8], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[9], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[10], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[11], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[12], 4.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[13], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[14], -2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[15], 4.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[16], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[17], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[18], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[19], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[20], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[21], 0.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[22], 2.000000, 1e-6);
  ck_assert_double_eq_tol(a.veretex[23], -2.000000, 1e-6);
  end(&a);
}
END_TEST

START_TEST(rotate_test) {
  obj a;
  start(&a, "cube.obj");
  double rotate = 2;
  rotate_x(&a, rotate);
  rotate_y(&a, rotate);
  rotate_z(&a, rotate);
  ck_assert_double_eq_tol(a.veretex[0], -0.845436, 1e-3);
  ck_assert_double_eq_tol(a.veretex[1], -1.33773, 1e-3);
  ck_assert_double_eq_tol(a.veretex[2], -0.704074, 1e-3);
  ck_assert_double_eq_tol(a.veretex[3], 1.12315, 1e-3);
  ck_assert_double_eq_tol(a.veretex[4], -1.26908, 1e-3);
  ck_assert_double_eq_tol(a.veretex[5], -0.357718, 1e-3);
  ck_assert_double_eq_tol(a.veretex[6], 0.776792, 1e-3);
  ck_assert_double_eq_tol(a.veretex[7], -0.512282, 1e-3);
  ck_assert_double_eq_tol(a.veretex[8], 1.46088, 1e-3);
  ck_assert_double_eq_tol(a.veretex[9], -1.19179, 1e-3);
  ck_assert_double_eq_tol(a.veretex[10], -0.580926, 1e-3);
  ck_assert_double_eq_tol(a.veretex[11], 1.11452, 1e-3);
  ck_assert_double_eq_tol(a.veretex[12], -0.776792, 1e-3);
  ck_assert_double_eq_tol(a.veretex[13], 0.512282, 1e-3);
  ck_assert_double_eq_tol(a.veretex[14], -1.46088, 1e-3);
  ck_assert_double_eq_tol(a.veretex[15], 1.19179, 1e-3);
  ck_assert_double_eq_tol(a.veretex[16], 0.580926, 1e-3);
  ck_assert_double_eq_tol(a.veretex[17], -1.11452, 1e-3);
  ck_assert_double_eq_tol(a.veretex[18], 0.845436, 1e-3);
  ck_assert_double_eq_tol(a.veretex[19], 1.33773, 1e-3);
  ck_assert_double_eq_tol(a.veretex[20], 0.704074, 1e-3);
  ck_assert_double_eq_tol(a.veretex[21], -1.12315, 1e-3);
  ck_assert_double_eq_tol(a.veretex[22], 1.26908, 1e-3);
  ck_assert_double_eq_tol(a.veretex[23], 0.357718, 1e-3);
  end(&a);
}
END_TEST

START_TEST(rotate_test2) {
  obj a;
  start(&a, "cube.obj");
  double rotate = -1;
  rotate_x(&a, rotate);
  rotate_y(&a, rotate);
  rotate_z(&a, rotate);
  ck_assert_double_eq_tol(a.veretex[0], -1.00772, 1e-3);
  ck_assert_double_eq_tol(a.veretex[1], -0.987974, 1e-3);
  ck_assert_double_eq_tol(a.veretex[2], 1.00419, 1e-3);
  ck_assert_double_eq_tol(a.veretex[3], -0.0828702, 1e-3);
  ck_assert_double_eq_tol(a.veretex[4], 0.68647, 1e-3);
  ck_assert_double_eq_tol(a.veretex[5], 1.58805, 1e-3);
  ck_assert_double_eq_tol(a.veretex[6], -0.666723, 1e-3);
  ck_assert_double_eq_tol(a.veretex[7], 1.59577, 1e-3);
  ck_assert_double_eq_tol(a.veretex[8], -0.0948957, 1e-3);
  ck_assert_double_eq_tol(a.veretex[9], -1.59157, 1e-3);
  ck_assert_double_eq_tol(a.veretex[10], -0.078677, 1e-3);
  ck_assert_double_eq_tol(a.veretex[11], -0.678749, 1e-3);
  ck_assert_double_eq_tol(a.veretex[12], 0.666723, 1e-3);
  ck_assert_double_eq_tol(a.veretex[13], -1.59577, 1e-3);
  ck_assert_double_eq_tol(a.veretex[14], 0.0948957, 1e-3);
  ck_assert_double_eq_tol(a.veretex[15], 1.59157, 1e-3);
  ck_assert_double_eq_tol(a.veretex[16], 0.078677, 1e-3);
  ck_assert_double_eq_tol(a.veretex[17], 0.678749, 1e-3);
  ck_assert_double_eq_tol(a.veretex[18], 1.00772, 1e-3);
  ck_assert_double_eq_tol(a.veretex[19], 0.987974, 1e-3);
  ck_assert_double_eq_tol(a.veretex[20], -1.00419, 1e-3);
  ck_assert_double_eq_tol(a.veretex[21], 0.0828702, 1e-3);
  ck_assert_double_eq_tol(a.veretex[22], -0.68647, 1e-3);
  ck_assert_double_eq_tol(a.veretex[23], -1.58805, 1e-3);
  end(&a);
}
END_TEST

int main() {
  int number_failed;
  Suite *s = suite_create("3dViewer");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s);
  tcase_add_test(tc, incorrect_input);
  tcase_add_test(tc, correct_input);
  tcase_add_test(tc, read_color_file);
  tcase_add_test(tc, rescale_rescale_test);
  tcase_add_test(tc, move_test);
  tcase_add_test(tc, move_test2);
  tcase_add_test(tc, rotate_test);
  tcase_add_test(tc, rotate_test2);
  tcase_add_test(tc, axis_maxdist_test);
  tcase_add_test(tc, writing_to_file_test);
  suite_add_tcase(s, tc);
  srunner_set_log(sr, "test.log");
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}