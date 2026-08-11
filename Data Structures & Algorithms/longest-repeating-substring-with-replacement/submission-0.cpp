class Solution {
public: 
    int characterReplacement(string s, int k) {
        int n  = s.size();
    int res= 0;
    unordered_set<char> charset(s.begin(),s.end());

       for (char c: charset ) {

        int count = 0;
        int  l = 0;
         for (int  r = 0; r < n;r++)
         {
             if (s[r] == c ) {
                 count ++;
             } 
            while (r-l+1-count > k){
                if (s[l] == c ){
                     count -- ;
                } l++;
              } 
              res =  max(res,r-l+1);
         } 

       } return res;
    }
};
