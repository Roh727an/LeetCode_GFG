class Solution {
public:
    bool isVowel(char ch){
        return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
    }
    string reverseVowels(string s) {
        int i=0,j=s.length()-1;
        while(i<j){
            while(i<s.length() && !isVowel(s[i]))
            i++;
            while(j>=0 && !isVowel(s[j]))
            j--;
            if(i<j)
            swap(s[i++],s[j--]);
        }
        return s;
    }
};