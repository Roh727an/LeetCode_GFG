class Solution {
public:
    int numSteps(string s) {
        int ans=0,c=0,n=s.length();
        for(int i=n-1;i>=1;i--){
            // Odd
            if((s[i]-'0' + c)%2==1)
            {
                ans+=2;
                c=1;
            }
            else
            ans+=1;
        }
        return ans+c;
    }
};