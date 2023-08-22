//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedOrder(stack<int>& s,int ele)
{
    // Base Case
    if(s.empty() || s.top() < ele)
    {
        s.push(ele);
        return ; 
    }
    
    
    int topEle=s.top();
    s.pop();
    SortedOrder(s,ele);
    s.push(topEle);
    
}
void SortedStack :: sort()
{
   //Your code here
    //   Base Case
    if(s.empty())
    return ;
    
    // Get the Top Element 
    int topEle=s.top();
    s.pop();
    // Recursion Call
    sort();
    // Backtracking-> Put the StackTop in it's Correct Order
    SortedOrder(s,topEle);
    
}