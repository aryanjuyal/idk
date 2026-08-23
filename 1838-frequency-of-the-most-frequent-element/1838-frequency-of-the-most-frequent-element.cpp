class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long sum = 0;
        int i = 0;
        int ans = 1;

        for (int j = 0; j < nums.size(); j++) {

            sum += nums[j];

            long long cost = 1LL * nums[j] * (j - i + 1) - sum;

            while (cost > k) {
                sum -= nums[i];
                i++;

                cost = 1LL * nums[j] * (j - i + 1) - sum;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};