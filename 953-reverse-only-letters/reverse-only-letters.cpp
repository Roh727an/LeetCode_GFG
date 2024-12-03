class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            while(i<s.length() && !isalpha(s[i]))
            i++;
            while(j>=0 && !isalpha(s[j]))
            j--;
            if(i<j)
            swap(s[i++],s[j--]);
        }
        return s;
    }
};