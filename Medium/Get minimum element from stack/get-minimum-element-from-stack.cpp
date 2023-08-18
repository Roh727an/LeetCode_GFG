//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle=INT_MAX;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
           return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty())
           return -1;
           int del=-1;
           if(s.top() < minEle)
           {
               del=minEle;
               long long temp = (long long)2*minEle - (long long)s.top();
               minEle=(int)temp;
               s.pop();
               return del;
           }
           else
           {
               del=s.top();
               s.pop();
               return del;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(x < minEle)
           {
               long long mod_val=(long long)2*x - (long long)minEle;
               s.push((int)mod_val);
               minEle=x;
               return;
           }
           else
           s.push(x);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends