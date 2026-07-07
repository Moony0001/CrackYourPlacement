class MedianFinder {
public:
    int cnt;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        cnt = 0;
    }
    
    void addNum(int num) {
        if(cnt==0){
            maxheap.push(num);
        }else{
            if(maxheap.top()>num){
                maxheap.push(num);
            }else{
                minheap.push(num);
            }
        }
        
        cnt++;
    }
    
    double findMedian() {
        int mid = (cnt+1)/2;
        if(maxheap.size()>mid){
            while(maxheap.size()>mid){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }else if(maxheap.size()<mid){
            while(maxheap.size()<mid){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        double ans = 0;
        if(cnt&1){
            ans = maxheap.top();
        }else{
            ans = (maxheap.top()+minheap.top())/2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */