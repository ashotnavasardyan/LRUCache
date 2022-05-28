#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::strcmp;

class Node{
public:
    int key;
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int _key,int _value):key(_key),value(_value){}
};

class Cache{
protected:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* mp = nullptr;
    size_t cp;
    size_t sz = 0;
public:
    explicit Cache(size_t M){
        cp = (M > 1000)?1000:M;
    }
    virtual int get(int key) = 0;
    virtual void set(int key, int value) = 0;
    virtual void key_check(int _key) = 0;
    virtual void move_front(int value) = 0;
    virtual void show(){ cout<<"Show buffer";}

    virtual ~Cache(){
        mp = head;
        Node* temp;
        while(mp->key != tail->key){
            temp = mp;
            mp = mp->next;
            delete temp;
        }
        delete tail;
    }
};

class LRUCache:public Cache{
private:
    void key_check(int _key) override {
        if(head != nullptr){
            mp = head;
            while(mp != nullptr){
                if(mp->key == _key){
                    return;
                }
                mp = mp->next;
            }
        }
    }

    void move_front(int value) override {
        if(mp->key != tail->key){
            mp->next->prev = mp->prev;
        }else{
            if(mp->key == head->key){
                mp->value = value;
                return;
            }else {
                tail = mp->prev;
            }
        }
        mp->prev->next = mp->next;
        head->prev = mp;
        mp->next = head;
        mp->prev = nullptr;
        head = mp;
    }

public:

    explicit LRUCache(size_t M): Cache(M) {}

    int get(int key) override {
        if(1 <= key && key <= 2000) {
            key_check(key);
            if (mp != nullptr) {
                if (head->key != mp->key) {
                    move_front(mp->value);
                    return mp->value;
                }else {
                    return head->value;
                }

            }
        }
        return -1;
    }

    void set(int key, int value) override {
        if (1 <= key && 1 <= value && key <= 2000 && value <= 2000) {
            key_check(key);
            if (mp != nullptr) {
                if(mp->key != head->key){
                    move_front(value);
                }
                head->value = value;
            } else {
                if (sz == cp) {
                    --sz;
                    if (tail->key == head->key) {
                        delete head;
                        head = nullptr;
                        tail = nullptr;
                    } else {
                        tail = tail->prev;
                        delete tail->next;
                        tail->next = nullptr;
                    }
                }
                Node *new_node = new Node(key, value);
                if (head == nullptr) {
                    tail = new_node;
                } else {
                    head->prev = new_node;
                }
                new_node->next = head;
                head = new_node;
                ++sz;
            }
        }else{
            cout<<"Your key or value is too big.(Max: 2000)"<<"\n";
            return;
        }
    }

    void show() override {
        if(head != nullptr){
            mp = head;
            while(mp != nullptr){
                cout<<mp->key<<" ";
                mp = mp->next;
            }
            cout<<"\n";
            mp = head;
            while(mp != nullptr){
                cout<<mp->value<<" ";
                mp = mp->next;
            }
            cout<<"\n";
            cout<<"-----------------------"<<"\n";
        }else{
            cout<<"Empty"<<"\n";
        }

    }
};

int main() {
    size_t M;
    char command[20];
    int N,key,value=0,result;
    cin>>N>>M;
    LRUCache* test = new LRUCache(M);
    Cache* cache = test;
    while(N != 0){
        cin>>command>>key;
        if(strcmp(command,"get") == 0){
            result = cache->get(key);
            cout<<"("<<result<<")"<<"\n";
        }else if((strcmp(command,"set") == 0)){
            cin>>value;
            cache->set(key,value);
        }
        cache->show();
        --N;
    }

    delete cache;
    return 0;
}
