class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        major_stack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!major_stack.empty()) {
            minor_stack.push(major_stack.top());
            major_stack.pop();
        }

        minor_stack.pop();

        while (!minor_stack.empty()) {
            major_stack.push(minor_stack.top());
            minor_stack.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int element;
        while (!major_stack.empty()) {
            element = major_stack.top();
            major_stack.pop();
            minor_stack.push(element);
        }

        while (!minor_stack.empty()) {
            major_stack.push(minor_stack.top());
            minor_stack.pop();
        }
        return element;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return major_stack.empty();
    }
private:
    stack<int> major_stack;
    stack<int> minor_stack;
};
