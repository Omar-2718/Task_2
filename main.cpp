#include <iostream>
#include "assert.h"
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data) : data(data){};

};
class Vector{
private:
    int *arr = {nullptr};
    int capacity{};
    int size {0};
public:
    Vector(int size) : size(size){
        if(size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity];
    }
    ~Vector(){
        delete[] arr;
        arr = nullptr;
    }
    int get_size(){
        return size;
    }
    int get(int idx){
        assert(idx >= 0 && idx < size);
        return arr[idx];
    }
    void set(int idx,int val){
        assert(idx >= 0 && idx < size);
        arr[idx] = val;
    }
    void print(){
        for(int i =0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
//    void insert(int val,int idx){
//        int *temp = new int [size - idx + 1];
//        temp[0] = val;
//        for(int i = idx;i<size;i++){
//            temp[i - idx + 1] = arr[i];
//        }
//        this->push_back(-1);
//        // 0 1 2 3 4 5
//        for(int i = idx;i<size;i++){
//            arr[i] = temp[i - idx];
//        }
//    }

    void insert(int idx, int value) {
        assert(0 <= idx && idx < size);

        // we can't add any more
        if (size == capacity)
            expand_capacity();

        // Shift all the data to right first

        for(int p = size-1; p >= idx; --p)
            arr[p+1] = arr[p];

        arr[idx] = value;
        ++size;

        // Common mistake to iterate from begin to end
        // the whole array right array will be arr[idx]
        //for (int p = idx; p < size; ++p)
    }
    int pop(int idx){
        assert(0 <= idx && idx < size);
        int val = arr[idx];
        for(int i =idx;i<size-1;i++){
            arr[i] = arr[i+1];
        }
        size--;
        // 1 2 3 4 5
        return val;


    }
    int find(int value){
        for(int i =0;i<size;i++){
            if(arr[i] == value)
                return i;
        }
        return -1;
    }
    int find_transposition(int target){
        int pos = find(target);
        if(pos != -1){
            if(pos >= 1) {
                int temp = arr[pos - 1];
                arr[pos - 1] = arr[pos];
                arr[pos] = temp;
            }
            pos--;
        }
        return pos;
    }
    void expand_capacity(){
        capacity *= 2;
        //cout << "expanded\n";
        int *temp = new int [capacity];
        for(int i = 0;i<size;i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    void push_back(int val){

        if(size == capacity){
            expand_capacity();
        }
        arr[size++] = val;

    }
    void right_rotate(int time){
        for(int j = 0;j<(time % size);j++) {
            int last = arr[size - 1];
            for (int i = size - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = last;
        }
    }
    void left_rotate(int time) {
        for (int j = 0; j < (time % size); j++) {
            int first = arr[0];
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[size - 1] = first;
        }
    }
};
class LinkedList{
private:
    Node* head{};
    Node* tail{};
    int length =0;
public:
    ~LinkedList(){
        while (head){
            Node* curr = head->next;
            delete head;
            head = curr;
        }
    }
    Node* get_nth(int t){
        int c = 0;
        for(Node* i = head;i;i = i->next){
            if(t == ++c)
                return i;
        }
        return nullptr;
    }
    Node* get_nth_from_back(int t){
        // 1 2 3 4 5 6 len = 6
        // 6 5 4 3 2 1
        // length - nth + 1 = nth from back
        return get_nth(length - t + 1);
    }
    Node* find(int target){
        return find(head,target);
    }
    Node* find(Node* tempHead,int target){
        if(tempHead == nullptr)
            return nullptr;
        if(tempHead->data == target)
            return tempHead;

        return find(tempHead->next,target);
    }
    int search(int t){
        int c = 0;
        for(Node* i = head;i;i = i->next){
            if(t == i->data)
                return c;
            c++;
        }
        return -1;
    }
    void print(){
        Node* tempHead = head;
        for(Node *i = tempHead; i != nullptr;i = i->next){
            cout << i->data << " ";
        }
        cout << "\n";
    }
    void print1(){
        Node* tempHead = head;
        while (tempHead != nullptr){
            cout << tempHead->data << " ";
            tempHead = tempHead->next;
        }
        cout << "\n";
    }
    void print2(){
        print2(head);
    }
    void print2(Node* tempHead){
        if(tempHead == nullptr) {
            cout <<"\n";
            return;
        }
        cout << tempHead->data << " ";
        print2(tempHead->next);
    }
    void insert_end(int val){
        length++;
        Node* t = new Node(val);
        if(head == nullptr && tail == nullptr) {
            head = tail = t;
            t->next = nullptr;
        }
        {
            tail->next = t;
            tail = t;
            tail->next = nullptr;
        }

    }
    void insert_front(int val){
        length++;
        Node* t = new Node(val);
        if(head == nullptr && tail == nullptr) {
            head = tail = t;
            t->next = nullptr;
        } else {
            t->next = head;
            head = t;
        }


    }
    void delete_front(){
        assert(length !=0);
        if(length == 1)
            tail = nullptr;
        length--;
        Node* t = head;
        head = head->next;
        delete t;
    }
    int search_improved(int t){
        int idx =0;
        Node* prev = nullptr;
        for(Node* cur = head;cur;cur = cur->next,idx++){
            if(cur->data == t){
                if(!prev)
                    return idx;
                swap(cur->data,prev->data);
                return idx - 1;
            }
            prev = cur;
        }
        return -1;
    }
    bool is_same(LinkedList ls){
        if(ls.length == length){
            for(int i = 0;i<length;i++){
                if(get_nth(i+1)->data != ls.get_nth(i+1)->data)
                    return false;
            }
            return true;
        }
        else
            return false;
    }
    bool is_same2(LinkedList ls){
        int c = 1;
        // 1 2 3 4
        // 1 2 3 4 5 6
        for(Node* temp = head;temp;temp = temp->next,c++) {
                if(ls.get_nth(c) == nullptr || temp->data != ls.get_nth(c)->data) {
                    return false;
                }

        }
        return ls.get_nth(c) == nullptr;

    }
    void debug(){
        if(length == 0) {
            assert(head == nullptr);
            assert(tail == nullptr);
        }
        else{
            assert(head != nullptr);
            assert(tail != nullptr);
            if(length == 1){
                assert(head == tail);
            }
            else{
                assert(head != tail);
            }
            assert(!tail->next);
        }
        int len = 0;
        for(Node* cur = head;cur;cur=cur->next,len++)
            assert(len <10000);
        assert(len == length);

    }
    void delete_first(){
        if(head){
            length--;
            Node* temp = head;
            head = head->next;
            delete temp;
            if(!head)
                tail = nullptr;
        }
    }
    void delete_last(){
        if(length <= 1) {
            delete_first();
            return;
        }
        Node* prev = get_nth(length - 1);
        delete tail;
        length--;
        tail = prev;
        tail->next = nullptr;
    }
    void delete_nth(int n){
        assert(n > 0 && n <= length);
        if(n == 1){
            delete_first();
            return;
        }
        else if (n == length){
            delete_last();
            return;
        }
        else{
            Node* prev = get_nth(n-1);
            Node* nth = prev->next;
            prev->next = nth->next;
            delete nth;
            length--;
        }
    }
};
int main() {

/*
    Node a = Node(23);
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    Node* node4 = new Node(40);

    LinkedList ls;
    ls.debug();
    ls.insert_end(23);
    ls.debug();
    ls.insert_end(10);
    ls.debug();
    ls.insert_end(20);
    ls.insert_end(30);
    ls.insert_end(40);
    ls.debug();

    ls.print2();
    ls.debug();

    cout << ls.search_improved(30) << "\n";
    ls.debug();
    ls.print2();
    cout << ls.search_improved(23) << "\n";
    ls.debug();
    ls.print2();
    cout << ls.search_improved(230) << "\n";
    ls.print2();
    ls.find(10);
    ls.debug();
    ls.insert_front(1009);
    ls.delete_front();
    ls.print2();
    cout<<"NRTE";
    cout << "sear : " << ls.search(1009) << "\n";
    ls.debug();
    ls.delete_front();
    ls.print2();
    ls.delete_front();
    ls.print2();

    ls.delete_front();
    ls.print2();

    ls.delete_front();
    ls.print2();

    ls.delete_front();

    ls.insert_end(30);
    ls.insert_end(34);
    ls.insert_front(10);
    ls.print2();
    cout << ls.get_nth_from_back(3)->data;

*/
    LinkedList ls,ls1;
    ls.insert_end(10);
    ls1.insert_front(107);
    ls.print2();
    ls1.print2();

    cout << ls.is_same2(ls1);



    return 0;
}
