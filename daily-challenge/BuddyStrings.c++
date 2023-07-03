class Solution {
public:
    bool buddyStrings(string s, string target) {
        int n = s.length();
        int m = target.length();

        if(n != m)return false;

        vector<int> freq(26);
        bool temp = false;

        for(int i = 0;i < n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a'] > 1){
                temp = true;
                break;
            }
        }

        if(s == target)return temp;

        for(int i = 0;i < n;i++){
            if(s[i] != target[i]){
                if(idx1 == -1)idx1 = i;
                else if(idx2 == -1)idx2 = i;
                else return false;
            }
        }
        

        return idx1 != -1 && idx2 != -1 && (s[idx2] == target[idx1]) && (s[idx1] == target[idx2]);
    }
};
