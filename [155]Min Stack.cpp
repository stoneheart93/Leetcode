//Design a stack that supports push, pop, top, and retrieving the minimum elemen
//t in constant time. 
//
// Implement the MinStack class: 
//
// 
// MinStack() initializes the stack object. 
// void push(val) pushes the element val onto the stack. 
// void pop() removes the element on the top of the stack. 
// int top() gets the top element of the stack. 
// int getMin() retrieves the minimum element in the stack. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]
//
//Output
//[null,null,null,null,-3,null,0,-2]
//
//Explanation
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin(); // return -3
//minStack.pop();
//minStack.top();    // return 0
//minStack.getMin(); // return -2
// 
//
// 
// Constraints: 
//
// 
// -231 <= val <= 231 - 1 
// Methods pop, top and getMin operations will always be called on non-empty sta
//cks. 
// At most 3 * 104 calls will be made to push, pop, top, and getMin. 
// 
// Related Topics Stack Design 
// 👍 5157 👎 481


//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
    stack<long> s;
    long min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val)
    {
        if(s.empty())
        {
            s.push((long)val);
            min = val;
        }
        else
        {
            if(val < min)
            {
                long prev_min = min;
                long curr_min = val;
                long encoded = 2*curr_min - prev_min;
                s.push(encoded);
                min = curr_min;
            }
            else
                s.push((long)val);
        }
    }
    
    void pop()
    {
        if(s.empty())
            return;
        else
        {
            long encoded = s.top();
            if(encoded < min)
            {
                long curr_min = min;
                long prev_min = 2*curr_min - encoded;
                min = prev_min;
            }
            s.pop();
        }
    }
    
    int top()
    {
        if(s.empty())
            return -1;
        else
        {
            long encoded = s.top();
            if(encoded < min)
                return min;
            else
                return encoded;
        }
    }
    
    int getMin()
    {
        return min;
    }
};

/*
curr_min < prev_min
curr_min - prev_min < 0
2 * curr_min - prev_min < curr_min
*/


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
