template <typename T>
struct Vertex {
    T key;
    Vertex* parent;
    Vertex* child;      // left child
    Vertex* sibling;    // right brother
    unsigned degree;
    Vertex ():
            key(0), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {};
    Vertex (const T& key):
            key(key), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {};
};

template <typename T>
class BinomialHeap {
private:
    Vertex<T> *head;
public:
    BinomialHeap(): head(nullptr) {}

    bool empty() { return !head; }
    void insert(const T& key) {
        BinomialHeap T0;
        T0.head = new Vertex<T>(key);
        *this = merge(*this, T0);
    }
    T getMinimum() {
        if (!head) {
            throw logic_error("Empty heap.");
        }
        T minVal = head->key;
        Vertex<T>* currH = head;
        while (currH) {
            minVal = min(minVal, currH->key);
            currH = currH->sibling;
        }
        return minVal;
    }
    T extractMin() {
        if (!head) {
            throw logic_error("Empty heap.");
        }
        T minVal = head->key;
        Vertex<T> *currH = head, *predToMin = nullptr;
        while (currH->sibling) {
            if (currH->sibling->key < minVal) {
                minVal = currH->sibling->key;
                predToMin = currH;
            }
            currH = currH->sibling;
        }
        Vertex<T> *minV;
        if (predToMin) {
            minV = predToMin->sibling;
            predToMin->sibling = predToMin->sibling->sibling;
        } else {
            minV = head;
            head = head->sibling;
        }
        currH = minV->child;
        while (currH) {
            BinomialHeap T0;
            T0.head = new Vertex<T>();
            *T0.head = *currH;
            T0.head->sibling = nullptr;
            T0.head->parent = nullptr;
           *this =  merge(*this, T0);
            currH = currH->sibling;
        }
        return minVal;
    }
    template <typename U>
    friend BinomialHeap<U> merge(BinomialHeap<U>& H1, BinomialHeap<U>& H2);
};

template <typename T>
BinomialHeap<T> merge(BinomialHeap<T>& H1, BinomialHeap<T>& H2) {
    if (H1.empty() || H2.empty()) {
        return H1.empty() ? H2 : H1;
    }
    BinomialHeap<T> H;
    Vertex<T>   *currH = H.head,        // активная вершина новой пирамиды
                *currH1 = H1.head,      // активная вершина пирамиды 1
                *currH2 = H2.head;      // активная вершина пирамиды 2
    while (currH1 && currH2) { // сконструировать список корней в порядке неубывания степеней
        if (currH1->degree < currH2->degree) {
            if (!currH) { // подвесить H1 справа
                H.head = currH1;
                currH = currH1;
            }
            else {
                currH->sibling = currH1;
            }
            if (currH->sibling) currH = currH->sibling;  // сдвинуться по Н
            currH1 = currH1->sibling;                    // сдвинуться по Н1
        } else {
            if (!currH) { // подвесить H2 справа
                H.head = currH2;
                currH = currH2;
            }
            else {
                currH->sibling = currH2;
            }
            if (currH->sibling) currH = currH->sibling; // сдвинуться по Н
            currH2 = currH2->sibling;                   // сдвинуться по Н2
        }
    }
    if (!currH1) {  // если непуста первая пирамида, то добавить её корни
        while (currH2) {
            currH->sibling = currH2;
            currH = currH->sibling;
            currH2 = currH2->sibling;
        }
    } else {    // если непуста вторая пирамида, то аналогично
        while (currH1) {
            currH->sibling = currH1;
            currH = currH->sibling;
            currH1 = currH1->sibling;
        }
    }
    currH = H.head;
    while (currH->sibling) { // произвести слияние вершин одинаковых степеней
        if (currH->degree == currH->sibling->degree) {
            // предполагаем, что пирамида на минимум, и значение с меньшим
            // ключом лежит в левом биномиальном дереве
            if (currH->key > currH->sibling->key) {
                // иначе: обменяем соседние деревья местами
                // сохраняя корректность ссылок на соседей
                swap(currH->child, currH->sibling->child);
                swap(currH->key, currH->sibling->key);
            }
            Vertex<T>* theNodeAfter = currH->sibling->sibling; // вырезать правую вершину
            currH->sibling->sibling = currH->child; // подцепить её слева к сыну левой вершины
            currH->sibling->parent = currH; // не забывая обновить ссылку на родительскую вершину
            currH->child = currH->sibling; // подцепить её как сына к левой вершине
            ++currH->degree; // соответственно увеличить степень вершины
            currH->sibling = theNodeAfter; // переподцепить её правую ссылку
            continue; // правая вершина может иметь ту же степень, следовательно, сдвигаться рано
        }
        // данная пара вершин слиянию не подлежит
        currH = currH->sibling;
    }
    return H;
}
