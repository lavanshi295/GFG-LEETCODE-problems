class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>>ans;

       for(int i=0; i<numRows; i++){
           vector<int>v(i+1, 1);
           for(int j=1; j<i; j++){
               //current_row->i, previous_row->i-1;
               v[j] = ans[i-1][j] + ans[i-1][j-1]; //sum of previous row 2 element
           }
           ans.push_back(v);
       }
       return ans;
    }
};