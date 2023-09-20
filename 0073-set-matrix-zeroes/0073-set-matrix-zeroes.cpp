class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); //number of rows
        int n = matrix[0].size(); //number of cols
        int x = 1; 
        int y=1;

        for(int j=0; j<n; j++){
            //iterating in 1st row, if we have seen a zero, then make x=0
            if(matrix[0][j] ==0) x=0; 
        }
        for(int i=0; i<m; i++){
            //iterating in col, if we have seen a zero then make y=0
            if(matrix[i][0] == 0) y=0;
        }
        //iterating in the inner matrix
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    //if we have seen a zero, then we will mark in the corresponding 1st row and 1st col
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //Now we are checking that where the markers are zero, then make the corresponding row & col zero
        for(int j=1; j<n; j++){
            if(matrix[0][j] == 0){
                for(int i=1; i<m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        //same for this
        for(int i=1; i<m; i++){
            if(matrix[i][0] == 0){
                for(int j=1; j<n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //if my y==0 then we have to make the 1st col as Zero
        if(y==0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
        //if my x==0 then we have to make the 1st row as Zero
        if(x==0){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

    }
};