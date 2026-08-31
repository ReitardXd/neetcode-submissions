class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> result = {{}};
       int prev=-1;
       int n = nums.size();
       for(int i =0;i<n;i++) { 
        int start =0;
        if (i>0 && nums[i]==nums[i-1])  { 
            start =prev;
        }
     prev = result.size(); 
     for (int j = start;j<prev;j++){ 
        vector<int> subset = result[j];
        subset.push_back(nums[i]);
        result.push_back(subset);
     }
       } return result;
    }
};
