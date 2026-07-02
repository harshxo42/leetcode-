class FreqStack {
private:
    unordered_map<int, int> freq;        // value -> frequency
    unordered_map<int, stack<int>> freqStack; // frequency -> stack of values
    int maxFreq = 0;
    
public:
    FreqStack() {
        // Constructor
    }
    
    void push(int val) {
        // Increment frequency
        int f = ++freq[val];
        
        // Update max frequency
        maxFreq = max(maxFreq, f);
        
        // Push to the stack for this frequency
        freqStack[f].push(val);
    }
    
    int pop() {
        // Get the most frequent element (closest to top)
        int val = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        
        // Decrement frequency
        freq[val]--;
        
        // If no more elements at this frequency, decrement maxFreq
        if (freqStack[maxFreq].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};
