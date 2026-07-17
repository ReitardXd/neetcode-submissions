
class Solution {
public:
    int findMin(vector<int> &nums) {
        int result = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }
            
            int m = left + (right - left) / 2;
            result = min(result, nums[m]);
            
            if (nums[m] >= nums[left]) {
                left = m + 1;
            } else {
                right = m - 1;
            }
        }
        
        return result;
    }
};

