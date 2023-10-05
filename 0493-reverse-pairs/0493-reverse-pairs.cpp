class Solution {
public:
int countPairs(vector<int>& nums, int low, int mid, int high){
    int cnt = 0; //store total no. of pairs
    int j = mid+1;
    for(int i=low; i<= mid; i++){ //iterate on left half of array
        while(j <= high && nums[i] > 2LL * nums[j]){ //checking for these 2 conditions
            j++;
        }
        cnt += (j - (mid+1));
    }
    return cnt;
}
void merge(vector<int>& nums, int low, int mid, int high){
    vector<int>temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high){ //iterating till anyone of array is exhausted 
        if(nums[left] <= nums[right]){ //if left is smaller than right
            temp.push_back(nums[left++]); 
        }
        else{
            temp.push_back(nums[right++]);
        }
    }
    //if one of the array is exhausted
    while(left <= mid){ //
        temp.push_back(nums[left++]);
    }
    while(right<= high){
        temp.push_back(nums[right++]);
    }

    //now copy back temp array to the nums
    for(int i=low; i<= high; i++){
        nums[i] = temp[i - low];
    }
}
int mergeSort(vector<int>&nums, int low, int high){
    int inv = 0;
    if(low >= high) return inv;
    int mid = (low+high)/2;
    inv = mergeSort(nums, low, mid); //left sorted array
    inv += mergeSort(nums, mid+1, high); //right sorted array 
    inv += countPairs(nums, low, mid, high); //this will sort and merge both left & right sorted arrays
    merge(nums, low, mid, high);
    return inv;
}
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};