class Solution {
public:
    string minWindow(string s, string t) {
       if (t.empty()) return ""; 

        unordered_map<char,int> ct,window;
        for (char  c : t) {
            ct[c]++;
            }
            int have = 0, need = ct.size();
            pair<int,int> res = {-1,-1};
            int reslen= INT_MAX;
            int l = 0; 


             for (int r = 0;r<s.length(); r++){
                char c = s[r];
                window[c]++;
                if (ct.count(c) && window[c] == ct[c]) {
                  have++;
                } 
                while(have==need) {
                  if((r-l+1)<reslen){
                     reslen = r-l+1;
                     res={l,r};
                  }
                  window[s[l]]--;
                  if(ct.count(s[l]) && window[s[l]] < ct[s[l]]) {
                     have--;
                  } 
                  l++;
                } 
                } 
                
   return reslen == INT_MAX ? "":s.substr(res.first,reslen);
        }
       
    };
