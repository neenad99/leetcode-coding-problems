class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        vector<int> arr = {2};
        vector<bool> isPrime(n+1,true);
        
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i = 2;i*i <= n;i++){
            if(isPrime[i]){
                for(int j = i*i;j<n;j+=i){
                    isPrime[j] = false;
                }
            }
        }
        
        for(int i = 0;i <= n;i++){
            if(isPrime[i])
                arr.push_back(i);
        }
        
        int l = 0;
        int r = arr.size() - 1;
        
        while(l <= r){
            if(arr[l] + arr[r] == n){
                ans.push_back({arr[l],arr[r]});
                l++;
                r--;
            }
            else if(arr[l] + arr[r] > n)
                r--;
            else
                l++;
        }
        
        return ans;
    }
};  