//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void findMiddle(Node* head,Node* &firstList,Node* &secondList)
    {
        Node* slow=head;
        Node* fast=head->next;
        // Traverse till Not NUll or Last Node
        while(fast!=NULL && fast->next !=NULL)
        {
           
            // Move Fast Pointer By Two Step
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
             // Move Slow Pointer By One Step
             slow=slow->next;
            }
            
        }
        // First list is from start to Middle
        firstList=head;
        // Second List is from Mid's Next to End
        secondList=slow->next;
        // Cut the Connection from Middle to Second List
        slow->next=NULL;

    }
    Node* MergeList(Node* firstList,Node* secondList)
    {
        // Base Case
        if(firstList==NULL)
        return secondList;
        if(secondList==NULL)
        return firstList;

        // Create one Final List
        Node* finalList=NULL;
        // First List has Smaller or Equal Element
        if(firstList->data <= secondList->data)
        {
            finalList=firstList;
            // Recursive Call to Update Final List
            finalList -> next=MergeList(firstList->next,secondList);
        }
        else
        {
            finalList=secondList;
            // Recursive Call to Update Final List
            finalList -> next=MergeList(firstList,secondList->next);
        }

        return finalList;
    }
    void Sort(Node* &head)
    {
        // Base Case
        if(head==NULL || head->next==NULL)
        return ;
        Node* curr=head;
        Node* firstList;
        Node* secondList;

        findMiddle(curr,firstList,secondList);

        // recursion Call for Both The Halfs
        Sort(firstList);
        Sort(secondList);

        // Merge them
        head=MergeList(firstList,secondList);

    }

    void addNode(Node* &A,Node* B)
    {
        A->next=B;
        A=B;
    }
    Node* segregate(Node *head) {
        
        // Add code here
        // Approch 1: Merge Sort
        /*
        Sort(head);
        return head;
        */

    //Approch 2: Count 0's,1's & 2's & Modify data According to that
    // Optimised Approch : modify Links Only

        Node* zero=new Node(-1);
        Node* temp0=zero;
        Node* one=new Node(-1);
        Node* temp1=one;
        Node* two=new Node(-1);
        Node* temp2=two;

        Node* trav=head;

        // Create three 3 Linked Lists
        while(trav!=NULL)
        {
            // zero
            if(trav->data==0)
            {
                addNode(temp0,trav);
            }
            // One
            else if(trav->data==1)
            {
                addNode(temp1,trav);
            }
            // Two
            else if(trav->data==2)
            {
               addNode(temp2,trav);
            }
            // Update trav Pointer
            trav=trav->next;
        }
        // Merge Them & Delete Dummy Nodes
        
        // Merge
        // There is No 1's
        if(one->next!=NULL)
        temp0->next=one->next;
        // There is 1's
        else
        temp0->next=two->next;

        // Delete Dummy Nodes
        temp1->next=two->next;
        temp2->next=NULL;
        head=zero->next;
        
        delete zero;
        delete one;
        delete two;

        return head;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends