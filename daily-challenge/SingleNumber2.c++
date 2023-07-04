class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(),res=0;
        int arr[32]={0};
        
        for(int i=0;i<32;i++){
            for(int j=0;j<n;j++){
                arr[i]+=(nums[j]>>i)&1;
                arr[i] %= 3;
            }
        }
        
        for(int i=0;i<32;i++){
            res |= (arr[i]<<i);
        }
        
        return res;
    }
};