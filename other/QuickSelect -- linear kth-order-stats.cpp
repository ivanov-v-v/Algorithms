#include <iostream>
#include <algorithm> // swap, copy

template<typename T>
class order_stats {
private:
    T* a;
    unsigned n;

    unsigned partition(T* l, T* r) {
        int* j = l;
        for (T* i = l; i != r ; ++i) {
            if (*i <= *r) {
                swap(*i, *j);
                ++j;
            }
        }
        swap(*j, *r);
        return j - l;
    }
    unsigned kth(T* l, T* r, unsigned k) {
        if (l == r) {
            return *l;
        }
        int p = partition(l, r);
        if (p == k) {
            return *(l + p);
        } else if (k < p) {
            return kth(l, l + p - 1, k);
        } else {
            return kth(l + p, r, k - p);
        }
    }
public:
    order_stats(T* l, T* r) {
        n = r - l + 1;
        a = new T[n];
        copy(l, l + n, a);
    }
    unsigned get_kth(unsigned k) {
        return kth(a, a + n - 1, k);
    }
};

int main(){
    int n;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << order_stats<int>(a, a + n - 1).get_kth(2) << std::endl;
    return 0;
}
