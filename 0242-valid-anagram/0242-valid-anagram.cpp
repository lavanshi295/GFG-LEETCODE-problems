class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};

        //counting the number of characters in string s
        for(char x : s){
            count[x - 'a']++;
        }
        //counting the number of characrers in string t(decreasing)
        for(char x: t){
            count[x - 'a']--;
        }

        for(int i : count){
            if(i != 0){
                return false;
            }
        }
        return true;

    }
};