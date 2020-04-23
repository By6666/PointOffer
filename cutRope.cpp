/**
题目描述
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

#include <algorithm>
#include <iostream>
#include <vector>

int cutRope(int number);

int main() {
  while (true) {
    std::cout << "Please input number: ";
    int num = 0;
    std::cin >> num;
    std::cout << "max length = " << cutRope(num) << std::endl;
  }

  return 0;
}

int cutRope(int number) {
  if (number < 2) return 0;

  std::vector<int> stg(number + 1, -1);  // stg[i]代表i的最大乘积
  stg[1] = 1;
  for (int i = 2; i <= number; ++i) {
    for (int j = 1; j < i; ++j) {
      stg[i] = std::max(stg[i], std::max(j * (i - j), j * stg[i - j]));
    }
  }
  return stg[number];
}
