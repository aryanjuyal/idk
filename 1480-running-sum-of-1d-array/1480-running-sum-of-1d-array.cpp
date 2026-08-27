class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int i=0;
        int sum=0;
        while(i<n){
            sum+=nums[i];
            ans.push_back(sum);
            i++;
        }
   return ans; }
};