class Solution{
    public:
    bool hasDuplicate(vector<int>& nums){
        int n; 
        n = nums.size();
        if (nums.empty()) return false;
         sort (nums.begin(),nums.end());
        for (int i = 1; i < n; i++){
            if (nums[i]==nums[i-1]) return true;
        }
         return false;
    }
};