class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int,int> m;

        for(int i = 0;i < n;i++){
            if(m.find(arr[i] - diff) != m.end())
                m[arr[i]] = max(m[arr[i]],1 + m[arr[i] - diff]);
            if(m[arr[i]] == 0)
                m[arr[i]]++;
            
        }

        for(auto &j : m){
            ans = max(ans,j.second);
        }

        return ans;
    }
};

// solved using dp memo using hashmap as dp memo array