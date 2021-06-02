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

Node* Merge(Node* A,Node* B,int len)
{
    Node* AC = A;
    Node* AF = A->next;
    Node* BC = B;
    Node* BF = B->next;

    while(AF->next && BF)
    {
        AC -> next = BC;
        BC -> next = AF;
        AC = AF;
        AF = AF -> next;
        BC = BF;
        BF = BF -> next;
    }

    AC -> next = BC;
    BC -> next = AF;

    if(len%2==0)
        AF -> next = BF;

    return A;}

Node* solve(Node* head)
{
    if(!head || !head-> next || !head-> next -> next)
        return head;

    int len  = getCount(head);
    cout<<"Length of List : "<<len<<endl;

    //SEPARATING ODD & EVEN ELEMENTS INTO TWO LISTS
    Node* head1 = head;
    Node* head2 = head->next;
    Node* O = head;
    Node* E = O -> next;
    Node* F = E -> next;

    for(int i=1;i<len/2;i++)
    {   
      O -> next = F;
      E -> next = F -> next;
      O = F;
      E = F -> next;
      F = E -> next; 
    }

    if(len%2==0)
    {
        Node* temp = head1;
        while(temp->next->next)
            temp = temp -> next;
        temp->next = NULL;}
    else if(len%2==1)
    {
        Node* temp = head1;
        while(temp->next->next->next)
            temp = temp->next;
        temp->next = temp->next->next;

        temp = head2;
        while(temp->next->next)
            temp = temp->next;
        temp->next = NULL;        }    

    head2 = reverse(head2);

    cout<<"Odd List  : ";printList(head1);cout<<endl;
    cout<<"Even List : ";printList(head2);cout<<endl;
    head1 = Merge(head1,head2,len);

    return head;}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
    
    //Given : 1->2->3->4->5->6->->NULL
    //Return: 1->6->3->4->5->2->->NULL
    //push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout<<"Ques List : ";printList(head);cout<<endl;

    Node* ans = solve(head);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
