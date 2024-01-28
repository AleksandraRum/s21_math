#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result;
  if ((y == 0 && x != S21_NAN) || x == POS_INF || x == NEG_INF) {
    result = -S21_NAN;
  } else if (x == S21_NAN || y == S21_NAN) {
    result = S21_NAN;
  } else if (y == POS_INF || y == NEG_INF) {
    result = x;
  } else {
    long long int mod = x / y;
    result = (long double)x - mod * (long double)y;
  }
  return result;
}
