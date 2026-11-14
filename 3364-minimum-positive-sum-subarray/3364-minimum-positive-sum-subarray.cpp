class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        
        vector<int> window_sums;
        int curr_sum = 0;
        for (int i = 0; i < l; ++i) {
            curr_sum += nums[i];
        }
        window_sums.push_back(curr_sum);
        if (curr_sum > 0) {
            min_sum = min(min_sum, curr_sum);
        }
        
        for (int i = 1; i <= n - l; ++i) {
            curr_sum = curr_sum - nums[i - 1] + nums[i + l - 1];
            window_sums.push_back(curr_sum);
            if (curr_sum > 0) {
                min_sum = min(min_sum, curr_sum);
            }
        }
        
        for (int size = l + 1; size <= r; ++size) {
            for (int i = 0; i <= n - size; ++i) {
                window_sums[i] += nums[i + size - 1];
                if (window_sums[i] > 0) {
                    min_sum = min(min_sum, window_sums[i]);
                }
            }
        }
        
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};