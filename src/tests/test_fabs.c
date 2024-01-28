#include "test.h"

START_TEST(test_s21_math_fabs) {
  ck_assert_double_eq_tol(s21_fabs(5.893), fabs(5.893), 1e-6);
  ck_assert_double_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_double_eq_tol(s21_fabs(-0.00004), fabs(-0.00004), 1e-6);
  ck_assert_double_eq_tol(s21_fabs(DBL_MAX), fabs(DBL_MAX), 1e-6);
  ck_assert_double_eq_tol(s21_fabs(DBL_MIN), fabs(DBL_MIN), 1e-6);

  ck_assert_double_nan(s21_fabs(NAN));
  ck_assert_double_infinite(s21_fabs(INFINITY));
  ck_assert_double_infinite(s21_fabs(-INFINITY));
}
END_TEST

Suite *test_fabs() {
  Suite *s = suite_create("\033[45m-=S21_FABS_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_fabs");
  tcase_add_test(tc, test_s21_math_fabs);
  suite_add_tcase(s, tc);

  return s;
}
