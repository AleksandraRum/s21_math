#include "test.h"

START_TEST(test_s21_math_sqrt) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(S21_PI / 4), sqrt(S21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(3 * S21_PI / 4), sqrt(3 * S21_PI / 4),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(5 * S21_PI / 6), sqrt(5 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(S21_PI), sqrt(S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(11 * S21_PI / 6), sqrt(11 * S21_PI / 6),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2 * S21_PI), sqrt(2 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(15 * S21_PI), sqrt(15 * S21_PI), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2), sqrt(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.123456), sqrt(0.123456), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-0.123456));
  ck_assert_ldouble_eq_tol(s21_sqrt(12345), sqrt(12345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(10000 * S21_PI), sqrt(10000 * S21_PI),
                           1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-10000 * S21_PI));
  ck_assert_ldouble_eq_tol(s21_sqrt(126.8647465), sqrt(126.8647465), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(75846.8647465), sqrt(75846.8647465), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(NEG_INF));
}
END_TEST

Suite *test_sqrt() {
  Suite *s = suite_create("\033[45m-=S21_SQRT_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_sqrt");
  tcase_add_test(tc, test_s21_math_sqrt);
  suite_add_tcase(s, tc);

  return s;
}