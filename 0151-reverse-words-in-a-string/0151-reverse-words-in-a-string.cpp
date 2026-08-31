class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int write = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }

            if (i >= n)
                break;
                if (write > 0) {
                s[write++] = ' ';
            }

      
            while (i < n && s[i] != ' ') {
                s[write++] = s[i++];
            }
        }


        s.resize(write);

        reverse(s.begin(), s.end());
         int start = 0;

        for (int j = 0; j <= s.size(); j++) {
            if (j == s.size() || s[j] == ' ') {
                reverse(s.begin() + start, s.begin() + j);
                start = j + 1;
            }
        }

        return s;
    }
};