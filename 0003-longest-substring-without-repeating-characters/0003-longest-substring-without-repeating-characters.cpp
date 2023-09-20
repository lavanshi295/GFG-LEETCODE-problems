class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        unordered_set<char>Set;
        int start =0, end=0;
        while(start < s.length()){
            auto it = Set.find(s[start]);

            if(it == Set.end()){
                if(start-end+1 > len){
                    len = start-end+1;
                }
                Set.insert(s[start]);
                start++;
            }
            else{
                Set.erase(s[end]);
                end++;                
            }
        }
        return len;
    }
};