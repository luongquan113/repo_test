#include<iostream>
using namespace std;

template <typename uint_t> struct node{
    uint_t item;
    struct node * next;
};

//stack
template <typename int_t> class Stack{
private:
    node<int_t> * head;
    size_t len;
public:
    Stack() : len(0) {
        head = NULL;
    }
    Stack(int_t x) : len(1) {
        node<int_t> * tmp = new node<int_t>;
        tmp->item = x;
        tmp->next = NULL;
        head = tmp;
    }
    ~Stack(){
        node<int_t> * tmp = head;
        node<int_t> * pre = tmp;
        while(tmp != NULL){
            pre = tmp;
            tmp = tmp->next;
            delete pre;
            cout << "huy\t";
        }
    }
    Stack(const Stack & obj){
        node<int_t> * temp_obj = obj.head;
        this->head = NULL;
        while(temp_obj != NULL){
            push(temp_obj->item);
            temp_obj = temp_obj->next;
        }
    }
    void push(const int_t & x){
        node<int_t> * temp = new node<int_t>;
        temp->item = x;
        temp->next = head;
        head = temp;
        len++;
    }
    void pop(){
        if (head != NULL){
            node<int_t> * temp = head;
            head = head->next;
            delete temp;
            len--;
        }
    }
    int_t top(){
        return head->item;
    }
    size_t size(){
        return len;
    }
    bool empty(){
        return (len == 0);
    }
};

//link list
template <typename uint_t> class List{
private:
    node<uint_t> * head;
public:
    List() { head = NULL; }
    List(uint_t x) { 
        node<uint_t> * temp = new node<uint_t>;
        temp->item = x;
        temp->next = NULL;
        head = temp;
    }
    List(const List & obj){
        node<uint_t> * temp_obj = obj.head;
        this->head = NULL;
        while(temp_obj != NULL){
            push_back(temp_obj->item);
            temp_obj = temp_obj->next;
        }
    }
    
    void push_front(uint_t x){
        node<uint_t> * temp = new node<uint_t>;
        temp->item = x;
        temp->next = head;
        head = temp;
    }
    void push_back(uint_t x){
        node<uint_t> * temp = new node<uint_t>;
        node<uint_t> * t = head;
        temp->item = x;
        temp->next = NULL;
        if (head == NULL){
            head = temp;
        }
        else{
            while(t->next != NULL){
                t = t->next;
            }
            t->next = temp;
        }
    }
    void pop_front(){
        if (head){
            node<uint_t> * temp = head;
            head = head->next;
            delete temp;
        }
    }
    void remove(uint_t x){
        node<uint_t> * tmp = head;
        while(tmp){
            if(tmp->item == x){
                //
            }
        }
    }
    /*uint_t * data{
        return head;
    }*/
    uint_t front(){
        return head->item;
    }
    bool empty(){
        return (!head);
    }
    size_t size(){
        int count = 0;
        node<uint_t> * temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    void print(){
        node<uint_t> * temp = head;
        cout << "List: ";
        if (head){
            while(temp != NULL){
                cout << temp->item << " ";
                temp = temp->next;
            }
        }
        else{
            cout << "empty\n";
        }
    }
    ~List(){
        node<uint_t> * tmp = head;
        node<uint_t> * pre = tmp;
        while(tmp != NULL){
            pre = tmp;
            tmp = tmp->next;
            delete pre;
            cout << "huy\t";
        }
    }
};

//vector
template <typename uint_t> 
class Test
{
private:
    size_t size;
    size_t cap;
    uint_t * data;
public:
    Test(size_t x = 5) : size(0), cap(x) {
        data = new uint_t[x];
    }
    ~Test(){
        delete[] data;
    }
    Test(const Test & obj){
        this->size = obj.size;
        this->cap = obj.cap;
        this->data = new uint_t[this->cap];
        for (int i = 0; i < this->size; i++){
            this->data[i] = obj.data[i];
        }
    }
    size_t getCap(){
        return cap;
    }
    uint_t & operator [] (int pos) {
        return data[pos];
    }
    uint_t at(int pos) {
        return data[pos];
    }
    void push_back(uint_t x){
        if (size >= cap){
            uint_t * old = data;
            cap += cap;
            data = new uint_t[cap];
            for (int i = 0; i < size; i++){
                data[i] = old[i];
            }
            delete[] old;
            cout << " add ";
        }
        data[size] = x;
        size++;
    }
    void insert(int pos, uint_t x){
        if (size >= cap){
            uint_t * old = data;
            cap += cap;
            data = new uint_t[cap];
            for (int i = 0; i < size; i++){
                data[i] = old[i];
            }
            delete[] old;
        }
        for (int i = size; i > pos; i--){
            data[size] = data[size-1];
        }
        data[pos] = x;
        size++;
    }
    bool empty(){
        return (size == 0);
    }
    void clear(){
        size = 0;
    }
    void print(){
        cout << "Vector: ";
        if (size > 0){
            for (int i = 0; i < size; i++)
            {
                cout << data[i] << " ";
            }
            
        }
        else{
            cout << "empty\n";
        }
    }
    size_t Size(){
        return size;
    }
    void sort(){
        for (int i = 0; i < size-1; i++){
            for (int j = i+1; j < size; j++){
                if (data[i] > data[j]){
                    swap(data[i], data[j]);
                }
            }
        }
    }
    void pop_back(){
        if( size > 0){
            size--;
        }
    }
    uint_t front(){
        return data[0];
    }
};



int main(){
    cout << "a";
    return 1;
}