#include "test.h"

START_TEST(test_s21_math_floor) {
  ck_assert_double_eq_tol(s21_floor(5.893), floor(5.893), 1e-6);
  ck_assert_double_eq_tol(s21_floor(0.0), floor(0.0), 1e-6);
  ck_assert_double_eq_tol(s21_floor(-0.00004), floor(-0.00004), 1e-6);
  ck_assert_double_eq_tol(s21_floor(1e18), floor(1e18), 1e-6);
  ck_assert_double_eq_tol(s21_floor(-1.434e18), floor(-1.434e18), 1e-6);
  ck_assert_double_eq_tol(s21_floor(.45e-6), floor(.45e-6), 1e-6);

  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_infinite(s21_floor(INFINITY));
  ck_assert_double_infinite(s21_floor(-INFINITY));
}
END_TEST

Suite *test_floor() {
  Suite *s = suite_create("\033[45m-=S21_FLOOR_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_floor");
  tcase_add_test(tc, test_s21_math_floor);
  suite_add_tcase(s, tc);

  return s;
}
