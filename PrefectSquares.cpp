/**
 * 题目描述：
 * 给出一个正整数你寻找最少的完全平方数，使他们的和为n
 * 完全平方数：1,4,9,16...
 * 12 = 4 + 4 + 4
 * 13 = 4 + 9
 */

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> PrefectSquare(int number);

int main() {
  while (true) {
    std::cout << "Please input number: ";
    int num = 0;
    std::cin >> num;

    std::vector<int> list = PrefectSquare(num);

    for (auto& elem : list) {
      std::cout << elem << "  ";
    }
    std::cout << std::endl;
  }

  return 0;
}

std::vector<int> PrefectSquare(int number) {
  if (number < 0) return std::vector<int>();

  if (number == 1) return std::vector<int>{1};

  int base = static_cast<int>(std::sqrt(number));

  std::vector<int> temp = PrefectSquare(number - base * base);
  temp.push_back(base * base);
  return temp;
}
