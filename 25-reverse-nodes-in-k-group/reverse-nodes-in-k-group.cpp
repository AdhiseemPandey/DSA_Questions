/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// TC => O(N) + O(N) = O(2N)

class Solution {
public:
     ListNode* reverseList(ListNode* head) {
      if(head== NULL || head->next==NULL)
      {
        return head;
      }  
      ListNode*newhead=reverseList(head->next);
      ListNode*front=head->next;
      front->next=head;
      head->next=NULL;
      return newhead;
      
    }
     ListNode* findkthnode( ListNode* temp,int k)
     {
        k=k-1;
        while(k>0&&temp!=NULL)
        {
            k--;
            temp=temp->next;
        }

           return temp;

     }

    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp=head;
          ListNode* prev=NULL;
          while(temp!=NULL)
          {
             ListNode* knode=findkthnode(temp,k);
             
             if(knode==NULL)
             {
                if(prev)
                {
                    prev->next=temp;
                }
                break;
             }
             ListNode* nextnode=knode->next;
             knode->next=NULL;
             reverseList(temp);
             if(temp==head)
             {
                head=knode;
             }
             else{
                prev->next=knode;
             }
            prev=temp;
            temp=nextnode;
          }
          return head;
    }
};


















//                       OTHER SOLUTION  
// class Solution {
// public:
//     ListNode* reverse_LL(ListNode* head, ListNode* end){
//         ListNode* a = head, *front = nullptr;
//         while(a != end){
//             front = a->next;
//             a->next = end->next;
//             end->next = a;
//             a = front;
//         }
//         head = end;
//         return head;
//     }

//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head == nullptr || k == 1) return head;
//         ListNode* i = head, *kGroupBegin = nullptr, *kGroupPrev = nullptr;
//         int count = 0;
//         while(i != nullptr){
//             count++;
//             if(count % k == 1){
//                 kGroupPrev = kGroupBegin;
//                 kGroupBegin = i;
//             }
//             if(count % k == 0){
//                 ListNode* front = i->next;
//                 ListNode* reversedKGroup_head = reverse_LL(kGroupBegin, i);
//                 if(count / k == 1) head = reversedKGroup_head;
//                 if(kGroupPrev != nullptr) kGroupPrev->next = reversedKGroup_head;
//                 i = front;
//             } else {
//                 i = i->next;
//             }
//         }
//         return head;
//     }
// };
