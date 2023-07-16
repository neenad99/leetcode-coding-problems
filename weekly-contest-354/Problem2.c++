//2779. Maximum Beauty of an Array After Applying Operation


class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> m;
        int n = nums.size();
        int currSum = 0;
        int ans = 0;
        
        for(int i = 0;i < n;i++){
            int l = nums[i] - k;
            int h = nums[i] + k;
            
            m[l]++;
            m[h+1]--;
        }
        
        for(auto &j : m){
            currSum+=j.second;
            ans = max(ans,currSum);
        }
        
        return ans;
    }
};

// 4 6 1 2
// -1 0 1 2 3 4 5 6 7 8
//  1 2 2 3 3 3 2 2 1 1 

// -1 -> 1
//  0 -> 1
//  2 -> 1 
//  4 -> -1
//  4 -> 

