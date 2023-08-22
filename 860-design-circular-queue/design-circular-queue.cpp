class MyCircularQueue {
public:
    // Array -> Queue
    vector<int>q;
    // Size-> Number of Element
    int size;
    // Two Pointers
    int front,rear;
    // Constructor
    MyCircularQueue(int k) {
        // Initially there is No Element so size is 0
        size=0;
        // Fill the Array with -1
        for(int i=0;i<k;i++)
        q.push_back(-1);
        // Initially Front & Rear will be at First Index
        front=0;
        rear=0;
    }
    
    bool enQueue(int value) {

        if(isFull())
        return false;

        // Special Case -> Fisrt Element Push 
        if(isEmpty())
        {
            // Make both front & rear as 0
            front=rear=0;
            // Push the Element into rear
            q[rear]=value;
            // Increment size of Queue
            size++;
            return true;
        }
        // Normal Case
        // 1.Increment Rear
        rear++;
        // **Circular Property
        rear=rear % q.size();
        // 2.Push the Value in Rear 
        q[rear]=value;
        // Increment Size as Element Pushed
        size++;
        return true;
    }
    
    bool deQueue() {

        if(isEmpty())
        return false;

        // 1.Pop the Element 
        q[front]=-1;
        // 2.Increment Front Value
        front++;
        // Circular Property
        front=front % q.size();
        // Decrement SIze of Queue as Element was Poped Out
        size--;
        return true;
    }
    
    int Front() {
        // If Queue is Empty
        if(isEmpty())
        return -1;

        return q[front];
    }
    
    int Rear() {
        // If Queue is Empty
        if(isEmpty())
        return -1;

        return q[rear];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return q.size()==size;
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