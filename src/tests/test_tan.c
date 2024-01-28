#include "test.h"

START_TEST(test_s21_math_tan) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI / 6), tan(S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(3 * S21_PI / 4), tan(3 * S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(5 * S21_PI / 6), tan(5 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(S21_PI), tan(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(7 * S21_PI / 6), tan(7 * S21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(11 * S21_PI / 6), tan(11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2 * S21_PI), tan(2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(15 * S21_PI), tan(15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI / 4), tan(-S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-3 * S21_PI / 4), tan(-3 * S21_PI / 4),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-S21_PI), tan(-S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-2 * S21_PI), tan(-2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-15 * S21_PI), tan(-15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(2), tan(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.123456), tan(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.123456), tan(-0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(12345), tan(12345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(10000 * S21_PI), tan(10000 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-10000 * S21_PI), tan(-10000 * S21_PI),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(126.8647465), tan(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-235.3456458), tan(-235.3456458), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(75846.8647465), tan(75846.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-92553.3456458), tan(-92553.3456458), 1e-6);
  ck_assert_ldouble_nan(s21_tan(POS_INF));
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
}
END_TEST

Suite *test_tan() {
  Suite *s = suite_create("\033[45m-=S21_TAN_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_tan");
  tcase_add_test(tc, test_s21_math_tan);
  suite_add_tcase(s, tc);

  return s;
}