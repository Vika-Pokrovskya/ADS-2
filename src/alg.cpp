// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 0) {
    value = 1;
  } else {
    double k = value;
    for (int i = 1; i < n; i++) {
      value = value * k;
    }
  }
  return value;
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  for (int i = 1; i <= n; i++) {
    result = result * i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  x = (pown(x, n)) / (fact(n));
  return x;
}

double expn(double x, uint16_t count) {
  double n = 0;
  double e = 0;
  for (int i = 0; i <= count; i++) {
    n = (calcItem(x, (count - i)));
    e = n + e;
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  double sinend = 0;
  int count2 = count;
  for (int i = 1; i <= count; i++) {
    double k = pown(-1, count2 - 1);
    sin = k * calcItem(x, ((2 * count2) - 1));
    sinend = sinend + sin;
    count2 -= 1;
  }
  return sinend;
}

double cosn(double x, uint16_t count) {
  double cos = 0;
  double cosend = 0;
  int count2 = count;
  for (int i = 1; i <= count; i++) {
    int k = (int)pown(-1, count2 - 1);
    cos = k * calcItem(x, ((2 * count2) - 2));
    cosend = cosend + cos;
    count2 -= 1;
  }

  return cosend;
}
