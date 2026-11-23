class Solution {
public:
    int maxArea(vector<int>& heights) { 
        int n = heights.size(); 

       vector<int> h = heights; 
       int  l = 0;  
       int r = n-1;  
       int res = 0; 
       while(l  < r ) {  
             int area  = min(h[l],h[r])* (r-l); 
             res = max(area,res); 
             if (h[l] <= h[r]) { 
                l++;
             } else {  r--; 

             } 
       }  

       return res; 
    }
};
