class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //initialise a int to store the duplicate number
        int ind = 0;
        //sort the vector
        sort(nums.begin(), nums.end());

        //if nums[i]==nums[i+1] then return nums[i] and then break
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1]){
            ind = nums[i];
            break;
        }
        }
        return ind;
    }
};