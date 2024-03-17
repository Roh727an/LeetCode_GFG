class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
              vector<vector<int>> res;
        
        // Iterate through intervals and add non-overlapping intervals before newInterval
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        
        // Merge overlapping intervals
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        // Add merged newInterval
        res.push_back(newInterval);
        
        // Add non-overlapping intervals after newInterval
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};