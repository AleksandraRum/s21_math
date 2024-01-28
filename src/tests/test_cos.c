#include "test.h"

START_TEST(test_s21_math_cos) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI / 6), cos(S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(3 * S21_PI / 4), cos(3 * S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(5 * S21_PI / 6), cos(5 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI), cos(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(7 * S21_PI / 6), cos(7 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(11 * S21_PI / 6), cos(11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(15 * S21_PI), cos(15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 6), cos(-S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI / 4), cos(-S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-5 * S21_PI / 6), cos(-5 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-S21_PI), cos(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-7 * S21_PI / 6), cos(-7 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-11 * S21_PI / 6), cos(-11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-15 * S21_PI), cos(-15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(2), cos(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.123456), cos(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.123456), cos(-0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(12345), cos(12345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(10000 * S21_PI), cos(10000 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-10000 * S21_PI), cos(-10000 * S21_PI),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(126.8647465), cos(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-235.3456458), cos(-235.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(75846.8647465), cos(75846.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-92553.3456458), cos(-92553.3456458), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(NEG_INF));
}
END_TEST

Suite *test_cos() {
  Suite *s = suite_create("\033[45m-=S21_COS_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_cos");
  tcase_add_test(tc, test_s21_math_cos);
  suite_add_tcase(s, tc);

  return s;
}