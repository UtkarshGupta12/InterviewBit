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
 
Node* solve(Node* head)
{
    Node* P = head;
    Node* F = head;
    F = F->next;

    while(F != NULL)
    {
        
        if(P->data == F->data)
        {
            F = F->next;
            P->next = F;
        }
        else if(F==P)
            F=F->next;
        else
            P = P->next; 
    }
    printList(head);
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
    push(&head, 3);
    push(&head, 3);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    
    printList(head);cout<<endl<<endl;

    Node* ans = solve(head);
    //cout <<endl <<"Answer : "<< ans << endl;    

    return 0;
    
}
