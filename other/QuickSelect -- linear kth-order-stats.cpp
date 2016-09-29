#include <iostream>
#include <algorithm>
#include <cmath>

template <typename T, unsigned K = 5>
class order_stats {
private:
    T* a;
    unsigned n;

    unsigned partitionK_(unsigned l, unsigned r) {
        for (size_t i = l; i < r; ++i) {
            for (size_t j = i; j > 0 && a[j - 1] > a[j] ; --j) {
                std::swap(a[j - 1], a[j]);
            }
        }
        return r - l <= 2 ? l : l + (r - l)/2 - 1;
    }
    unsigned pivot_(unsigned l, unsigned r) {
        if (r - l <= K) {
            return partitionK_(l, r);
        }
        for (unsigned i = l; i < r; i += K) {
            unsigned median5 = partitionK_(i, std::min(r, i + K - 1));
            std::swap(a[median5], a[l + (i - l)/K]);
        }
        return select_(l, l + std::ceil(static_cast<double>(r - l)/K) - 1, l + (r - l)/(2*K));
    }
    unsigned partition_(unsigned l, unsigned r, unsigned pivotId) {
        unsigned j = l;
        T &pivot = a[r - 1];
        std::swap(a[pivotId], pivot);
        for (size_t i = l; i != r ; ++i) {
            if (a[i] <= pivot) {
                std::swap(a[i], a[j]);
                ++j;
            }
        }
        std::swap(a[j], pivot);
        return j;
    }
    unsigned select_(unsigned l, unsigned r, unsigned order) {
        while (r - l >= 2) {
            unsigned pivotId = pivot_(l, r);
            pivotId = partition_(l, r, pivotId);
            if (pivotId == order) {
                return pivotId;
            } else if (order < pivotId) {
                r = pivotId;
            } else {
                l = pivotId + 1;
                order -= pivotId;
            }
        }
        return l;
    }
public:
    order_stats(T* l, T* r) {
        n = r - l;
        a = new T[n];
        std::copy(l, l + n, a);
    }
    T get_kth(unsigned k) {
        return a[select_(0, n, k - 1)];
    }
};

int main(){
    unsigned n, order, K;
    std::cin >> n >> order >> K;
    int* a = new int[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::cout << order_stats<int, K>(a, a + n).get_kth(order) << std::endl;
    return 0;
}
