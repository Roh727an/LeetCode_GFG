class Solution {
public:
    int strStr(string haystack, string needle) {
        // Base Case
        if(needle.length() > haystack.length())
        return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;i++){
            string sub=haystack.substr(i,needle.length());
            if(sub==needle)
            return i;
        }
        return -1;
    }
};