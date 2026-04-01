class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_vol = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int vol = h * (right - left);
            max_vol = max(max_vol, vol);
            // 移动较短的边
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_vol;
    }
};
