/**
 * 题目描述
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变.
 **/

#include <iostream>
#include <vector>

void reOrderArray(std::vector<int> &array);

int main() {
  std::vector<int> test_data{1, 2, 3, 4, 5, 6, 7, 8, 9};

  return 0;
}

void reOrderArray(std::vector<int> &array) {
  if (array.size() < 2) return;

  std::vector<int> ji_data;
  std::vector<int> ou_data;

  for (auto &elem : array) {
    if (elem & 1)
      ji_data.push_back(elem);
    else
      ou_data.push_back(elem);
  }
  array.clear();

  array.insert(array.begin(), ji_data.begin(), ji_data.end());
  array.insert(array.end(), ou_data.begin(), ou_data.end());
}