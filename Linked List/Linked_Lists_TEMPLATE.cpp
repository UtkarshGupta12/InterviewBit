#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }}

void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;}  

Node* Insert(Node* head,int from,int to)
{
    if(from == to)
        return head;

    Node* A = NULL;
    Node* AP = NULL;
    Node* B = NULL;
    Node* BP = NULL;
    Node* temp = head;
    int count = 0;

    while(temp)
    {
        count++;
        if(count==from)
            A = temp;
        else if(count==from-1)
            AP = temp;
        else if(count==to)
            B = temp;
        else if(count==to-1)
            BP = temp;
        temp = temp -> next;}

    if(from-to==1)
        B = AP;    

    AP -> next = A -> next;
    A -> next = B;    

    if(to>1)
        BP -> next = A;
    else if(to == 1)
        head = A;

    return head;}

Node* Merge(Node* A,Node* B,int len)
{
    Node* AC = A;
    Node* AF = A->next;
    Node* BC = B;
    Node* BF = B->next;

    while(AF->next && BF)
    {
        AC -> next = BC;
        BC -> next = AF;
        AC = AF;
        AF = AF -> next;
        BC = BF;
        BF = BF -> next;
    }

    AC -> next = BC;
    BC -> next = AF;

    if(len%2==0)
        AF -> next = BF;

    return A;}

Node* reverse(Node* head)
{
    struct Node* prev = NULL;   
    struct Node* curr = head;
 
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;}

Node* reverseBetween(Node* head, int m, int n)
{
    if (m == n)
        return head;
 
    // revs and revend is start and end respectively
    // of the portion of the linked list which
    // need to be reversed. revs_prev is previous
    // of starting position and revend_next is next
    // of end of list to be reversed.
    Node* revs = NULL, *revs_prev = NULL;
    Node* revend = NULL, *revend_next = NULL;
 
    // Find values of above pointers.
    int i = 1;
    Node* curr = head;
    while (curr && i <= n) {
        if (i < m)
            revs_prev = curr;
 
        if (i == m)
            revs = curr;
 
        if (i == n) {
            revend = curr;
            revend_next = curr->next;
        }
 
        curr = curr->next;
        i++;
    }
    revend->next = NULL;
 
    // Reverse linked list starting with
    // revs.
    revend = reverse(revs);
 
    // If starting position was not head
    if (revs_prev)
        revs_prev->next = revend;
 
    // If starting position was head
    else
        head = revend;
 
    revs->next = revend_next;
    return head;}

void insertAfter(Node* prev_node, int new_data) 
{
   
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    { 
        cout << "the given previous node cannot be NULL"; 
        return; 
    }
   
    // 2. Allocate new node
    Node* new_node = new Node();
   
    // 3. Put in the data
    new_node->data = new_data; 
   
    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next; 
   
    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node; }    

void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    Node *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;}    

void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }}

void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;}    

/* Counts no. of nodes in linked list */
int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;}

/* Checks whether the value x is present in linked list */
bool search(Node* head, int x)
{
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;}

int GetNth(Node* head, int index)
{
 
    Node* current = head;
 
    // the index of the
    // node we're currently
    // looking at
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
 
    /* if we get to this line,
    the caller was asking
    for a non-existent element
    so we assert fail */
    assert(0);}

/* Function to get the nth node from the last of a linked list*/
void printNthFromLast(struct Node* head, int n)
{
    int len = 0, i;
    struct Node* temp = head;
 
    // count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
 
    // check if value of n is not
    // more than length of the linked list
    if (len < n)
        return;
 
    temp = head;
 
    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
 
    cout << temp->data;
 
    return;}        

void printMiddle(struct node* head)
{
    int count = 0;
    struct node* mid = head;
 
    while (head != NULL)
    {
         
        // Update mid, when 'count'
        // is odd number
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    // If empty list is provided
    if (mid != NULL)
        printf("The middle element is [%d]\n\n",
                mid->data);}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
 
    // Add elements in linked list
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    //insertAfter(head->next,4);
    //append(&head,5);
    //deleteNode(&head,3);

    printList(head);
    deleteList(&head);
    printList(head);

    return 0;
    
}
