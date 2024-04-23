class Solution {
public:
    void sortColors(vector<int>& a) {
        // code here
        int n=a.size(); 
        int zero=0,one=0,two=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            zero++;
            else if(a[i]==1)
            one++;
            else
            two++;
        }
        int idx=0;
        
        while(idx<n && zero--)
        a[idx++]=0;
        
        while(idx<n && one--)
        a[idx++]=1;
        
        while(idx<n && two--)
        a[idx++]=2;
    }
};