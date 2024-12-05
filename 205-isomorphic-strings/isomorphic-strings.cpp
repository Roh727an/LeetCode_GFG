class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Base Case
        if(s.length()!=t.length())
        return false;
        //For Hash s
        vector<int>hash(256,0);
        // To Check if Current Char is Already Mapped or Not
        vector<bool>isMapped(256,false); 

        for(int i=0;i<s.length();i++){
            // Not Mapped
            if(hash[s[i]]==0 && isMapped[t[i]]==false)
            {
                // Map it
                hash[s[i]]=t[i];
                isMapped[t[i]]=true;
            }
        }

        for(int i=0;i<s.length();i++){
            if(char(hash[s[i]])!=t[i])
                return false;
            
        }
        return true;
    }
};