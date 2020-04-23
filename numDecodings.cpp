/**
 * 题目描述：
一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
*/

#include <iostream>
#include <string>
#include <vector>

int numDecodings(std::string s);

int main() {
  std::string s = "12120";
  std::cout << numDecodings(s) << std::endl;
  return 0;
}

int numDecodings(std::string s) {
  if (s.length() == 0) return 0;
  if (s[0] == '0') return 0;

  std::vector<int> dp_stg(s.length() + 1);
  dp_stg[0] = 1;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] >= '1' && s[i] <= '9') {
      if (i == 0) {
        dp_stg[i + 1] = 1;
        continue;
      }
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
        dp_stg[i + 1] = dp_stg[i] + dp_stg[i - 1];
      else
        dp_stg[i + 1] = dp_stg[i - 1];
    } else if (s[i] == '0') {
      if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
        // dp_stg[i + 1] = (i - 1 == 0) ? 1 : dp_stg[i - 1];
        dp_stg[i + 1] = dp_stg[i - 1];
    }
  }
  return dp_stg.back();
}