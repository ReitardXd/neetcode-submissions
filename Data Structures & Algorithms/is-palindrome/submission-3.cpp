class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {

            while (l < r && !isalnum((unsigned char)s[l])) {
                l++;
            }

            while (l < r && !isalnum((unsigned char)s[r])) {
                r--;
            }

            if (tolower((unsigned char)s[l]) !=
                tolower((unsigned char)s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};