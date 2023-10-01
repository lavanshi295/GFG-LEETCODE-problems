class Solution {
public:
    int search(vector<int>& nums, int target) {
        //APPROACH: Binary search
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            //if mid is target 
            if(nums[mid] == target) return mid;

            //left sorted part
            if(nums[low] <= nums[mid]){
                //check if target lies in left sorted part i.e. from low to mid
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                }
                else low = mid+1;
            }
            //right is sorted
            else{
                //check if target lies in right sorted part i.e. from mid to high
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        //if not found then return -1
        return -1;
    }
};