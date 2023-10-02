//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
        void rec(string s, int n)
    {
        // Base Case
        if (s.length() >= n)
        {
            bool check = true;
            for (int i = 0; i < s.length() - 1; i++)
            {
                // Consicutive One
                if (s[i] == '1' && s[i + 1] == '1')
                {
                    check = false;
                    break;
                }
            }
            if (check)
                cout << s << " ";
            return;
        }
        // Push 0 into String
        s.push_back('0');
        // Recursive Call(For 0)
        rec(s, n);
        // Pop the last added 0 from String
        s.pop_back();
        // Push 1 into String
        s.push_back('1');
        // Recursive Call(For 0)
        rec(s, n);
    }
    void generateBinaryStrings(int num)
    {
        // Write your code

        string s = "";
        rec(s, num);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends