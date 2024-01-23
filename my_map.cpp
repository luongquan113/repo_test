#include<iostream>
using namespace std;



template <class K, class V>
class Unordered_Map {
private:
    const size_t cap = 10;
    struct node_t{
        K key;
        V value;
        node_t * next;
        //node_t(V ke, V va) : key(ke), value(va), next(NULL) { }
    };
    node_t ** head_table;
    
public:
    Unordered_Map() {
        head_table = new node_t*[cap];
        for (size_t i = 0; i < cap; i++) {
            head_table[i] = NULL;
        }
    }
    ~Unordered_Map(){
        for (size_t i = 0; i < cap; i++){
            node_t * temp = head_table[i];
            while(temp != NULL){
                node_t * pre = temp;
                temp = temp->next;
                delete pre;
                cout << " ? ";
            }
        }
        delete[] head_table;
    }
    void insert_back(K key, V value){
        size_t index = static_cast<size_t>(key) % cap;
        node_t * new_node = new node_t{key, value, NULL};
        if (head_table[index] == NULL){
            head_table[index] = new_node;
        }
        else{
            bool check_key = false;
            node_t * temp = head_table[index];
            while (temp->next != NULL)
            {
                if (temp->key == key){
                    check_key = true;
                    break;
                }
                temp = temp->next;
            }
            if ( (temp->key == key) || (check_key == true) ){
                temp->value = value;
                delete new_node;
            }
            else{
                temp->next = new_node;
            }
        }
    }
    void insert_front(K key, V value){
        size_t index = static_cast<size_t>(key) % cap;
        node_t * new_node = new node_t{key, value, NULL};
        node_t * temp = head_table[index];
        // check if key already exists
        while (temp != NULL){
            if (temp->key == key){
                temp->value = value;
                delete new_node;
                return;
            }
            temp = temp->next;
        }
        new_node->next = head_table[index];
        head_table[index] = new_node;
    }
    void print(){
        cout << "List: ";
        for (size_t i = 0; i < cap; i++){
            node_t * temp = head_table[i];   

            while(temp != NULL){
                cout << temp->key << "-" << temp->value << endl;
                temp = temp->next;
            }
        }
    }
};

//Map
template<class key_t, class value_t>
class Map{
private:
    struct nodemap_t{
        key_t key;
        value_t value;
        struct nodemap_t * left;
        struct nodemap_t * right;
    };
    nodemap_t * root;
    nodemap_t * insert_node(nodemap_t * tmp, key_t key, value_t value){
        if (tmp == NULL) {
            nodemap_t * temp = new nodemap_t;
            temp->key = key;
            temp->value = value;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        if (key < tmp->key) {
            tmp->left = insert_node(tmp->left, key, value);
        } else if (key > tmp->key) {
            tmp->right = insert_node(tmp->right, key, value);
        } else {
            tmp->value = value;
        }
        return tmp;
    }
    void print_node(nodemap_t * node)
    {
        if (node != NULL)
        {
            print_node(node->left);
            cout << node->key << "-" << node->value << " ";
            print_node(node->right);
        }
    }
    size_t count_node(nodemap_t * node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + count_node(node->left) + count_node(node->right);
    }
public:
    Map() : root(NULL) { }
    ~Map() { }
    void insert(key_t key, value_t value){
        root = insert_node(root, key, value);
    }
    size_t count(){
        return count_node(root);
    }
    void print()
    {
        cout << "\nData: ";
        print_node(root);
    }
};

//Set
template<class int_t>
class Set{
private:
    struct node_t{
        int_t item;
        node_t * left;
        node_t * right;
    };
    node_t * root;
    size_t size;
    node_t * make_node(int_t x){
        node_t * new_node = new node_t;
        new_node->item = x;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    void print_node(node_t * node)
    {
        if (node != NULL)
        {
            print_node(node->left);
            cout << node->item << " ";
            print_node(node->right);
        }
    }
    size_t count_node(node_t * node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + count_node(node->left) + count_node(node->right);
    }
    void delete_node(node_t * node){
        if (node){
            delete_node(node->left);
            delete_node(node->right);
            cout << " ?";
            delete node;
        }
    }
public:
    Set() : root(NULL), size(0) { }
    ~Set(){
        //delete[] data;
        delete_node(root);
    }
    void destroy(){
        delete_node(root);
        root = NULL;
    }
    void insert(const int_t & x){
        if (root != NULL){
            node_t *temp = root;
            while(temp != NULL){
                if (x > temp->item){
                    if (temp->right == NULL){
                        temp->right = make_node(x);
                        size++;
                    }
                    temp = temp->right;
                }
                else if (x < temp->item){
                    if (temp->left == NULL){
                        temp->left = make_node(x);
                        size++;
                    }
                    temp = temp->left;
                }
                else{
                    temp = NULL;
                }
            }
        }
        else{
            root = make_node(x);
            size++;
        }
    }
    bool search(const int_t & x){
        bool check = false;
        if (root != NULL) {
            node_t * temp = root;
            while(temp != NULL){
                if (x < temp->data){
                    temp = temp->left;
                }
                else if (x > temp->data){
                    temp = temp->right;
                }
                else{
                    check = true;
                    break;
                }
            }
        }
        else{
            check = false;
        }
        return check;
    }
    size_t getSize(){
        return size;
    }
    size_t count(){
        return count_node(root);
    }
    void print()
    {
        cout << "\nData: ";
        print_node(root);
    }
};


int main(){
    cout << "a";
    return 1;
}