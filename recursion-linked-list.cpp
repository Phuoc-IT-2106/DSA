#include <iostream>
#include <stdexcept> //for using throw
using namespace std;
struct NODE{
    int val;
    NODE* next;
};

class Solution{
    public:
    NODE* createNODE(int x){
        NODE* p = new NODE;
        p->val = x; p->next = NULL;
        return p;
    }
    void InsertHead(NODE*& head,int x){
        NODE* p = createNODE(x);
        if(!head){
            head = p;
            return;
        }
        p->next = head;
        head = p;
    }

    void InsertTail(NODE*& head, int val){
        if(!head)InsertHead(head,val);
        NODE* p = createNODE(val);
        NODE* cur = head;
        while(cur->next) cur = cur->next;
        cur->next = p;
    }

    void print(NODE* head){
        NODE* cur = head;
        if(!head) return;
        cout << " " << cur -> val << " ->";
        if(!cur->next) cout << " " << "NULL";
        print(cur->next);
    }

    int countNODES(NODE*head){
        if(!head) return 0;
        NODE* cur = head;
        return 1 + countNODES(cur->next);
    }

    int MaxValNode(NODE* head){
        if(!head){
            throw runtime_error("List is empty. No MAX");
        }
        if(!head->next) return head->val;
        NODE* cur = head;
        int maxRest = MaxValNode(cur->next);
        return max(cur->val,maxRest);
    }

    bool searchNode(NODE* head, int target){
        if(!head) return false;
        NODE* cur = head;
        if(head->val == target) return true;
        return searchNode(cur->next,target);
    }

    NODE* mergeTwoLists(NODE* list1, NODE* list2){
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{list2->next = mergeTwoLists(list1,list2->next); return list2;}
    }

    NODE* swapPairs(NODE* head){
        if(!head || !head->next) return nullptr;
        NODE* second = head->next;
        head->next = swapPairs(second->next);
        second->next = head;
        return second;
    }
};




int main(){
    Solution sol;
    NODE* p1 = nullptr;
    //USE TRY - CATCH
    try{
        sol.MaxValNode(p1);
    } catch (const exception& e){
         cout << "Caught exception" << " " <<  e.what() << endl;}




    sol.InsertHead(p1,3);
    sol.InsertHead(p1,5);
    sol.InsertTail(p1,8);
    sol.InsertTail(p1,15);
    sol.print(p1); cout << endl;
    NODE* p2 = sol.swapPairs(p1);
    sol.print(p2);


    /*
    cout << endl << sol.countNODES(p1) << endl;
    cout << sol.MaxValNode(p1);    
*/

}