class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int countOne = 0;
        int minLen = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                countOne++;
            }

            while (countOne == k) {
                minLen = min(minLen, j - i + 1);

                if (s[i] == '1') {
                    countOne--;
                }

                i++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }
         string ans = "";
        countOne = 0;
        for (int i = 0; i < minLen; i++) {
            if (s[i] == '1') {
                countOne++;
            }
        }

        if (countOne == k) {
            ans = s.substr(0, minLen);
        }
                for (int j = minLen; j < n; j++) {
            if (s[j] == '1') {
                countOne++;
            }

            if (s[j - minLen] == '1') {
                countOne--;
            }

            if (countOne == k) {
                string current = s.substr(j - minLen + 1, minLen);

                if (ans.empty() || current < ans) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};