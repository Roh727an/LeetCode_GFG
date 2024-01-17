class Solution {
public:
    void rec(int digIdx,int len,string digits,string temp, vector<string>&ans,map<int,string>mp)
    {
        // Base Case
        if(digIdx>=len)
        {
            ans.push_back(temp);
            return;
        }
        int digit=digits[digIdx]-'0';
        string comb=mp[digit];
        // Try all Combinations
        for(int i=0;i<comb.length();i++)
        {
            // Pick Element
            temp.push_back(comb[i]);
            rec(digIdx+1,len,digits,temp,ans,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
        vector<string>ans;
        if(n==0)
        return ans;
        string temp="";
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

        rec(0,n,digits,temp,ans,mp);
        return ans;
    }
};