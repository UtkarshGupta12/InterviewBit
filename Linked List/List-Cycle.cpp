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

Node* detectCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    if (head == NULL || head->next == NULL)
        return head;

    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast)
            break;
    }

    if(slow != fast)
        return NULL;

    if(slow == fast)
    {
        slow = head;
        if(slow == fast)
            return slow;
        else
        {
            while(slow->next != fast->next)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
        }
    }

    cout << slow->next->data <<endl;
    return slow->next; 
}

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt     
    freopen("input1.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
  #endif

    Node* head = NULL;
    
    //           ______
    //           |     |
    //           \/    |
    //  1 -> 2 -> 3 -> 4

    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    //push(&head2, 6);
    //push(&head2, 5);
    head->next->next->next->next = head->next->next;

    
    //cout<<"Ques List I : ";printList(head1);cout<<endl;

    Node* ans = detectCycle(head);
    //cout<<"Ans List : ";printList(ans);    

    return 0;
    
}
