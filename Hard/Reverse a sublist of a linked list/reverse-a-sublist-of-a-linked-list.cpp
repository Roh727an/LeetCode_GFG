//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    void Reverse(struct Node *&prev,struct Node *&curr){
        // Base Case
        if(curr==NULL)
        return ;

        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        Reverse(prev,curr);
    }
    Node* ReverseList(Node* &head)
    {
        Node* prev=NULL;
       Node* curr=head;
       Reverse(prev,curr);
       return prev;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(head==NULL || head->next==NULL || m==n)
        return head;
        
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt!=m)
        {
            cnt++;
            prev=curr;
            curr=curr->next;
        }
        Node* revStart=curr;

        while(cnt!=n)
        {
            curr=curr->next;
            cnt++;
        }

        Node* remList=curr->next;
        curr->next=NULL;

        Node* revHead=ReverseList(revStart);
        
        if(prev!=NULL)
        prev->next=revHead;

        curr=revHead;

        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=remList;

        if(m==1)
        return revHead;

        else 
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends