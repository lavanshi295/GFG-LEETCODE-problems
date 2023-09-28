class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //APPROACH:
        //hypothetically assume 2D matrix to be an 1D array and then just apply BINARY SEARCH
        //in order to find mid element in the 2D matrix we can simply do 
        //row = ind/m and col = ind%m


        int n = matrix.size(); //number of rows
        int m = matrix[0].size(); //number of col
        int low = 0, high = n*m -1; 

        while(low <= high){
            int mid = (low+high)/2;
            int row = mid/m; 
            int col = mid%m;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};