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

Node* reverse(Node* head)
{
    struct Node* prev = NULL;   
    struct Node* curr = head;
 
    while (curr) {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;}

Node* addTwoNumbers(Node* A, Node* B)
{
    Node* ans = NULL;

    int sum = 0;
    int carry = 0;
    bool flag = false;

    if(A->data+B->data > 10)
        flag = true;


    while(A||B||carry)
    {
        sum = 0;
        if(A) sum += A->data;
        if(B) sum += B->data;
        sum += carry;
        carry = sum/10;
        sum = sum%10;
        cout<<sum<<endl;
        push(&ans,sum);
        if(A) A = A->next;
        if(B) B = B->next;  
    }

    if(flag==true)
        push(&ans,1);

    ans = reverse(ans);
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
    push(&head1, 1);
    push(&head1, 9);
    push(&head1, 9);
    push(&head2, 1);
    //push(&head2, 9);
    //push(&head2, 9);

    cout<<"A : ";printList(head1);cout<<endl;
    cout<<"B : ";printList(head2);cout<<endl;

    Node* ans = addTwoNumbers(head1,head2);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
