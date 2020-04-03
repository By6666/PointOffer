/**
 * 题目描述
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 **/

#include <iostream>
#include <vector>

int main() { return 0; }

bool VerifySquenceOfBST(std::vector<int> sequence) {
  if (sequence.size() == 0) return true;

  int mid = sequence.back();
  int i = 0;
  while (mid > sequence[i]) ++i;

  int seg = i;

  for (int j = i; j < sequence.size() - 1; ++j) {
    if (mid < sequence[i]) return false;
  }

  return VerifySquenceOfBST(
             std::vector<int>(sequence.begin(), sequence.begin() + seg)) &&
         VerifySquenceOfBST(
             std::vector<int>(sequence.begin() + seg, sequence.end() - 1));
}