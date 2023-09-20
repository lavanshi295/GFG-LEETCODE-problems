class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int infpt = 0;
        int n = nums.size()-1;

        for(int i=n; i>0; i--){ //eg: 7 2 5 3 1 here infpt is 5 
            if(nums[i] > nums[i-1]){ //if the prev num is smaller then infpt is i
                infpt = i;
                break;
            }
        }
        if(infpt == 0){
            //otherwise sort the array as listed in ques
                sort(nums.begin(), nums.end());
            }
        else{
            //now for swapping the toswap element
                int min = INT_MAX;  
                int toswap = nums[infpt-1]; //declaring toswap variable
                for(int j=infpt; j<=n; j++){ //iterating from infpt to n
                //check if the diff of the num and toswap is smaller and less than min
                    if(nums[j] - toswap>0 && nums[j] - toswap <min){
                        //if yes then swap both
                    int temp = nums[j];
                    nums[j] = nums[infpt-1];
                    nums[infpt-1] = temp;
                    } 
                }
                //otherwise sort the array with infpt
                //ans for eg: 73125
                sort(nums.begin()+infpt, nums.end());
        }

    }
};