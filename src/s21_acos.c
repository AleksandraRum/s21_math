
#include "s21_math.h"
long double s21_acos(double x) {
  long double result = 0;
  if (x < -1 || x > 1) {
    result = S21_NAN;
  } else if (x > 0 && x < 1) {
    result = s21_atan((s21_pow(1 - (x * x), 0.5)) / x);
  } else if (x > -1 && x < 0) {
    result = S21_PI + s21_atan((s21_pow(1 - (x * x), 0.5)) / x);
  } else if (x == -1) {
    result = S21_PI;
  } else if (x == 0) {
    result = S21_PI / 2;
  } else if (x == 1) {
    result = 0;
  }
  return result;
}