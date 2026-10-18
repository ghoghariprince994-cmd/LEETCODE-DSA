class MyCircularQueue {
public:
    int x;
   vector<int> arr;
    MyCircularQueue(int k) {
        arr.resize(k);
        x=k;
    }
  int count = 0;
   
    int i=0;
    int j=0;
    bool enQueue(int value) {
        if(count<x)
         {
            arr[j]=value;
          j = (j + 1) % x;
         count++;
            return true;
         } 
         return false;
         
    }
    
    bool deQueue() {
        if(count>0)
        {
            arr[i]=0;
            i = (i + 1) % x;
            count--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(count==0)return -1;
        return arr[i];
    }
    
    int Rear() {
        if(count==0)return -1;
        return arr[(j - 1 + x) % x];
    }
    
    bool isEmpty() {
       return count == 0;
}
    
    
    bool isFull() {
         return count == x;
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