#include "test.h"

START_TEST(test_s21_math_abs) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(-4), abs(-4));
  ck_assert_int_eq(s21_abs(9), abs(9));
  ck_assert_int_eq(s21_abs(INT32_MAX), abs(INT32_MAX));
  ck_assert_int_eq(s21_abs(INT32_MIN), abs(INT32_MIN));
}
END_TEST

Suite *test_abs() {
  Suite *s = suite_create("\033[45m-=S21_ABS_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_abs");
  tcase_add_test(tc, test_s21_math_abs);
  suite_add_tcase(s, tc);

  return s;
}
