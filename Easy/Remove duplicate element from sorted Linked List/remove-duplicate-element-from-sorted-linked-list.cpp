//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
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
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
     // Base Case
    if (head == NULL || head->next == NULL)
        return head;
    // 1.Create a Prev Pointer Pointing at NULL
    Node *prev = NULL;
    // 2.Create a curr Pointer Pointing at head
    Node *curr = head;
    // 3.Traverse till curr becomes NULL-
    while (curr != NULL)
    {
        // a.Create a forward Pointer Pointing at curr's Next
        Node *forward = curr->next;
        // b.IF it is Duplicate Element then-
        if (forward != NULL && curr->data == forward->data)
        {
            // i.point Curr to Froward
            curr = forward;
            // ii.If it is First Node then Update Head
            if (prev == NULL)
            {
                head = curr;
            }
            // iii.If it is Not then First Node then point prev's Next to Forward
            else
            {
                prev->next = forward;
            }
        }
        // c.Else Update Pointers-
        else
        {
            // a.Prev as Curr & Curr as Forward
            prev = curr;
            curr = forward;
        }
    }
    // 4.Return the head
    return head;
}