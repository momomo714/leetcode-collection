#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保 nums1 是较短的数组，减少二分范围
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;   // 左半部分元素总数

        while (left <= right) {
            int i = (left + right) / 2;   // nums1 左半部分元素个数
            int j = halfLen - i;          // nums2 左半部分元素个数

            // 边界判断：nums2 左半部分最大值 > nums1 右半部分最小值
            if (i < m && j > 0 && nums2[j - 1] > nums1[i]) {
                left = i + 1;            // i 太小，需要增大
            }
            // 边界判断：nums1 左半部分最大值 > nums2 右半部分最小值
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j]) {
                right = i - 1;           // i 太大，需要减小
            }
            else {
                // 找到正确分割点，计算左半部分最大值
                int maxLeft;
                if (i == 0) maxLeft = nums2[j - 1];
                else if (j == 0) maxLeft = nums1[i - 1];
                else maxLeft = max(nums1[i - 1], nums2[j - 1]);

                // 总长度为奇数，中位数就是左半部分最大值
                if ((m + n) % 2 == 1) return maxLeft;

                // 总长度为偶数，还需右半部分最小值
                int minRight;
                if (i == m) minRight = nums2[j];
                else if (j == n) minRight = nums1[i];
                else minRight = min(nums1[i], nums2[j]);

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0; // 不会执行到
    }
};