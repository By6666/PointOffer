/**
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
**/

#include <iostream>
#include <vector>

int Fibonacci(int n);

int main() {
  std::cout << Fibonacci(6) << std::endl;
  return 0;
}

int Fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  int curr = 0, last = 1, last_last = 0;

  for (int i = 2; i <= n; ++i) {
    curr = last + last_last;
    last_last = last;
    last = curr;
  }
  return curr;
}