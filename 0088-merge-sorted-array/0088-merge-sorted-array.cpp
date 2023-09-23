class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1; //pointing to the last element of nums1
        int j= n-1; //pointing to the last element of nums2
        int k = m+n-1; //pointing to the last element of nums1 

        while(j>=0){
            //if nums1[i] is greater than nums2[j] then put it at place of k pointer
            if(i>=0 && nums1[i] >  nums2[j]){ 
                nums1[k] = nums1[i];
                k--;
                i--;
            }
            else{
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
    }
};