/* First Unique Character in a String
Solution
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.*/
class Solution {
public:
    int firstUniqChar(string s) {
        int h[26]={0};
        for(int i=0;i<s.size();i++){
            h[s[i]-'a']++;
        }
        int i;
        for(i=0;i<s.size();i++){
            if(h[s[i]-'a']==1){
                break;
            }
        }
        if(i<s.size()&&s.size()>0){
            return i;
        }
        return -1;
    }
};
