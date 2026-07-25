class Solution {
public:
    int maxProduct(int n) {
        vector<int> num;

        while (n != 0) {
            int digit = n % 10;
            num.push_back(digit);
            n /= 10;
        }

        sort(num.begin(), num.end());

        int sz = num.size();
        return num[sz - 1] * num[sz - 2];
    }
};