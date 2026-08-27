class Solution {
public:
    int missingNumber(vector<int>& nums) {
       unordered_set<int> ns(nums.begin(),nums.end());
       int n = nums.size();
       for(int i = 0; i<= n;i++)  { 
        if (ns.find(i)==ns.end(i)){
            return i;
        }
       } 
       return -1;
    }
};
