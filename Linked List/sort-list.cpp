// TLE for NlogN
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

Node* Swap(Node* head,int m)
{
    int from = m;
    int to = m-1;

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

Node* sortList(Node* head)
{
    if(!head || !head->next)
        return head;

    int len = getCount(head);
    //head = Swap(head,3);
    for(int i = 0;i<len;i++)
    {    
        Node* L = head;
        Node* R = head->next;
        int m=2;
        bool flag = false;

        while(R)
        {
            cout<<"L : "<<L->data<<" & R : "<<R->data<<endl;
            cout<<"l : "<<m-1<<" & r : "<<m<<endl<<endl;
            if(L->data > R->data)
            {
                head = Swap(head,m);
                Node* temp = L;
                L = R;
                R = temp;
                flag = true;
            }
            R = R -> next;
            L = L -> next;
            m++;
            printList(head);cout<<endl;
        }
        if(flag == false)
            break;
    }    

    return head;}

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
    push(&head, 13);
    push(&head, 11);
    push(&head, 12);
    //push(&head, 2);
    //push(&head, 3);
    //push(&head, 4);

    //cout<<"Ques List: ";
    printList(head);cout<<endl;

    Node* ans = sortList(head);
    cout<<endl<<"Ans List : ";printList(ans);    

    return 0;
    
}
