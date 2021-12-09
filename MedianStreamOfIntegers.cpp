class MedianFinder {
private:
    priority_queue <int, vector<int>, greater<int>> Right; // min_heap
    priority_queue <int, vector<int>> Left; // max_heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        // Push the first element to the Left heap.
        // Push an element to the Left heap if it is smaller than Left's top.
        if (Left.empty() || Left.top() > num) Left.push(num);
        else Right.push(num);

        // Rebalance
        if (Left.size() > Right.size() + 1) {
            Right.push(Left.top()); Left.pop();
        } else if (Right.size() > Left.size() + 1) {
            Left.push(Right.top()); Right.pop();
        }
    }
    
    double findMedian() {
        if(Left.size() == Right.size())
            return Left.empty() ? 0 : (Left.top() + Right.top())/2.0;
        else 
            return (Left.size() > Right.size()) ? Left.top() : Right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */