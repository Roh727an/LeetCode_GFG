//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
    int mp[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i]; // Get the Character
        int idx = ch - 'a';
        // Increase Frequency
        mp[idx] += 1;
    }
    int maxChar,maxoc=-1;
    for(int i=0;i<26;i++){
        if(mp[i]!=0)
        {
            if(mp[i]>maxoc)
            {
                maxoc=mp[i];
                maxChar=i+'a';
            }
        }
    }
    return maxChar;
    }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends