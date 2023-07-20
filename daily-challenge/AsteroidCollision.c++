class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for(int i = 0;i < n;i++){
            if(arr[i] >= 0)
                ans.push_back(arr[i]);
            else{
                int curr = 0;
                while(ans.size() > 0){
                    curr = ans.back();
                    if(curr < 0 || curr > -arr[i])
                        break;
                    ans.pop_back();
                    if(curr == -arr[i])
                        break;
                }
                if(curr < 0 || curr < -arr[i])
                    ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};