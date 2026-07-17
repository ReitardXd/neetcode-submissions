class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) return mid;
            
            // Left part is sorted
            if (nums[i] <= nums[mid]) {
                if (nums[i] <= target && target < nums[mid]) {
                    j = mid - 1;  // Target is in the left part
                } else {
                    i = mid + 1;  // Target is in the right part
                }
            } 
            // Right part is sorted
            else {
                if (nums[mid] < target && target <= nums[j]) {
                    i = mid + 1;  // Target is in the right part
                } else {
                    j = mid - 1;  // Target is in the left part
                }
            }
        }
        
        return -1;  // Target not found
    }
};
