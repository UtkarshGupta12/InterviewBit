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

int solve(Node* head, int k) 
{
    int count=0;
    Node* temp = head;

    while(temp!=NULL)
    {
        count++;
        temp = temp->next;}

    int middle = (count/2)+1;

    int index = middle - k ;
    if(index<=0)
        return -1;

    temp = head;

    for(int i=1;i<index;i++)
        temp = temp->next;
    
    return temp->data;
}                

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
 
    //A : [ 630 -> 624 -> 85 -> 955 -> 757 -> 841 -> 967 -> 377 -> 932 ]
    //B : 2
    // Add elements in linked list
    push(&head, 932);
    push(&head, 377);
    push(&head, 967);
    push(&head, 841);
    push(&head, 757);
    push(&head, 955);
    push(&head, 85);
    push(&head, 624);
    push(&head, 630);
    
    printList(head);

    int ans = solve(head,2);
    cout <<endl <<"Answer : "<< ans << endl;    

    return 0;
    
}
