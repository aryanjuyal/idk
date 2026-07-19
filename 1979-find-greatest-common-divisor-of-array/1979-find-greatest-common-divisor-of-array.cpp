class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int smallest=INT_MAX;
        int largest=INT_MIN;
        while(i<n){
            if(nums[i]>largest){
                largest=nums[i];
            } if(nums[i]<smallest){
                smallest=nums[i];
            }
            i++;

        }
        int j=1;
        int ans=0;
    while(j<=smallest){
        if(smallest % j == 0 && largest % j == 0){
            ans=max(ans,j);
        }
        j++;


    }

return ans;
    }
};