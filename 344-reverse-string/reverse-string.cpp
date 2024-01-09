class Solution {
public:
    void Rec(vector<char>& s,int i,int j)
    {
        if(i>=j)
        return ;

        swap(s[i],s[j]);

        Rec(s,i+1,j-1);
    }
    void reverseString(vector<char>& s) {
        Rec(s,0,s.size()-1);
    }
};