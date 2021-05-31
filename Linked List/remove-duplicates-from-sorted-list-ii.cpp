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
 
Node* deleteDuplicates(Node* head)
{
    Node* temphead = new Node();
    temphead->next = head;
    Node* prev = temphead;
    Node* temp = head;

    while(temp!=NULL)
    {
        while(temp->next != NULL && temp->data == temp->next->data)
            temp = temp->next;
        if(prev->next == temp)
            prev = prev->next;
        else
            prev->next = temp->next;
        temp = temp->next;
    }

    return temphead->next;
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
    push(&head, 5);
    push(&head, 4);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 1);
    
    printList(head);cout<<endl<<endl;

    Node* ans = deleteDuplicates(head);
    printList(ans);    

    return 0;
    
}
