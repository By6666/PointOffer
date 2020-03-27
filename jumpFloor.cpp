/**
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
**/

/**
 * 本质与斐波那契数列相同
 * **/

#include <iostream>
#include <vector>

int jumpFloor(int number);

int main() {
  while (1) {
    std::cout << "Please input num: ";
    int num = 0;
    std::cin >> num;
    std::cout << jumpFloor(num) << std::endl;
  }

  return 0;
}

int jumpFloor(int number) {
  if (number == 1) return 1;
  if (number == 2) return 2;

  return jumpFloor(number - 1) + jumpFloor(number - 2);
}
