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

Node* Insert(Node* head,int from,int to)
{
    if(from == to)
        return head;

    Node* A = NULL;
    Node* AP = NULL;
    Node* B = NULL;
    Node* BP = NULL;
    Node* temp = head;
    int count = 0;

    while(temp)
    {
        count++;
        if(count==from)
            A = temp;
        else if(count==from-1)
            AP = temp;
        else if(count==to)
            B = temp;
        else if(count==to-1)
            BP = temp;
        temp = temp -> next;}

    if(from-to==1)
        B = AP;    

    AP -> next = A -> next;
    A -> next = B;    

    if(to>1)
        BP -> next = A;
    else if(to == 1)
        head = A;

    return head;}

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

Node* insertSortList(Node* A)
{
    Node* L = A;
    Node* temp = NULL;
    Node* R = A->next; 
    int len = getCount(A);
    //cout << "Length : "<< len << endl << endl;
    int l = 1, r= 2;

    while(L->next->next || R->next)
    {
        cout<<"L : "<<L->data<<" & R : "<<R->data<<endl;
        cout<<"l : "<<l<<" & r : "<<r<<endl<<endl;
        if(l < len && r <len)
        {    
            if(L->data > R->data)
            {
                A = Insert(A,r,l);
                temp = L;
                L = R;
                R = temp;
                r = l+1;
            }    
            r++;
            R = R->next;
        }    
        else if(r == len)
        {
            if(L->data > R->data)
            {
                A = Insert(A,r,l);
                temp = L;
                L = R;
                R = temp;
                r = l+1;
            }    
            L = L->next;
            R = L->next;
            l++;
            r = l+1;
        }
        printList(A);cout<<endl;}

    cout<<"L : "<<L->data<<" & R : "<<R->data<<endl;
    cout<<"l : "<<l<<" & r : "<<r<<endl<<endl;

    if(L->data > R->data)
            A = Insert(A,r,l);

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
    
    //Input : 4 -> 3 -> 2 -> 10 -> 12 -> 1 -> 5 -> 6 -> NULL 
    //Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 10 -> 12 -> NULL

    //Input : 12 -> 11 -> 13 -> 5 -> 6 -> NULL 
    //Output: 5 -> 6 -> 11 -> 12 -> 13 -> NULL    
    push(&head, 6);
    push(&head, 5);
    push(&head, 1);
    push(&head, 10);
    push(&head, 12);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    //cout<<"Ques List: ";
    printList(head);cout<<endl;

    Node* ans = insertSortList(head);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
