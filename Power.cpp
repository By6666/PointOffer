/**
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
**/

#include <iostream>

double Power(double base, int exponent);
int main() { return 0; }

double Power(double base, int exponent) {
  if (exponent == 0) return 1;
  if (exponent == 1) return base;
  if (base == 0.0) return 0.0;

  double result = 1.0;
  bool n_flag = (exponent < 0) ? true : false;
  exponent = abs(exponent);
  while (exponent) {
    if (exponent & 1) result *= base;
    base *= base;
    exponent >>= 1;
  }

  return (n_flag) ? 1 / result : result;
}