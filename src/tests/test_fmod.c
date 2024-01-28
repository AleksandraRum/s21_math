#include "test.h"

START_TEST(test_s21_math_fmod) {
  long double int_values[] = {NAN, INFINITY, -INFINITY, 0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (int_values[i] != 0) {
        ck_assert_double_nan(s21_fmod(int_values[i], int_values[j]));
      }
    }
  }
  ck_assert_double_nan(s21_fmod(4234.94, NAN));
  ck_assert_double_nan(s21_fmod(NAN, 2342.324));
  ck_assert_double_nan(s21_fmod(INFINITY, -5849.848));
  ck_assert_double_nan(s21_fmod(-34.342, 0));

  ck_assert_double_eq_tol(s21_fmod(5.893, INFINITY), fmod(5.893, INFINITY),
                          1e-6);

  long double cv[] = {1.2e-6, -4.7e-6, 4.38394, 23.8e7, -4.8e7, 8.32, -9.003};
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      ck_assert_double_eq_tol(s21_fmod(cv[i], cv[j]), fmod(cv[i], cv[j]), 1e-6);
    }
  }
}
END_TEST

Suite *test_fmod() {
  Suite *s = suite_create("\033[45m-=S21_FMOD_C=-\033[0m");
  TCase *tc;

  tc = tcase_create("s21_fmod");
  tcase_add_test(tc, test_s21_math_fmod);
  suite_add_tcase(s, tc);

  return s;
}
