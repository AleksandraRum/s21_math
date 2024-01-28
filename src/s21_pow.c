
#include "s21_math.h"
long double s21_pow(double base, double exp) {
  long double res;
  long double copy_base = base;
  if (((base == -1) || (base == 1)) && (isNEG_INF(exp) || isPOS_INF(exp)))
    res = 1.;
  else if ((isPOS_INF(exp) && (s21_fabs(base) > 1)) ||
           (isNEG_INF(exp) && (s21_fabs(base) < 1)))
    res = POS_INF;
  else if ((isPOS_INF(exp) && (s21_fabs(base) < 1)) ||
           (isNEG_INF(exp) && (s21_fabs(base) > 1)))
    res = 0.;
  else if ((base == 1) && isNAN(exp))
    res = 1.;
  else if ((isPOS_INF(base) || isNEG_INF(base)) && (exp > 0))
    res = POS_INF;
  else if (isPOS_INF(base) && (exp < 0))
    res = 0;
  else if ((base >= 0) && isNormal(base) && isNormal(exp)) {
    res = s21_exp(exp * s21_log(copy_base));
  } else if ((((base == 0) || !isNormal(base)) && (exp == 0)))
    res = 1.;
  else {
    copy_base = -copy_base;
    if (s21_fmod(exp, 2.0) != 0)
      res = -(s21_exp(exp * s21_log(copy_base)));
    else
      res = s21_exp(exp * s21_log(copy_base));
  }

  return res;
}
