#include <iostream>
using std::cin,std::cout;
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
    virtual ~Cache(){
        mp = head;
        Node* temp;
        while(mp->key != tail->key){
            temp = mp;
            mp = mp->next;
            delete mp;
        }
        delete tail;
    }
};

class LRUCache:public Cache{
    private:
    Node* key_check(int _key){
        if(head != nullptr){
            mp = head;
            while(mp != nullptr){
                if(mp->key == _key){
                    return mp;
                }
                mp = mp->next;
            }
        }
        return nullptr;
    }

    void move_front(int value){
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
        if(key <= 2000) {
            key_check(key);
            if (mp != nullptr) {
                if (head->key != mp->key) {
                    move_front(mp->value);
                }
                return mp->value;
            }
        }
        return -1;
    }

    void set(int key, int value) override {
        if (key <= 2000 && value <= 2000) {
            key_check(key);
            if (mp != nullptr) {
                move_front(value);
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

    void show(){
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
    int N;
    size_t M;
    char command[20];
    int key,value=0;
    cin>>N>>M;
    LRUCache* cache = new LRUCache(M);

    while(N != 0){
        cin>>command>>key;
        if(strcmp(command,"get") == 0){
            cache->get(key);
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
