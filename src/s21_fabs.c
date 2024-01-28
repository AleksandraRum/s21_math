#include "s21_math.h"

long double s21_fabs(double x) {
  long double result = (long double)x;

  if (x != x) {
    result = S21_NAN;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else if (x == NEG_INF) {
    result = NEG_INF;
  } else if (x < 0) {
    result = -x;
  } else if (x >= 0) {
    result = x;
  }
  return result;
}
