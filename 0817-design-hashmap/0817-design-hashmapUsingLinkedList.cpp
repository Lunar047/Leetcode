struct node{
    int val,key;
    node*next;
    node(int key,int val){
        this->key = key;
        this->val=val;
        next = nullptr;
    }
};
class MyHashMap {
private:
    node* arr[1024];
public:
    MyHashMap() {
        for(int i=0;i<1024;i++)arr[i]=nullptr;
    }
    
    void put(int key, int value) {
        int i = key%1024;
        if(arr[i]==NULL){
            arr[i] = new node(key,value);
        }
        else{
            node *ptr = arr[i],*prev=NULL;
            while(ptr){
                if(ptr->key==key){
                    ptr->val = value;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = new node(key,value);
        }
    }
    
    int get(int key) {
        int i = key%1024;
        if(arr[i]==NULL)return -1;
        else{
            node *ptr = arr[i];
            while(ptr){ 
                if(ptr->key==key)return ptr->val;
                ptr = ptr->next;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int i = key%1024;
        if(arr[i]!=NULL){
            node *ptr = arr[i];
            while(ptr){
                if(ptr->key==key){
                    ptr->val = -1;
                }
                ptr = ptr->next;
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
