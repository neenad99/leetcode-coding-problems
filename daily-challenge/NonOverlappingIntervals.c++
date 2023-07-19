class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[] (vector<int> &interval1,vector<int> &interval2) -> bool 
        {
            return interval1[1] < interval2[1];
        });

        int n = intervals.size();

        int i = 0;
        int j = 1;
        int ans = 0;

        while(j < n){
            if(intervals[i][1] > intervals[j][0]){
                ans++;
            }
            else{
                i = j;
            }
            j++;
        }
         
        return ans;
    }
};


// [1,2] [1,3] [2,3] [3,4]

//  i      j


// 1 -> 7
// 2 -> 3
// 4 -> 5
// 6 -> 8

// considering sorting intervals based on end unit consider abobe eg for more details on logic used