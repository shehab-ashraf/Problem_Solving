class MyCircularQueue {

    int *queue;
    int front , rear;
    int size , Maxsize;
    
public:
    MyCircularQueue(int k) {
        queue = new int[k];
        front = 0;
        rear = -1;
        Maxsize = k;
        size = 0;
    }
    
    // O(1) time | O(1) space
    bool enQueue(int value) {
        if(size < Maxsize){
            rear = (rear+1) % Maxsize;
            queue[rear] = value;
            size++;
            return true;
        }
        return false;
    }
    
    // O(1) time | O(1) space
    bool deQueue() {
        if(size > 0 ){
            front = (front+1) % Maxsize;
            size--;
            return true;
        }
        return false; 
    }
    
    // O(1) time | O(1) space
    int Front() {
        if(size > 0){
            return queue[front];
        }
        return -1;
    }
    
    // O(1) time | O(1) space
    int Rear() {
        if(size > 0){
             return queue[rear];
        }
        return -1;
    }
    
    // O(1) time | O(1) space
    bool isEmpty() {
        return size == 0;
    }
    
    // O(1) time | O(1) space
    bool isFull() {
        return size == Maxsize;
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
