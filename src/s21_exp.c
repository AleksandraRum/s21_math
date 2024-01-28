#include "s21_math.h"

long double calc_exp(double x) {
  long double add_value = 1;
  long double i = 1;
  long double result = 1;
  while (s21_fabs(add_value) > S21_EPS) {
    add_value *= x / i;
    result += add_value;
    if (result >= POS_INF) {
      result = POS_INF;
      break;
    }
    i++;
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  if (x != x) {
    result = S21_NAN;
  } else if (x >= POS_INF) {
    result = POS_INF;
  } else if (x <= NEG_INF) {
    result = 0;
  } else if (x >= 0) {
    result = calc_exp(x);
  } else if (x < 0) {
    x = -x;
    result = calc_exp(x);
    result = 1 / result;
  }

  return result;
}
