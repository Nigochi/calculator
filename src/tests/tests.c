#define _GNU_SOURCE
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../calc_functions/s21_smart_calc.h"

START_TEST(s21_calculate_test_1) {
  char *src = "2 + 2";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 4, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_2) {
  char *src = "2 - 2";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_3) {
  char *src =
      "cos(4) * (8 * 4 - (56 + 7 * sin(85 / 10) / (-6 * (+1 - 2)-1)-1)-1)";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 16.41814, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_4) {
  char *src = "tan(8)-atan(sqrt(5))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, -7.94997, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_5) {
  char *src = "-ln(log(78))-(-tan(45))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0.98209, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_6) {
  char *src = "-ln(log(78))-(-tan(45)))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_7) {
  char *src = "-ln(log(7.8))-(-tan(45)))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_8) {
  char *src = "-ln(log(7.8.))-(-tan(45)))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_9) {
  char *src = "+ 5 - 4 mod 5";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 1, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_10) {
  char *src = "2^3 + 4 * acos(0.123) - asin(0)\0";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 13.78994, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_11) {
  char *src = "0-+7\0";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_12) {
  char *src = "-ln(jjjlog(7.8.))-(-tan(45)))";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.000001);
}
END_TEST;

START_TEST(s21_calculate_test_13) {
  char *src = "-tan(45)*tan(45)";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, -2.62367, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_14) {
  char *src = "-3+7-";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.00001);
}
END_TEST;

START_TEST(s21_calculate_test_15) {
  char *src = "8(7)";
  double result = 0;
  s21_start_calc(src, &result);
  ck_assert_double_eq_tol(result, 0, 0.00001);
}
END_TEST;

Suite *s21_string_suite(void) {
  Suite *suite;
  suite = suite_create("s21_smart_calc");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, s21_calculate_test_1);
  tcase_add_test(tcase_core, s21_calculate_test_2);
  tcase_add_test(tcase_core, s21_calculate_test_3);
  tcase_add_test(tcase_core, s21_calculate_test_4);
  tcase_add_test(tcase_core, s21_calculate_test_5);
  tcase_add_test(tcase_core, s21_calculate_test_6);
  tcase_add_test(tcase_core, s21_calculate_test_7);
  tcase_add_test(tcase_core, s21_calculate_test_8);
  tcase_add_test(tcase_core, s21_calculate_test_9);
  tcase_add_test(tcase_core, s21_calculate_test_10);
  tcase_add_test(tcase_core, s21_calculate_test_11);
  tcase_add_test(tcase_core, s21_calculate_test_12);
  tcase_add_test(tcase_core, s21_calculate_test_13);
  tcase_add_test(tcase_core, s21_calculate_test_14);
  tcase_add_test(tcase_core, s21_calculate_test_15);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
