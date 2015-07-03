class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if (!Que[idx].empty()) {
            Que[idx^1].push(Que[idx].front());
            Que[idx].pop();
        }
        Que[idx].push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        Que[idx].pop();
        idx ^= 1;
        len = Que[idx].size();
        while (len > 1) {
            Que[idx^1].push(Que[idx].front());
            Que[idx].pop();
            --len;
        }
    }

    // Get the top element.
    int top() {
        return Que[idx].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Que[0].empty() && Que[1].empty();
    }
private :
    queue<int> Que[2];
    int idx = 0, len = 0;
};