class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        int ans = 0;
        vector<int> lis(n,1);
        vector<int> cnt(n,1);

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    if(lis[j] >= lis[i]){
                        lis[i] = 1 + lis[j];
                        cnt[i] = cnt[j];
                    }
                    else if(lis[i] == 1 + lis[j]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen,lis[i]);
        }

        for(int i = 0;i<n;i++){
            if(lis[i] == maxLen){
                ans+=cnt[i];
            }
        }

        return ans;
    }
};

// 1 3 5 4 7 7

// 1 2 3 3 4 4
// 1 1 1 1 2 2