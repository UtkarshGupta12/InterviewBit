/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* reverseList(ListNode* head)
{
    struct ListNode* prev = NULL;   
    struct ListNode* curr = head;
 
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;} 
 
ListNode* Solution::mergeKLists(vector<ListNode*> &vec)
{
    ListNode* head = NULL;
    priority_queue<pair<int,ListNode*>> pq;

    for(int i=0;i<vec.size();i++)
    {
        ListNode* temp = vec[i];
        while(temp != NULL)
        {   
            pq.push(make_pair(temp->val,temp));
            temp = temp->next;
        }
    }

    //cout<< pq.top().second <<endl;
    //Handling Head Case
    head = pq.top().second;
    pq.pop();
    ListNode* tmp = NULL;
    tmp = head;

    while(!pq.empty())
    {
        tmp->next = pq.top().second;
        pq.pop();
        tmp = tmp->next;
    }
    
    tmp->next = NULL;
    
    head = reverseList(head);
    return head;
    
} 
