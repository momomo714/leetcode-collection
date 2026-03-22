#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> lastPos; // 字符 -> 最后出现的位置
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); ++right) {
            char c = s[right];
            // 如果字符已存在且其位置在窗口内，移动左指针
            if (lastPos.find(c) != lastPos.end() && lastPos[c] >= left) {
                left = lastPos[c] + 1;
            }
            lastPos[c] = right; // 更新当前字符的位置
            maxLen = std::max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};