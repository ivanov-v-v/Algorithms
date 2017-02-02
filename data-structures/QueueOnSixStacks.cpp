template<typename T>
class Queue6 {
private:
    stack<T> *L, *L1, *S;
    stack<T> *R, *Rc, *Rc1;
    bool recopy;    // changes the mode
    bool copiedToS; // marks whether R is already copied to S during recopy mode
    int toCopy;     // how many elements from R remain uncopied from S at the moment

    void recopyOperations() {
        int toDo = 3; // three operations are enough
        while (!copiedToS && toDo && !R->empty()) { // copy R to S
            S->push(R->top());
            R->pop();
            --toDo;
        }
        while (toDo && !L->empty()) { // copy L to R, maintain a copy of R in Rc1
            copiedToS = true;
            T x = L->top();
            L->pop();
            R->push(x);
            Rc1->push(x);
            --toDo;
        }
        while (toDo && !S->empty()) { // copy S to R if necessary, maintain a copy of R in Rc1
            T x = S->top();
            S->pop();
            if (toCopy) {
                R->push(x);
                Rc1->push(x);
                --toCopy;
            }
            --toDo;
        }
        // if everything is copied correctly, exchange the stacks and change the mode
        if (S->empty()) {
            swap(L, L1);
            swap(Rc, Rc1);
            recopy = false;
        }
    }
    void startRecopy() {
        recopy = true;
        toCopy = R->size();
        copiedToS = false;
        recopyOperations();
    }
public:
    Queue6() {
        L = new stack<T>();
        L1 = new stack<T>();
        S = new stack<T>();
        R = new stack<T>();
        Rc = new stack<T>();
        Rc1 = new stack<T>();
        recopy = copiedToS = false;
        toCopy = 0;
    }
    void push(const T& x) {
        if (!recopy) {
            L->push(x);
            if (!Rc1->empty()) {
                Rc1->pop();
            }
            if (L->size() > R->size()) {
                startRecopy();
            }
        } else {
            L1->push(x);
            recopyOperations();
        }
    }
    T pop() {
        if (!recopy) {
            T tmp = R->top();
            R->pop();
            Rc->pop();
            if (!Rc1->empty()) {
                Rc1->pop();
            }
            if (L->size() > R->size()) {
                startRecopy();
            }
            return tmp;
        } else {
            T tmp = Rc->top();
            if (toCopy) {
                --toCopy;
            } else {
                R->pop();
                Rc->pop();
            }
            recopyOperations();
            return tmp;
        }
    }
};
