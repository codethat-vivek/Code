/* You are given a pointer to the node which is to be deleted from the linked list of N nodes.
The task is to delete the node. Pointer/ reference to head node is not given.
Note: No head reference is given to you.
    It is guaranteed that the node to be deleted is not a tail node in the linked list.

For Example --
Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30
Explanation: After deleting 20 from
the linked list, we have remaining
nodes as 10, 4 and 30. */

// SOLUTION -

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


void deleteNode(Node *node_ptr);

// Main Function
int main(void)
{
    int t,k;

    scanf("%d",&t);
    while(t--)
    {
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return(0);
}

void deleteNode(Node *node)
{
   // Basically we copy the data of next node to the current node which is to be deleted,
   // And then delete the next node

   // after is a pointer to the next node
   Node *after = node -> next;
   node -> data = after -> data;
   node -> next = after -> next;
   free(after);
}

