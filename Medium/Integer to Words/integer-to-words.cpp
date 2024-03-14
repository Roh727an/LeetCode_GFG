//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
string ones[20]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine ","ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
string tens[10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    string convert(long n,string suffix){
        string res="";
        if(n>19){
            res+=(tens[n/10] + ones[n%10]);
        }
        else
        res+=ones[n];
        
        // Add Suffix
        if(n)
        res+=suffix;
        
        return res;
        
    }
    string convertToWords(long n) {
        // code here
        string str="";
        // Crore Part -> 10000000
        str+=convert(n/10000000,"crore ");
        // Lakh Part -> 100000
        str+=convert((n/100000)%100,"lakh ");
        // thousand Part -> 1000
        str+=convert((n/1000)%100,"thousand ");
        // hundred Part -> 100
        str+=convert((n/100)%10,"hundred ");
        
        if(n>100 && n%100!=0)
        str+="and ";
        str+=convert((n%100),"");
        return str;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends