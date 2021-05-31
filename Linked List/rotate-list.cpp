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
 
int countNodes(Node* head)
{
    Node* temp = new Node();
    temp = head;
    int count = 0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;}

Node* rotateRight(Node* head, int B)
{
    int len = countNodes(head);
    cout <<"Length of list : "<<len<<endl;

    int rot = B%len;
    cout <<"Rotation : "<<rot<<endl;
    if(rot == 0)
        return head;

    Node* temphead = head;

    for(int i=1;i<=len-rot;i++)
        head = head->next;

    Node* newend = temphead;
    for(int i=1;i<=len-rot-1;i++)
        newend = newend -> next;
    newend -> next = NULL;

    Node* combine = head;
    while(combine->next!=NULL)
        combine = combine->next;
    combine->next = temphead;

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
    
    //1 -> 2 -> 3 -> 4 -> 5
    //5 -> 4 -> 3 -> 2 -> 1 
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    cout<<"List : ";printList(head);cout<<endl<<endl;

    Node* ans = rotateRight(head,20);
    printList(ans);    

    return 0;
    
}
