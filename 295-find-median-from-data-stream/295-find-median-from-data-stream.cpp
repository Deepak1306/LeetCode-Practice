class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
        
    }
    void balance(){
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0){
            maxHeap.push(num);
        }
        
       else if(num>maxHeap.top()){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        
        balance();
        
        
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (double)(maxHeap.top()+minHeap.top())/2;
        }else{
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */