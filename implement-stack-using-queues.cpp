class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        Que.push(x);
        len = Que.size();
        for (int i = 0; i < len - 1; ++i) {
            Que.push(Que.front());
            Que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Que.pop();
    }

    // Get the top element.
    int top() {
        return Que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Que.empty();
    }
private :
    queue<int> Que;
    int len = 0;
};