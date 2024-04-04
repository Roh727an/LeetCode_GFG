class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int mxCnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            cnt++;
            else if(s[i]==')'){
                mxCnt=max(mxCnt,cnt);
                cnt--;
            }
        }
        return mxCnt;
    }
};