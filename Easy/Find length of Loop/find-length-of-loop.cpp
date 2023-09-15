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

int countNodesinLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        cout<< countNodesinLoop(head) << endl;
    }
	return 0;
}

// } Driver Code Ends


/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Function to find the length of a loop in the linked list.
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
int countNodesinLoop(struct Node *head)
{
    // Code here
    // Base Case
    if(head==NULL || head->next==NULL)
    return 0;
    if(head->next==head)
    return 1;

    int length=1;
    // 1.Find the Insertion Node of Cycle by Floyd Cycle Detection Algorithm
    Node* Insertion=FloydAlgorithm(head);
    if(Insertion==NULL)
    return 0;
    // 2.Take a Temp Pointer & Calculate
    Node* temp=Insertion->next;
    while(temp!=Insertion)
    {
        length++;
        temp=temp->next;
    }
    return length;
}