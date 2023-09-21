class Solution {
public:
    void sortColors(vector<int>& nums) {
        //using three pointer approach: low, mid, high

        int low =0;
        int mid = 0;
        int high = nums.size() -1;

        while(mid<= high){
            if( nums[mid] ==0 ){
                //swap it with nums[low]
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }
            else if( nums[mid] ==2 ){
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }
            else mid++;

        }
    }
};