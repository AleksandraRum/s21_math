#include "s21_math.h"
long double s21_cos(double x) {
  long double res = 0;
  if (!isNormal(x))
    res = S21_NAN;
  else if (s21_fabs(x) > 2 * S21_PI) {
    x = s21_fmod(x, 2 * S21_PI);
  }
  res = s21_sin(S21_PI / 2 - x);

  return res;
}