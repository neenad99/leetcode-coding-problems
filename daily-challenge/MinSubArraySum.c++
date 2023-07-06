class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int n = nums.size();
        int currSum = 0;
        int ans = INT_MAX;

        while(end < n){
            currSum+=nums[end];

            while(start <= end && currSum >= target){
                ans = min(ans,end-start+1);
                currSum-=nums[start++];
            }

            end++;
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};