class Solution {
public:
    bool rotateString(string s, string goal) {
        // Base Case
        if(s.length()!=goal.length())
        return false;
        for(int i=0;i<s.length();i++){
            char ch=s[0];
            s.erase(0,1);
            s.push_back(ch);
            if(s==goal)
            return true;
        }
        return false;
    }
};