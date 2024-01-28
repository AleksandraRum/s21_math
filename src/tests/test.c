#include "test.h"

int main(void) {
  int failed = 0;
  Suite *s21_math_test[] = {test_ceil(),  test_atan(), test_asin(), test_acos(),
                            test_log(),   test_pow(),  test_sqrt(), test_tan(),
                            test_sin(),   test_cos(),  test_abs(),  test_fabs(),
                            test_floor(), test_fmod(), test_exp(),  NULL};

  for (int i = 0; s21_math_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_math_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
