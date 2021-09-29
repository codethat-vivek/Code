// Question Link - https://leetcode.com/problems/design-linked-list/

// Solution - 

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    vector<int>v;
    int size;
    MyLinkedList() {
        v.resize(2500);
        for(int i=0; i<2500; i++)
            v[i] = -1;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
        return v[index];
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(size == 0){
            v[0] = val;
            size++;
            return;
        }
        for(int i=size; i>0; i--)
            v[i] = v[i-1];
        v[0] = val;
        size++;        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        v[size] = val;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)
            return;
        if(index == size){
            v[size] = val;
            size++;
            return;
        }
        for(int i=size; i>index; i--)
            v[i] = v[i-1];
        v[index] = val; 
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        for(int i=index; i<size-1; i++)
            v[i] = v[i+1];
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


/*
Sample Test Case -> 
 ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get", "addAtHead", "addAtHead", "addAtHead", "addAtHead", "addAtHead", "addAtHead", "addAtHead","get","get","get","get","get","get","get","get","get","addAtTail","addAtTail","addAtTail","addAtTail","get","get","get","get","get","get","deleteAtIndex","deleteAtIndex","deleteAtIndex","get","get","get","get","get","deleteAtIndex","deleteAtIndex","deleteAtIndex","deleteAtIndex","get","get","get","addAtIndex", "get", "get", "addAtIndex","addAtIndex", "get", "get", "get", "get", "get", "addAtIndex","addAtIndex","addAtIndex","addAtIndex","get","get","get","get","get","get","get","get","get","get","get","get"]
[[],[1],[3],[1,2],[1],[1],[1], [123], [100], [2], [12], [34], [45], [232], [0], [1], [2], [3], [4], [5], [6], [7], [8], [235], [666], [333], [111], [9], [10], [11], [12], [13], [14], [0], [1], [2], [10], [11], [12], [13], [14], [10], [9], [8], [7], [6], [5], [4], [0, 88], [0], [7], [4, 489], [6, 623], [3], [4], [8], [9], [10], [9, 99], [10, 12], [11, 440], [14, 90], [0], [1], [2], [3], [4], [5], [6], [7], [8], [9], [10], [11]]
 

*/
