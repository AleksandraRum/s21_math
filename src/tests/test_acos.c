#include "test.h"

START_TEST(test_s21_math_acos_usual) {
  ck_assert_ldouble_eq_tol(s21_acos(1.0), acos(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1.0), acos(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.0), acos(0.0), 1e-6);

  ck_assert_ldouble_eq_tol(s21_acos(0.23234), acos(0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.23234), acos(-0.23234), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.0002), acos(0.0002), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.0002), acos(-0.0002), 1e-6);
}
END_TEST

Suite *test_acos() {
  Suite *s = suite_create("\033[45m-=S21_ACOS_C=-\033[0m");
  TCase *tc_acos_usual;

  tc_acos_usual = tcase_create("s21_acos_usual");
  tcase_add_test(tc_acos_usual, test_s21_math_acos_usual);

  suite_add_tcase(s, tc_acos_usual);

  return s;
}