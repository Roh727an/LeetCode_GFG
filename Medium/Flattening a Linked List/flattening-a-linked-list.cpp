//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
void findMiddle(Node *head, Node *&firstList, Node *&secondList)
{
    Node *slow = head;
    Node *fast = head->bottom;
    // Traverse till Not NUll or Last Node
    while (fast != NULL && fast->bottom != NULL)
    {

        // Move Fast Pointer By Two Step
        fast = fast->bottom;
        if (fast != NULL)
        {
            fast = fast->bottom;
            // Move Slow Pointer By One Step
            slow = slow->bottom;
        }
    }
    // First list is from start to Middle
    firstList = head;
    // Second List is from Mid's Next to End
    secondList = slow->bottom;
    // Cut the Connection from Middle to Second List
    slow->bottom = NULL;
}
Node *MergeList(Node *firstList, Node *secondList)
{
    // Base Case
    if (firstList == NULL)
        return secondList;
    if (secondList == NULL)
        return firstList;

    // Create one Final List
    Node *finalList = NULL;
    // First List has Smaller or Equal Element
    if (firstList->data <= secondList->data)
    {
        finalList = firstList;
        // Recursive Call to Update Final List
        finalList->bottom = MergeList(firstList->bottom, secondList);
    }
    else
    {
        finalList = secondList;
        // Recursive Call to Update Final List
        finalList->bottom = MergeList(firstList, secondList->bottom);
    }

    return finalList;
}
void Sort(Node *&head)
{
    // Base Case
    if (head == NULL || head->bottom == NULL)
        return;
    Node *curr = head;
    Node *firstList;
    Node *secondList;

    findMiddle(curr, firstList, secondList);

    // recursion Call for Both The Halfs
    Sort(firstList);
    Sort(secondList);

    // Merge them
    head = MergeList(firstList, secondList);
}
Node *mergeSort(Node *head)
{
    // your code here
    Sort(head);
    return head;
}
Node *flatten(Node *root)
{
    // Your code here
    // Base Case
    if (root == NULL || root->next == NULL)
        return root;

    Node *curr = root;
    Node *temp = root;

    while (curr != NULL)
    {
        temp = curr;
        while (temp->bottom != NULL)
        {
            temp = temp->bottom;
        }
        // Last Node of Downwards
        temp->bottom = curr->next;
        curr->next = NULL;
        curr = temp->bottom;
    }
    return mergeSort(root);
}

