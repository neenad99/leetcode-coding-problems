// 2781. Length of the Longest Valid Substring

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.length();
        int i = 0;
        int ans = 0;
        unordered_set<string> hashWords;
        
        for(string & word : forbidden)
            hashWords.insert(word);
        
        for(int j = 0;j < n;j++){
            for(int k = j;k>(j-10) && k >= i;k--){
                if(hashWords.find(word.substr(k,j-k+1)) != hashWords.end()){
                    i = k + 1;
                    break;
                }
            }
            
            ans = max(ans,j-i+1);
        }
        
        return ans;
    }
};

// cbaaaabc   aaa cb 
//    i   j

// trick is to check constraint of this problem i.e  forbidden words will have length at max 10 length.
// So we let two pointers i and j now whenever we increase j we check if this character is end of any forbidden word so we check every word formed by this
// at max 10 len using another loop. suppose the word is "aaabbc" our current window is "aaab" here i is at 1th index and j is at 3rd index. and forbidden words
 //are"aabb,bc" now when we increase j our word becomes "aaabb" so we check if this b is end of any forbidden word that is we check "b" then "bb" then "abb" then 
 //"aabb" now we got that this is forbidden word so we move our ith index to index just after the current k which is at 5th index hence word becomes "abb" 
 //and this is not forbiddden in this way we calculate max len.
