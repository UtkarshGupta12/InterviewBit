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

Node* partition(Node* head, int B)
{
    //Assiging a temphead
    Node* temphead = head;
    Node* fakehead = new Node();
    fakehead->data = B-1;
    fakehead -> next = head;
    
    while(temphead->data < B && temphead->next ) 
        temphead = temphead->next;

    if(temphead->next == NULL)
        return head;

    Node* P = NULL;
    Node* PL = NULL;
    Node* C = head;
    Node* F = head->next;
    bool fake = false;

    //BASE CASE
    if(temphead!=head)
        C->next = temphead;
    else 
    {
        C = fakehead;
        F = C->next; 
        fake = true;
    }
    
    P = C;
    PL = C;
    C = F;
    F = F->next;

    while(F)
    {
        if(C->data < B)
        {
            PL ->next = F;
            C -> next = temphead;
            P -> next = C;
            P = C;
        }
        
        PL = C;
        C = F;
        F = F->next;
    }

    if(C->data < B)
    {
        PL -> next = F;
        C -> next = temphead;
        P -> next = C;
    }

    if(fake==true)
        return fakehead->next;
    else
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
    
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2 -> NULL 
    // 1 -> 2 -> 2 -> 4 -> 3 -> 5 -> NULL
    //push(&head, 9);
    push(&head, 2);
    push(&head, 5);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 1);
    
    cout<<"Ques List : ";printList(head);cout<<endl;

    Node* ans = partition(head,4);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
