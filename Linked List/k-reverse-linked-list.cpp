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
        cout << n->data << " -> ";
        n = n->next;
    }
    cout  << "NULL";}

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

Node* reverseList(Node* head,int K)
{
    if(K==1)
        return head;
    int len = getCount(head);
    int times = len/K;
    cout<<"Length : "<<len<<endl<<"Times of Rotation : "<<times<<endl;
    int m = 1;
    int n = K;

    //BASE CASE
    for(int i=1;i<=times;i++)
    {
        head = reverseBetween(head,m,n);
        m += K;
        n += K;
    }

    return head;}    

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
    
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL 
    // 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> NULL
    //push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    cout<<"Ques List : ";printList(head);cout<<endl;

    Node* ans = reverseList(head,2);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
