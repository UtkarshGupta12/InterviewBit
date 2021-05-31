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
 
Node* mergeTwoLists(Node* A, Node* B)
{
    Node* temphead = new Node();
    Node* currA = A;
    Node* currB = B;
    Node* temp = A;

    if(A->data >= B->data)
    {
        temphead->next = B;
        currB = currB->next;}
    else
    {
        temphead->next = A;
        currA = currA->next;}

    temp = temphead->next;    

    if(currB==NULL)
    {
        temp->next = currA;
        return temphead->next;} 
    else if(currA==NULL)
    {
        temp->next = currB;
        return temphead->next;}

    while(currA->next != NULL || currB->next != NULL)
    {
        int x = currA->data;
        int y = currB->data;
        int o = temp->data;

        if(x>o && y>o && y>=x)
        {
            temp->next = currA;
            currA = currA->next;
            temp = temp->next;}
        else if(x>o && y>o && x>=y)
        {
            temp->next = currB;
            currB = currB->next;
            temp = temp->next;}

        if(currA == NULL || currB == NULL)
            break;   }

    if(currA==NULL)
    {
        temp->next = currB;
        return temphead->next;}
    else if(currB==NULL)
    {
        temp->next = currA;
        return temphead->next;}

    if(temp->next == currB)
        temp->next->next = currA;
    else if(temp->next == currA)
        temp->next->next = currB;

    return temphead->next;
}     

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head1 = NULL;
    Node* head2 = NULL;
    
    //5 -> 8 -> 20 
    //4 -> 11 -> 15
    //The merged list should be :
    //4 -> 5 -> 8 -> 11 -> 15 -> 20
    // Add elements in linked list
    push(&head1, 3);
    push(&head1, 2);
    push(&head1, 1);
    push(&head2, 6);
    push(&head2, 5);
    push(&head2, 4);
    
    cout<<"List I : ";printList(head1);cout<<endl<<endl;
    cout<<"List II : ";printList(head2);cout<<endl<<endl;

    Node* ans = mergeTwoLists(head1,head2);
    printList(ans);    

    return 0;
    
}
