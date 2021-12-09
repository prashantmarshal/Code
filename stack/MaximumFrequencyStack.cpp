class FreqStack {
public:
    unordered_map<int, stack<int>> elements;
    unordered_map<int, int> freq;
    int maxFreq;

    FreqStack() {    
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++; // update frequency of the element
        elements[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
    }
    
    int pop() {
        int r = elements[maxFreq].pop();
        freq[val]--;
        if(elements[maxFreq].size() == 0) maxFreq--;
        return r;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */