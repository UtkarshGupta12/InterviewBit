#include <iostream>
#include <string>
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

struct Node
{
    int data;
    Node *next;};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " -> ";
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

Node* removeNthFromEnd(Node* head, int B)
{
    Node* start = head;
    Node* end = head;

    int len = getCount(head);
    if(B>=len)
        return head->next;

    for(int i=1;i<B;i++)
    {
        end = end -> next;
        if(end == NULL)
            break;
    }

    if(end == NULL||end->next == NULL)
        return head->next;

    while(end->next->next!=NULL)
    {
        start = start->next;
        end = end->next;
    }

    start->next = start->next->next;

    return head;
}         

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
 
    // Add elements in linked list
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    printList(head);cout<<endl<<endl;

    Node* ans = removeNthFromEnd(head,15);
    printList(ans);    

    return 0;
    
}
