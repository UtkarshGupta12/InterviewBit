+#include <iostream>
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
        temp = temp->next;}
    return count;}

Node* addTwoNumbers(Node* A, Node* B)
{
    if(!A)
        return B;
    if(!B)
        return A;

    Node* ans = NULL;
    int sum = 0;
    int carry = 0;

    int len = countNodes(A);

    for(int i=1;i<len;i++)
    {
        sum = A->data + B->data + carry;
        carry = sum/10;
        push(&ans, sum);
        A = A->next;
        B = B->next;
    }


    return ans;
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
    
    //Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    //Output: 7 -> 0 -> 8
    //342 + 465 = 807 
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 2);
    push(&head2, 4);
    push(&head2, 6);
    push(&head2, 5);
    
    cout<<"Ques List I : ";printList(head1);cout<<endl;
    cout<<"Ques List II: ";printList(head2);cout<<endl<<endl;

    Node* ans = addTwoNumbers(head1,head2);
    cout<<"Ans List : ";printList(ans);    

    return 0;
    
}
