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

Node* middleElement(Node* head_ref)
{
    Node* fast_ptr = head_ref;
    Node* slow_ptr = head_ref;

    while(fast_ptr->next != NULL && fast_ptr->next->next != NULL )
    {   
        slow_ptr = slow_ptr -> next;
        fast_ptr = fast_ptr -> next ->next;
    }

    return slow_ptr;}

Node* reverseNode(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* further = head;

    while(further != NULL)
    {
        further = further -> next;
        current -> next = prev;
        prev = current;
        current = further;
    }

    return prev; }    

int lPalin(Node* head)
{
    Node* middle = middleElement(head);
    cout <<"Middle Value : "<< middle->data << endl;

    Node* temphead = middle->next;
    middle->next = NULL;
    temphead = reverseNode(temphead);
    cout<<"Left Side : ";printList(head);cout<<endl;
    cout<<"Right Side : ";printList(temphead);cout<<endl;

    while(temphead != NULL && head!= NULL)
    {
        if(temphead->data != head-> data)
            return 0;
        temphead = temphead->next;
        head = head->next;
    }

    return 1;
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
    push(&head, 2);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    printList(head);cout<<endl<<endl;

    int ans = lPalin(head);
    cout <<endl <<"Answer : "<< ans << endl;    

    return 0;
    
}
