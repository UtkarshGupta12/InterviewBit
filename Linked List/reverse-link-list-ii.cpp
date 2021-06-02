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

Node* reverseBetween(Node* head, int m, int n)
{
    if(!head)
        return NULL;
    else if(m==n)
        return head;

    Node* SS = NULL;
    Node* S = head;
    Node* E = head;
    Node* EE = head;
    Node* temp = head;
    int count = 0;

    while(temp)
    {
        count++;
        if(count==m-1)
            SS = temp;
        else if(count==m)
            S = temp;
        else if(count==n)
            E = temp;
        temp = temp -> next;}
    EE = E->next;
        
    Node* P = SS;
    Node* C = S;
    Node* F = S->next;
    bool end = false;
    bool start = false;

    if(m==1)
        start = true;
    if(EE==NULL)
        end = true;

    for(int i=0;i<n-m;i++)
    {
        C -> next = P;
        P = C;
        C = F;
        F = F -> next;}

    C -> next = P;
        P = C;
        C = F;
            
    if(start==false && end == false)
    {
        F = F -> next;
        S -> next = EE;
        SS -> next = E;}
    else if(start == false && end == true)
    {
        S -> next = EE;
        SS -> next = E;}    
    else if(start == true && end == false)
    {
        F = F -> next;

        S->next = EE;
        head = E;}
    else 
    {
        head = E;
        S -> next = NULL;} 
    
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
    
    //Given : 1->2->3->4->5->NULL, m = 1 and n = 4,
    //Return: 4->3->2->1->5->NULL.
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    int m = 1;
    int n = 4;

    cout<<"Ques List : ";printList(head);cout<<endl;
    cout<<"m : "<<m<<" -> "<<" n : "<<n<<endl;

    Node* ans = reverseBetween(head,m,n);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
