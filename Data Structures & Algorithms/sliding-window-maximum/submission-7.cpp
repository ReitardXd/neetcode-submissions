class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> heap;
        vector<int> answer; 
        int n = nums.size();
        for(int i = 0;i<n;i++){
            heap.push({nums[i],i});
            if (i>=k-1) {
                while(heap.top().second<=i-k){
                    heap.pop();
                } 
                answer.push_back(heap.top().first);
            }
        } 
        return answer;
    }
};
