class MyCircularQueue {
    vector<int>a;
    int first, last, size;
public:
    MyCircularQueue(int k) {
        size = k;
        a = vector<int>(size);
        first = last = -1;
    }   
    
    bool enQueue(int value) {
        if(isFull())return false;
        if(first == -1){
            first = 0;
        }
        last = (last + 1) % size;
        a[last] = value;
        return true;
    }
    
    bool deQueue() {
        if(first == last){
            if(first == -1)return false;
            else{
                first = last = -1;
                return true;
            }
        }
        else{
            first = (first + 1) % size;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty())return -1;
        return a[first];
    }
    
    int Rear() {
        if(isEmpty())return -1;
        return a[last];
    }
    
    bool isEmpty() {
        if(first == -1)return true;
        else return false;
    }
    
    bool isFull() {
        if(((last + 1) % size) == first){
            return true;
        }
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */