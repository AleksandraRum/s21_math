#include "s21_math.h"

int s21_abs(int x) {
  int result;
  // if (x == (int)S21_NAN) {
  //     result = (int)S21_NAN;
  // } else if (x == S21_INT_POSINF) {
  //     result = S21_INT_POSINF;
  // } else if (x == S21_INT_NEGINF) {
  //     result = -S21_INT_NEGINF;
  // } else if (x < 0) {
  //     result = -x;
  // } else if (x >= 0) {
  //     result = x;s
  // }
  if (x < 0) {
    result = -x;
  } else {
    result = x;
  }
  return result;
}