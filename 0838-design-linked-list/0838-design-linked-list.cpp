struct node{
    int val;
    node*next;
    node(int val){
        this->val=val;
        next = nullptr;
    }
};
class MyLinkedList {
private:
    node *root;
public:
    MyLinkedList() {
        root = nullptr;
    }
    
    int get(int index) {
        int ans = -1;
        node *ptr = root;
        int c = 0;
        while(ptr){
            if(c==index)return ptr->val;
            c++;
            ptr = ptr->next;
        }
        return ans;
    }
    
    void addAtHead(int val) {
        node* n = new node(val);
        n->next = root;
        root = n;
    }
    
    void addAtTail(int val) {
        node*ptr = root,*prev=nullptr;
        if(!root){
        root = new node(val);
        return;
        }
        while(ptr){
            prev=ptr;
            ptr = ptr->next;
        }
        prev->next = new node(val);
    }
    
    void addAtIndex(int index, int val) {
        node *ptr = root,*pre=nullptr;
        if(index==0){
            addAtHead(val);
            return;
        }
        int c = 0;
        while(ptr){
            if(c==index){
                pre->next = new node(val);
                pre->next->next = ptr;
                return;
            }
            c++;
            pre = ptr;
            ptr = ptr->next;
        }
        if(c==index)pre->next = new node(val);
    }
    
    void deleteAtIndex(int index) {
        node *ptr = root,*pre=nullptr;
        if(index==0){
            root=root->next;
            return;
        }
        int c = 0;
        while(ptr){
            if(c==index){
                pre->next = ptr->next;
                return;
            }
            c++;
            pre = ptr;
            ptr = ptr->next;
        }
        
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