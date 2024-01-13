class Solution {
public:
    void rec(int i,int n,string s,int open,int close,vector<string>&ans){
        // Base Case (n=2*n as Number of Open Paranthesis = Number of Close Paranthesis)
        if(i>=2*n)
        {
            ans.push_back(s);
            return;
        }
        // IF open paranthesis is less than n then we pick open parantheiss
        if(open<n)
        {
            s.push_back('(');
            open=open+1;
            rec(i+1,n,s,open,close,ans);
            open=open-1;
            s.pop_back();
        }
        // We only pick a close paranthesis if the Number of open parantheisis is greater than close parantheis
        if(close<open)
        {
            s.push_back(')');
            close=close+1;
            rec(i+1,n,s,open,close,ans);
            close=close-1;
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=0,close=0,i=0;
        rec(i,n,"",open,close,ans);
        return ans;
    }
};