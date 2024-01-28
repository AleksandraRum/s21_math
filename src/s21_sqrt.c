#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res;
  long double R = x;
  long double L = 0;
  if (x == 0)
    res = 0;
  else if (isPOS_INF(x))
    res = POS_INF;
  else if ((x < 0) || isNAN(x) || isNEG_INF(x))
    res = S21_NAN;
  else {
    while ((L - R) != 0) {
      L = R;
      R = (L + (x / L)) / 2;
    }
    res = R;
  }
  return res;
}
