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

Node* swapPairs(Node* head)
{
    Node* temp = head->next;
    Node* L = head;
    Node* R = head->next;

    int len = getCount(head);
    cout<<"Length : "<<len<<endl;
    int times = len/2;

    if(len<2)
        return head;

    //BASE CASE
    L->next = R->next;
    R->next = L;
    head = R;

    //MIDDLE CASES
    for(int i=2;i<=times;i++)    
    {
        temp = L;
        L = L->next;R = R->next->next->next;
        L->next = R->next;
        R->next = L; 
        temp->next = R;       
    }

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
    
    //1 -> 2 -> 3 -> 4 -> 5 -> 6  
    //2 -> 1 -> 4 -> 3 -> 6 -> 5  
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    cout<<"Ques List : ";printList(head);cout<<endl<<endl;

    Node* ans = swapPairs(head);
    cout<<"Ans List : ";printList(ans);    

    return 0;
    
}
