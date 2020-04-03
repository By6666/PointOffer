/**
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
**/

#include <iostream>
#include <string>
#include <unordered_map>

int FirstNotRepeatingChar(std::string str);

int main() {
  std::string input = "";
  while (1) {
    std::cout << "Please input string:";
    std::cin >> input;

    std::cout << "Result = " << FirstNotRepeatingChar(input) << std::endl;
  }
  return 0;
}

int FirstNotRepeatingChar(std::string str) {
  std::unordered_map<char, int> stg;
  for (auto& elem : str) {
    stg[elem]++;
  }

  for (int i = 0; i < str.length(); ++i) {
    if (stg[str[i]] == 1) return i;
  }
  return -1;
}
