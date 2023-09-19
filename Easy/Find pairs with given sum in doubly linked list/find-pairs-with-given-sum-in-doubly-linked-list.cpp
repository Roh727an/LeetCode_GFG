//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        // Base Case
        if(head==NULL || head->next==NULL)
        return {};
        vector<pair<int, int>> ans;
        // 1.Take a Start Pointer pointing at Starting Node
        Node *start=head;
        // 2.Take a End Pointer & Point that to the Last Node
        Node* end=head;
        while(end->next!=NULL)
        end=end->next;
        // 3. Iterate till they Meet-
        while(start!=end)
        {
            int d1=start->data;
            int d2=end->data;

            // a.If sum is Equal to target then store & End--
            if(d1+d2 == target)
            {
                ans.push_back({d1,d2});
                end=end->prev;
            }
            // b.If sum is Greater than target then  End--
            else if(d1 + d2 > target)
            {
                end=end->prev;
            }
            // c.If sum is Smaller than target then Start++
            else
            {
                start=start->next;
            }
        }
        // 4.IF No such Pair Exist return empty array ,Else Return ans
        if(ans.size()==0)
        return {}; 
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends