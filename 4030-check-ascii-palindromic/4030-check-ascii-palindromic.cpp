class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();
        string ans;
        int i = 0;
        while (i < n) {
            int x = s[i];
            for (int j = 7; j >= 0; j--) {
                ans += ((x >> j) & 1) + '0';
            }

            i++;
        }

        int k = 0;
        int l = ans.size() - 1;

        while (k < l) {
            if (ans[k] == ans[l]) {
                k++;
                l--;
            } else {
                return false;
            }
        }

        return true;
    }
};