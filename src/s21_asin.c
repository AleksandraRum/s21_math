
#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (x < -1 || x > 1) {
    result = S21_NAN;
  } else if (x > -1 && x < 1) {
    result = s21_atan(x / (s21_pow(1 - (x * x), 0.5)));
  } else if (x == -1) {
    result = -S21_PI / 2;
  } else if (x == 0) {
    result = 0;
  } else if (x == 1) {
    result = S21_PI / 2;
  }
  return result;
}