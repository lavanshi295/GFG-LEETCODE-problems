class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int>Set;
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            if(Set.count(nums[i])){
                ans.push_back(nums[i]);
            }
            else{
                Set.insert(nums[i]);
            }
        }
        return ans;
    }
};