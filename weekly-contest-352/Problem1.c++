class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int cnt = 0;
        int ans = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(nums[i] <= threshold){
                if(cnt > 0){
                    cnt = (nums[i]%2 == nums[i-1]%2) ? 0 : cnt + 1;
                }
                if(cnt == 0){
                    cnt = nums[i]%2 == 0;
                }
            }
            else{
                cnt = 0;
            }
            ans = max(ans,cnt);
        }

        return ans;
    }
};