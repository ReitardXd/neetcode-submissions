class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> nums3; 
       for (int x: nums1) {
        nums3.push_back(x); }
    for (int x :nums2){
        nums3.push_back(x);}
        
        sort(nums3.begin(),nums3.end());
        int n = nums3.size();
    
if (n % 2 == 1) {
    return nums3[n / 2];
} else {
    return (nums3[n / 2 - 1] + nums3[n / 2]) / 2.0;
}
    }

         }; 