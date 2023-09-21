class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0]; //initialising with 1st element of the nums array

        for(int i=0; i<nums.size(); i++){
            sum = sum+ nums[i]; //calcullating sum of every number

            maxi = max(maxi, sum); //updating maxi
            
            if(sum <0) sum=0; //checking if sum <0
        }
        return maxi;
    }
};