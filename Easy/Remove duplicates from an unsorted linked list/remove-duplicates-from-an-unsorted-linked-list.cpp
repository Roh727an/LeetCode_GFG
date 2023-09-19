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


// } Driver Code Ends
/*
The structure of linked list is the following

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
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
    // Base Case
     if(head==NULL || head->next==NULL)
     return head;
    //  1.Create a Set Data Structure to Contain Unique Node data
     unordered_set<int>hashSet;
     // 2.Create a Prev Pointer Pointing at NULL
     Node* prev=NULL;
     // 3.Create a curr Pointer Pointing at head
     Node* curr=head;
     // 4.Traverse till curr becomes NULL-
     while(curr!=NULL)
     {
        // a.If the Current Node data is Found in the HashSet then-
        if(hashSet.find(curr->data)!=hashSet.end())
        {
            // Point Prev's next to curr's Next & Delete Current
            prev->next=curr->next;
            Node* temp=curr;
            temp->next=NULL;
            delete temp;
        }
        // b.If the Current Node data is NOT Found in the HashSet then-
        else{
            // Insert the Current Node value into HashSet & Update Pointers
            hashSet.insert(curr->data);
            prev=curr;
        }
        // c.Update Current as Prev's Next
        curr=prev->next;
     }
    //  5.Return head
     return head;
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
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
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}
// } Driver Code Ends