//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  unordered_map<string,int>mp;
    int invalid(string s)
    {
        stack<char>st;
        int i=0;
        while(i<s.length())
        {
            //Opening Bracket 
            if(s[i]=='(' )
            st.push(s[i]);
            else if(s[i]==')')
            {
                // if there is an Opening Bracket
                if(st.size()>0 && st.top()=='(')
                st.pop();
                else
                st.push(')');
            }
            i++;
        }
        return st.size();
    }
    void rec(int inval,string s,set<string>&ans)
    {
        // If it is Already Visited then Simply Return
        if(mp[s]!=0)
        return;
        if(mp[s]==0)
        mp[s]++;
        // Base Case
        if(inval<0)
        return;
        // If there is No Invalid Paranthesis left then we Check if the Given String is valid or not,if valid then we push into our answer
        if(inval==0)
        {
            // check if Valid
            if(!invalid(s))
            ans.insert(s);

            return;
        }
        // For each index check try 2 Options
        for(int i=0;i<s.length();i++)
        {
            string leftSub=s.substr(0,i);
            string rightSub=s.substr(i+1);
            // Recursive Call
            rec(inval-1,leftSub+rightSub,ans);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        // code here
        int invalid_Paranthesis=invalid(s);
        set<string>st;
        rec(invalid_Paranthesis,s,st);
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends