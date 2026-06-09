#include <iostream>
#include <vector>
using namespace std;
struct NODE{
    int data;
    NODE* next;
    NODE* prev;
};
NODE* createNODE(int val){
    NODE* newNODE = new NODE;
    newNODE->data = val;
    newNODE->next = nullptr;
    newNODE->prev = nullptr;
    return newNODE;
}
class MyLinkedList{
    //BECAUSE THIS IS A DLL, WE NEED TWO EXTRA ATTRIBUTES: HEAD, TAIL. SIZE FOR FLEXIBLE
    private:
    NODE* head;
    NODE* tail;
    int size;
    //THANKS TO THIS, WE CAN REUSE HEAD AND TAIL WITHOUT ADD THEM FOR EVERY FUNCTION
    public:
    //CONSTRUCTOR FUNCTION
    MyLinkedList(): head(nullptr),tail(nullptr),size(0){};

    int getIndex(int index){
        if(index < 0 || index >= size) return -1; // MAX INDEX = SIZE - 1
        NODE* current;
        if(index < size / 2){
            current = head;
            for(int i = 0; i < index; i++) current = current->next;
            }
            else{
                current = tail;
            for(int i = size - 1; i > index; i--) current = current->prev;
            }
            return current->data;
        }
    
        void InsertHead(int val){
            NODE* newNODE = createNODE(val); //PREV AND NEXT FOR NEWNODE IS NULL
            if(!head){ head = tail = newNODE;
                size++;
                return;}
            newNODE->next = head;
            head->prev = newNODE;
            head = newNODE; // re-assign because of void function 
            size++;
        }
        void InsertTail(int val){
            NODE* newNODE = createNODE(val);
            if(!head) {head = tail = newNODE;
                size++;
                return;
            }
            tail->next = newNODE;
            newNODE->prev = tail;
            tail = newNODE;
            size++;
        }
        void DeleteHead(){
            if(!head) return;
            if(!head->next){
                head = tail = nullptr;
                size--;
                return;
            }
            NODE* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            size--;
        }
        void DeleteTail(){
            if(!head) return;
            if(!head->next) {head = tail = nullptr;
                size--;
                return;
            }
            NODE* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
            size--;
        }
        void InsertAtPos(int val,int index){
            if(index < 0 || index > size) return;
            if(index == 0) {
                InsertHead(val); return;
            }
            if(index == size){
                InsertTail(val); return;
            }
            NODE* current;
            if(index < size / 2){
                current = head;
                for(int i = 0; i < index; i++){
                    current = current->next;
                }
            }
            else{
                current = tail;
                for(int i = size - 1; i > index; i--){
                    current = current->prev;
                }
            }
            NODE* newNODE = createNODE(val);
            current->prev->next = newNODE;
            newNODE->prev = current->prev;
            newNODE->next = current;
            current->prev = newNODE;
            size++;
            }
            void DeleteAtPos(int index){
                if(!head) return;
                if(index == 0) {
                    DeleteHead(); return;
                }
                if(index == size - 1){
                    DeleteTail(); return;
                }
                NODE* toDelete;
                if(index < size / 2){
                    toDelete = head;
                    for(int i = 0; i < index; i++){
                        toDelete = toDelete -> next; 
                    }
                }
                else{
                    toDelete = tail;
                    for(int i = size - 1; i > index; i--){
                        toDelete = toDelete->prev;
                    }
                }
                    toDelete -> prev -> next = toDelete->next;
                    toDelete -> next -> prev = toDelete -> prev;
                    delete toDelete;
                    size--;
                
            }
        
        void PrintForwardList(){
            if(size == 0) return;
            NODE* current = head;
            while(current) {
                if(current == head) cout << " nullptr ->";
                cout << " " << current->data << " ->";
                if(!current->next) cout << " nullptr";
                current = current->next;
        }

    }
         void PrintBackwardList(){
            if(size == 0) return;
            NODE* current = tail;
            while(current) {
                if(current == tail) cout << " nullptr ->";
                cout << " " << current->data << " ->";
                if(!current->prev) cout << " nullptr";
                current = current->prev;
        }
    }
      void clearList(){
            NODE* current = head;
            while(current){
                NODE* next = current->next;
                delete current;
                current = next;
            }
            head = tail = nullptr;
            size = 0;
        }    
        void createListFromArray(vector<int>&a){
            clearList();
            int n = a.size();
            if(n <= 0) return;
            head = createNODE(a[0]);
            tail = head;
            size = 1;
            for(int i = 1; i < n; i++){
                NODE* newNODE = createNODE(a[i]);
                tail->next = newNODE;
                newNODE->prev = tail;
                tail = newNODE;
                size++;
            }
        }
        void DeleteAllTarget(int target){
            if(!head) return;
            NODE* current = head;
            while(current){
                NODE* nextNODE = current->next;
                if(current->data == target){
                if(current->prev){
                    current->prev->next = current->next;
                }
                else head = current->next;
                if(current->next) current->next->prev = current->prev;
                else tail = current->prev;
                delete current;
                size--;
                }
                current = nextNODE;
                }    
        }
        void RemoveDuplicateSorted(){
            if(!head) return;
            NODE* curr = head;
            while(curr && curr->next){
                if(curr->data == curr->next->data){
                    NODE* dup = curr->next;
                    curr->next = dup->next;
                    if(dup->next) dup->next->prev = curr;
                    else tail = curr;
                    delete dup;
                    size--;
                }
                else curr = curr->next;
            }
        }
        //REVERSE LL
        void ReverseLinkedList(){
            NODE* curr = head;
            NODE* temp = nullptr;
            while(curr){
                temp = curr->prev;
                curr->prev = curr->next;
                curr->next = temp;
                curr = curr->prev;
            }
            temp = head;
            head = tail;
            tail = temp;
        }

        //CHECK PALINDROME LL
        bool CheckPalindrome(){
            if(!head && !head->next) return true;
            NODE* left = head;
            NODE* right = tail;
            while(left != right && left->prev != right){
                if(left->data != right->data){
                    return false;
                }
                left = left->next;
                right = right->prev;
            }
            return true;
        }

        //PAIRS TWO SUM ON LL - https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1

        vector<vector<int>> PairsTwoSum(int target){
            vector<vector<int>> result;
            if(!head) return result;
            NODE* left = head;
            NODE* right = tail;
            while(left != right && left->prev != right){
                int sum = left->data + right->data;
                if(sum == target){
                    result.push_back({left->data,right->data});
                    left = left->next;
                    right = right ->prev;
                }
                else if(sum < target){
                    left = left->next;
                }
                else right = right->prev;
            }
            return result;
        }

};





int main(){
    MyLinkedList mll;
    mll.InsertHead(20);
    mll.InsertTail(10);
    mll.InsertTail(15);
    mll.InsertTail(25);
    mll.InsertAtPos(30,1);
    //mll.DeleteHead();
    mll.DeleteAtPos(4);
    vector<int>arr = {1,2,4,5,6,8,9};
    mll.createListFromArray(arr);
    //mll.RemoveDuplicateSorted();
    //mll.ReverseLinkedList();
    //mll.DeleteAllTarget(2);
    //cout <<mll.CheckPalindrome() << endl;
    vector<vector<int>> pairs = mll.PairsTwoSum(7);
    for (auto& p : pairs) {
    cout << "(" << p[0] << ", " << p[1] << ")" << endl;
}
    //mll.PrintForwardList();
    //cout << endl;
    //mll.PrintBackwardList();
    //mll.clearList();
    //mll.PrintForwardList();
}