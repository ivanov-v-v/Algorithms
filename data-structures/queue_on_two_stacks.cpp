template<typename T>
class queue_on_stacks{
private:
    int N;
    stack<T> head, tail;
    void intersperse() {
        assert(head.empty());
        while (!tail.empty()) {
            head.push(tail.top());
            tail.pop();
        }
    }
public:
    queue_on_stacks() { N = 0; }
    inline bool empty() { return !N; }
    inline void push(const T& val) { tail.push(val), N++; }
    T peek() {
        assert(!empty());
        if (head.empty()) intersperse();
        return head.top();
    }
    T pop() {
        assert(!empty());
        if (head.empty()) intersperse();
        T top = head.top();
        head.pop(), N--;
        return top;
    }
};
