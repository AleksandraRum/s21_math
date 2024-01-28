#include "test.h"

START_TEST(test_s21_math_exp) {
  ck_assert_double_eq_tol(s21_exp(5.893), exp(5.893), 1e-6);
  ck_assert_double_eq_tol(s21_exp(0.0), exp(0.0), 1e-6);
  ck_assert_double_eq_tol(s21_exp(-0.00004), exp(-0.00004), 1e-6);
  ck_assert_double_eq_tol(s21_exp(99), exp(99), 1e-6);
  ck_assert_double_eq_tol(s21_exp(-1.434e18), exp(-1.434e18), 1e-6);
  ck_assert_double_eq_tol(s21_exp(.45e-6), exp(.45e-6), 1e-6);
  ck_assert_double_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 1e-6);

  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_infinite(s21_exp(INFINITY));
  ck_assert_double_infinite(s21_exp(1e18));
}
END_TEST

Suite *test_exp() {
  Suite *s = suite_create("\033[45m-=S21_EXP_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_exp");
  tcase_add_test(tc, test_s21_math_exp);
  suite_add_tcase(s, tc);

  return s;
}
