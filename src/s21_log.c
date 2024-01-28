
#include "s21_math.h"
long double s21_log(double x) {
  long double result = 0;
  long double prev = 0;
  int exp_pow = 0;
  if (x < 0) {
    result = S21_NAN;
  } else if (x == 0) {
    result = NEG_INF;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else {
    while (x >= S21_EXP) {
      x /= S21_EXP;
      exp_pow++;
    }
    for (int i = 0; i < 150; i++) {
      prev = result;
      result = prev + 2 * (x - s21_exp(prev)) / (x + s21_exp(prev));
    }
    result += exp_pow;
  }
  return result;
}