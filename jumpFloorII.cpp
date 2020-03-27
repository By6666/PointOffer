/**
 题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
**/

/**
 * f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(1)
 * f(n-1) = f(n-2) + f(n-3) + ... + f(1)
 * 联立两式得:  f(n) = 2 * f(n-1) 
 * **/

#include <algorithm>
#include <iostream>

int jumpFloorII(int number);

int main() {
  while (1) {
    std::cout << "Please input num: ";
    int num = 0;
    std::cin >> num;
    std::cout << jumpFloorII(num) << std::endl;
  }

  return 0;
}

int jumpFloorII(int number) { return pow(2, number - 1); }
