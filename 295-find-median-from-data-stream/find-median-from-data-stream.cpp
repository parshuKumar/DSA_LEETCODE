class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        min.push(num);
        max.push(min.top());
        min.pop();

        if(size % 2 == 1){
            int value = max.top();
            max.pop();
            min.push(value);
        }
    }
    
    double findMedian() {
        if(size % 2 == 1){
            return min.top();
        }

        return ((min.top() + max.top()) / 2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */