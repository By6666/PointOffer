/**
 * 希尔排序法
 **/

#include <iostream>
#include <vector>

void ShellSort(std::vector<int> data);

int main() {
  ShellSort(std::vector<int>{5, 6, 7, 1, 2, 4, 9, 3});
  return 0;
}

void ShellSort(std::vector<int> data) {
  int dev = 2;
  int jump = data.size() / dev;
  while (jump) {
    for (int i = jump; i < data.size(); ++i) {
      int pre_index = i - jump;
      int temp = data[i];
      while (pre_index >= 0 && temp < data[pre_index]) {
        data[pre_index + jump] = data[pre_index];
        pre_index -= jump;
      }
      data[pre_index + jump] = temp;
    }

    jump /= dev;
  }

  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
}