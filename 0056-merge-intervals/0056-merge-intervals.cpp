class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        //1. sort the intervals
        sort(intervals.begin(), intervals.end());
        //2. check for overlapping intervals
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(ans.empty()) //if ans is empty then push intervals in it
            ans.push_back(intervals[i]);

            else{
                //make an vector to store the last interval in our ans
                vector<int>&v = ans.back(); //end time of previous interval
                int y = v[1]; 
                //compare y with i's start time
                //overlapping intervals
                if(intervals[i][0] <= y)
                v[1] = max(intervals[i][1], y);

                //non-overlapping intervals
                else ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};