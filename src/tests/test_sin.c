#include "test.h"

START_TEST(test_s21_math_sin) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 6), sin(S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI / 4), sin(S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(3 * S21_PI / 4), sin(3 * S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(5 * S21_PI / 6), sin(5 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(S21_PI), sin(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(7 * S21_PI / 6), sin(7 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(11 * S21_PI / 6), sin(11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2 * S21_PI), sin(2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(15 * S21_PI), sin(15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 6), sin(-S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI / 4), sin(-S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-3 * S21_PI / 4), sin(-3 * S21_PI / 4),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-5 * S21_PI / 6), sin(-5 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-7 * S21_PI / 6), sin(-7 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-11 * S21_PI / 6), sin(-11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-2 * S21_PI), sin(-2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-15 * S21_PI), sin(-15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2), sin(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.123456), sin(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.123456), sin(-0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(12345), sin(12345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(10000 * S21_PI), sin(10000 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-10000 * S21_PI), sin(-10000 * S21_PI),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(126.8647465), sin(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-235.3456458), sin(-235.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(75846.8647465), sin(75846.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-92553.3456458), sin(-92553.3456458), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(NEG_INF));
}
END_TEST

Suite *test_sin() {
  Suite *s = suite_create("\033[45m-=S21_SIN_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_sin");
  tcase_add_test(tc, test_s21_math_sin);
  suite_add_tcase(s, tc);

  return s;
}
