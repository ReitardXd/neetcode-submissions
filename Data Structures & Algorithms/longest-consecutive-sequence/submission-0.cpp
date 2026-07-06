class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int  n =nums.size();
        int ans=0,streak=0,i=0,curr=nums[0];
        sort(nums.begin(),nums.end());
        while (i<n){
            if (curr!=nums[i]){
                curr =nums[i];
                streak=0;
            }
            while (i < n && nums[i]==curr){
                i++;
            }streak++;
            curr++;
            ans=max(ans,streak);
        
        } return ans;
    }
};
