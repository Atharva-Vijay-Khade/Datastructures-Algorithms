Given an array of intervals where intervals[i] = [starti, endi], 
merge all overlapping intervals, and return an array of the 
non-overlapping intervals that cover all the intervals in the input.

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104

class Solution {
public:
    struct myCmp {
        bool operator()(vector<int> &v1, vector<int> &v2) {
            return (v1[0] < v2[0]);
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        
        sort(intervals.begin(),intervals.end(),myCmp());
        
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= intervals[i-1][1]) {
                intervals[i][0] = min(intervals[i][0], intervals[i-1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i-1][1]);
                intervals[i-1][0] = -1;
                intervals[i-1][1] = -1;
            }
        }
        
        for(int i=0;i<intervals.size();i++)
            if(intervals[i][0] != -1)
                res.push_back(intervals[i]);
        
        return res;
        
    }
};