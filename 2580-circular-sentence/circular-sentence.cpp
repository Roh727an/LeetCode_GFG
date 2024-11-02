class Solution {
public:
    bool isCircularSentence(string s) {
        char firstChar=s[0];
        stack<char>st;
        st.push(s[0]);
        bool newChar=false;
        for(int i=1;i<s.length();i++){
            if(s[i]==' '){
               newChar=true;
               continue; 
            }
            else if(newChar){
                if(!st.empty() && st.top()!=s[i])
                return false;
                newChar=false;
            }
            st.push(s[i]);
        } 
        return st.top()==firstChar;
    }
};