class Solution {
public:
    bool isPalidrome(int i,int j,string s){
        while(i<=j){
            if(s[i++]!=s[j--])
            return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j])
            return isPalidrome(i+1,j,s)||isPalidrome(i,j-1,s);
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
};