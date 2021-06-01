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

Node* Reverse(Node* head)
{
    Node* P = NULL;
    Node* C = head;
    Node* F = head->next;

    while(F)
    {
        C->next = P;
        P = C;
        C = F;
        F = F->next;
        //printList(C);cout<<endl;
    }

    C->next = P;

    head = C;

    return head;}

Node* Merge(Node* A, Node* B,bool even)
{
    Node* CA = A;
    Node* FA = A->next;

    Node* CB = B;
    Node* FB = B->next;

    while(FB && FA)
    {
        CA -> next = CB;
        CA = FA;
        FA = FA -> next;

        CB -> next = CA;
        CB = FB;
        FB = FB -> next;
    }

    CA -> next = CB;

    if(even == false)
    {
        CA = FA;
        FA = FA -> next;
        CB -> next = CA;
    }

    return A;
}

Node* reorderList(Node* head)
{
    if(head->next==NULL)
        return head;

    int len = getCount(head);
    cout<<"Length : "<<len<<endl;

    Node* A = head;
    Node* B = head;
    bool even = true;

    int till;
    if(len%2==0)
        till = len/2;
    else
    {
        till = len/2+1;
        even = false;}

    for(int i=1;i<=till;i++)   B = B->next;
    for(int i=1;i<=till-1;i++) A = A->next; 
    A -> next = NULL; A = head;

    B = Reverse(B);
    cout<<"A : ";printList(A);cout<<endl;
    cout<<"B : ";printList(B);cout<<endl;

    A = Merge(A,B,even);

    return A;
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
    // 1 -> 9 -> 2 -> 8 -> 3 -> 7 -> 4 -> 6 -> 5 -> NULL
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

    Node* ans = reorderList(head);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
