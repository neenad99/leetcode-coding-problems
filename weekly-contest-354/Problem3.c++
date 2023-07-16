// 2780. Minimum Index of a Valid Split

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        int dominantNum = -1,dominantFreq = 0;
        
        for(int i = 0;i < n;i++){
            m[nums[i]]++;    
            if(m[nums[i]] * 2 > n)
                dominantNum = nums[i];
        }
        
        
        for(int i = 0;i < n;i++){
            if(nums[i] == dominantNum)
                dominantFreq++;
            if(dominantFreq * 2 > i+1 && (m[dominantNum] - dominantFreq) * 2 > (n-i-1))
                return i;
        }
        
        return -1;
    }
};