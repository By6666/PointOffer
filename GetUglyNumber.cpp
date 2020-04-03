/**
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
**/

#include <iostream>
#include <vector>

int GetUglyNumber_Solution(int index);

int main() {
  int input = 0;
  while (1) {
    std::cout << "Please input index:";
    std::cin >> input;

    std::cout << "Result = " << GetUglyNumber_Solution(input) << std::endl;
  }
  return 0;
}

int GetUglyNumber_Solution(int index) {
  if (index < 1) return 0;
  if (index == 1) return 1;

  std::vector<int> res_stg{1};
  int p2 = 0, p3 = 0, p5 = 0;

  while (res_stg.size() < index) {
    res_stg.push_back(
        std::min(res_stg[p2] * 2, std::min(res_stg[p3] * 3, res_stg[p5] * 5)));

    if (res_stg.back() == res_stg[p2] * 2) ++p2;
    if (res_stg.back() == res_stg[p3] * 3) ++p3;
    if (res_stg.back() == res_stg[p5] * 5) ++p5;
  }

  return res_stg[index - 1];
}