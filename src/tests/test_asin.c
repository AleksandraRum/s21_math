#include "test.h"

START_TEST(test_s21_math_asin_usual) {
  ck_assert_ldouble_eq_tol(s21_asin(1.0), asin(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1.0), asin(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0), asin(0.0), 1e-6);

  ck_assert_ldouble_eq_tol(s21_asin(0.23234), asin(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.23234), asin(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.0002), asin(0.0002), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.0002), asin(-0.0002), 1e-6);
}
END_TEST

Suite *test_asin() {
  Suite *s = suite_create("\033[45m-=S21_ASIN_C=-\033[0m");
  ;
  TCase *tc_asin_usual;

  tc_asin_usual = tcase_create("s21_asin_usual");
  tcase_add_test(tc_asin_usual, test_s21_math_asin_usual);

  suite_add_tcase(s, tc_asin_usual);

  return s;
}