#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  if (x == 1 || x == -1) {
    result = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);
  } else if (x > -1 && x < 1) {
    for (int i = 0; i < 500; i++) {
      result += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else {
    for (int i = 0; i < 500; i++) {
      result += (s21_pow(-1, i) * s21_pow(x, -1 - 2 * i)) / (1 + 2 * i);
    }
    result = (S21_PI * s21_pow(x * x, 0.5)) / (2 * x) - result;
  }
  return result;
}