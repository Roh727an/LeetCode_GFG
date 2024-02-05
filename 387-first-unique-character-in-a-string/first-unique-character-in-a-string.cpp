class Solution {
public:
    int firstUniqChar(string s) {
        // Create a Hash Array of Size 26
        vector<int>hashMap(26,0);
        // Hashing
        for(int i=0;i<s.length();i++)
            hashMap[s[i]-'a']++;
        // Check for Single Element
        for(int i=0;i<s.length();i++)
        {
            if(hashMap[s[i]-'a']==1)
            return i;
        }
        return -1;
    }
};