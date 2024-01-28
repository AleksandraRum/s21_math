#include "s21_math.h"

long double s21_sin(double x) {
  long double res = 0;
  int n = 0;
  if (!isNormal(x))
    res = S21_NAN;
  else if (s21_fabs(x) > 2 * S21_PI) {
    x = s21_fmod(x, 2 * S21_PI);
  }
  while (s21_fabs((s21_pow(x, 2 * n - 1) / s21_factorial(n))) > S21_EPS) {
    res += (s21_pow(-1, n) * s21_pow(x, 2 * n + 1)) / s21_factorial(2 * n + 1);
    n += 1;
  }
  return res;
}

long double s21_factorial(double x) {
  long double res = 0;
  if (x < 0) res = 0;
  if (x == 0)
    res = 1;
  else
    res = x * s21_factorial(x - 1);
  return res;
}
