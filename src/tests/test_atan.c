#include "test.h"

START_TEST(test_s21_math_atan_usual) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.1), atan(0.1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1000.0), atan(1000.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1000.0), atan(-1000.0), 1e-6);
}
END_TEST

Suite *test_atan() {
  Suite *s = suite_create("\033[45m-=S21_ATAN_C=-\033[0m");
  ;
  TCase *tc_atan_usual;

  tc_atan_usual = tcase_create("s21_atan_usual");
  tcase_add_test(tc_atan_usual, test_s21_math_atan_usual);

  suite_add_tcase(s, tc_atan_usual);

  return s;
}