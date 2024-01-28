#include "s21_math.h"

long double s21_floor(double x) {
  long double result = (long long int)x;
  if (x != x) {
    result = S21_NAN;
  } else if (x == POS_INF) {
    result = POS_INF;
  } else if (x == NEG_INF) {
    result = NEG_INF;
  } else if (x == 0) {
    result = 0;
  } else if (x != result && x < 0) {
    result -= 1;
  }
  return result;
}