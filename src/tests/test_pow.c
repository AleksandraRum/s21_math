#include "test.h"

START_TEST(test_s21_math_pow) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 0.5), pow(2, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(4.678, -5), pow(4.678, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.5), pow(0, 0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), 1e-6);
  ck_assert_ldouble_nan(s21_pow(0, -S21_NAN));
  ck_assert_ldouble_nan(s21_pow(0, 0));
  ck_assert_ldouble_eq_tol(s21_pow(8.654, 0.7), pow(8.654, 0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8.654, -0.7), pow(8.654, -0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.978464, -5), pow(0.978464, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.756, -7), pow(0.756, -7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 567.789), pow(1, 567.789), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -0.789), pow(1, -0.789), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(675, 0), pow(675, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.5, POS_INF), pow(0.5, POS_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(44.44, NEG_INF), pow(44.44, NEG_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(POS_INF, 0), pow(POS_INF, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(NEG_INF, 0), pow(NEG_INF, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(POS_INF, -57), pow(POS_INF, -57), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(NEG_INF, -57), pow(NEG_INF, -57), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(POS_INF, NEG_INF), pow(POS_INF, NEG_INF),
                           1e-6);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

Suite *test_pow() {
  Suite *s = suite_create("\033[45m-=S21_POW_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_pow");
  tcase_add_test(tc, test_s21_math_pow);
  suite_add_tcase(s, tc);

  return s;
}