
#include "test.h"

START_TEST(test_s21_math_ceil_usual) {
  double testValue1 = -5.7;
  double testValue2 = -0.1;
  double testValue3 = 12.4;
  ck_assert_ldouble_eq_tol(s21_ceil(testValue1), ceil(testValue1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue2), ceil(testValue2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(testValue3), ceil(testValue3), 1e-6);
  for (double i = -1.01; i <= 1.01; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_ceil(i), ceil(i), 1e-6);
  }
}
END_TEST

START_TEST(test_s21_math_ceil_unusual) {
  double testValue1 = POS_INF;
  double testValue2 = NEG_INF;
  double testValue3 = S21_NAN;
  ck_assert_double_infinite(s21_ceil(testValue1));
  ck_assert_double_infinite(s21_ceil(testValue2));
  ck_assert_double_nan(s21_ceil(testValue3));
}
END_TEST

Suite *test_ceil(void) {
  Suite *s = suite_create("\033[45m-=S21_CEIL_C=-\033[0m");
  ;
  TCase *tc_ceil_usual, *tc_ceil_unusual;

  tc_ceil_usual = tcase_create("s21_ceil_usual");
  tcase_add_test(tc_ceil_usual, test_s21_math_ceil_usual);
  suite_add_tcase(s, tc_ceil_usual);

  tc_ceil_unusual = tcase_create("s21_ceil_unusual");
  tcase_add_test(tc_ceil_unusual, test_s21_math_ceil_unusual);
  suite_add_tcase(s, tc_ceil_unusual);

  return s;
}