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

void ReversePart(Node* SS,Node* E)
{
    Node* S = SS->next;
    Node* EE = E->next;

    Node* prev = SS;
    Node* curr = S;
    Node* forw = S->next;
    int error = 10;

    while(forw->next && forw && error)
    {
        curr -> next = prev;
        prev = curr;
        curr = forw;
        forw = forw -> next;
        error--;
        if(forw->next == EE || forw->next == NULL)
            break;
    }}

Node* reverseList(Node* head,int K)
{
    Node* temphead = new Node();
    temphead->data = 0;
    temphead->next = head;

    int len = getCount(head);
    int times = len/K;
    cout<<"Length : "<<len<<endl<<"Times of Rotation : "<<times<<endl;

    //BASE CASE
    Node* SS = temphead;
    Node* E = head->next->next;
    cout<<"SS : "<<SS->data<<" & E : "<<E->data<<endl;
    
    ReversePart(temphead,E);

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
    
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> NULL 
    // 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7 -> NULL
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    cout<<"Ques List : ";printList(head);cout<<endl;

    Node* ans = reverseList(head,3);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
