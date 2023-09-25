//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
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

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
                // Base Case
        if(head==NULL || head->next==NULL)
        return head;
        // 1.Create an Array to Stor Right Max Nodes Data
        vector<int>rmax;
        Node* temp=head;
        // 2.Copy the Linked List to Right Max Array 
        while(temp!=NULL)
        {
            rmax.push_back(temp->data);
            temp=temp->next;
        }
        // 3.Find Right Max
        int mx=rmax[rmax.size()-1];
        for(int i=rmax.size()-1;i>=0;i--)
        {
            if(rmax[i]>mx)
            mx=rmax[i];

            rmax[i]=mx;
        }
        // 4.Delete Nodes Accoring to Right Max Array
        Node* prev=NULL;
        Node* curr=head;
        for(int i=0;i<rmax.size() && curr!=NULL;i++)
        {
            Node* forward=curr->next;
            // a.If Right MAx of the Node is Greater than the Node itself then Delete the Node
            if(rmax[i]>curr->data)
            {
                // i.IF the Node is First Node
                if(prev==NULL)
                {
                    head=head->next;
                    curr=head;
                }
                //ii. Node is Not The First Node
                else
                {
                    prev->next=curr->next;
                    // curr->next=NULL;
                    curr=forward;
                }
            }
            // b.Else Simply Update Pointers
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        // 5.Return Head
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
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
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends