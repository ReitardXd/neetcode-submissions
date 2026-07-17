class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (string str : strs) {
            res += to_string(str.size()) + "#" + str;
        } return res;

    }

    vector<string> decode(string s) {

        vector <string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int size = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, size));
            i = j + size + 1;
        } return res;
    }
};
