//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

bool notOriginal(Node *head, unordered_map<Node *, int>&myMap){
    
    while(head){
        if(myMap.find(head)==myMap.end()) return true;
        if(myMap[head] != (head->data)) return true;
        
        head=head->next;
    }
}




// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    Node *FloydAlgorithm(Node *head)
    {
        //  Tortoise-Hare Approch Extension
        // Intutuion-We can prove that if the Linked List has a Cycle/Loop then fast &  slow Pointer eventually meet at some point for sure.
        // Base Case
        if (head == NULL || head->next == NULL)
            return NULL;
        if (head->next == head)
            return head;
        // 1.Create slow Pointer pointing at Head
        Node *slow = head;
        // 2.Create fast Pointer pointing at Head
        Node *fast = head;
        // 3.Traverse Both the Pointer till one of them becomes NULL-
        while (slow != NULL && fast != NULL)
        {
            // a.Update Slow by 1 Step
            slow = slow->next;
            // a.Update fast by 2 Step
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;

            // c.Check if Slow & Fast is Pointing at the Same Node,if yes then the LL has a Cycle-> Return True
            if (slow == fast)
                return slow;
        }
        // 4.Since slow/fast one of them becomes NULL so the Lnked List Doesnot Have Any Cycle
        return NULL;
    }
    Node* findFirstNode(Node* head)
    {
        // your code here
        if(head==NULL|| head->next==NULL)
        return NULL;

        Node* start=FloydAlgorithm(head);
        if(start==NULL)
        return NULL;
        while(head!=start)
        {
            head=head->next;
            start=start->next;
        }
        return head;
    }
    void removeLoop(Node* head)
    {
       if(head==NULL || head->next==NULL)
        return ;
        Node* startN=findFirstNode(head);
        if(startN==NULL)
        return; 
        Node* temp=startN->next;
        while(temp->next!=startN)
        {
            temp=temp->next;
        }
        
        temp->next=NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_map<Node *, int>myMap;
        
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        myMap[head]=num;
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
            myMap[tail]=num;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n || notOriginal(head, myMap))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends