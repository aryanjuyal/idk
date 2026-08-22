class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<vector<char>> bucket(s.size() + 1);

        for (auto [ch, count] : freq) {
            bucket[count].push_back(ch);
        }
        string ans;

        for (int i = s.size(); i >= 1; i--) {
            for (char ch : bucket[i]) {
                ans += string(i, ch);
            }
        }

        return ans;
    }
};