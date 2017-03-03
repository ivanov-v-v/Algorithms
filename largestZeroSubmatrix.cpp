#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using vector;
using std::pair;

/*
 * Given an n*m matrix consisting only of zeroes and ones,
 * find the largest submatrix consisting only of zeroes
 * in O(n*m) time and less than quadratic space complexity.
 */

/*
 * The algorithm traverses the matrix row by row,
 * and at each level recalculates for each entry
 * the height of the pile of zeros starting at it.
 * Using this, we can invert the problem to following:
 * for each such pile try to construct the largest submatrix of
 * that height by dragging it as far to both sides
 * as far as possible. To do so, find the largest such segment containing this pile
 * that all the piles located there have greater or equal height.
 * Or, equivalently, find the first strictly smaller pile (from the both sides).
 */

// return dimensions of the largest zero submatrix
// and its bottom left corner
pair<pair<int, int>, pair<int, int>> maxZeroSubmatrix(vector<vector<int>>& matrix) {
    enum orderT {ASCENDING, DESCENDING};
    /*
     * Given an array of data, how to efficiently (in linear time or less) find
     * a direct predecessor of every element?
     * Desired O(n) complexity can be achieved by the following algorithm:
     * traverse the array and store some of its elements in the stack,
     * maintaining the following invariant: each time the new element is
     * being pushed into a stack, it's guaranteed that it is strictly
     * greater than all the other elements in that stack.
     * To achieve this, simply keep on popping out the elements
     * from the stack, until the top element is less than the new one.
     * That top element, if any, will be the direct predecessor of the
     * one being inserted: to proof this, notice that, among all
     * already processed elements it is the closest strictly smaller one,
     * and at each step the stack elements are maintained in the
     * ascending sorted order.
     * So, the algorithm can be formulated as follows:
     *   | 1. Initialize output array to all -1s.
     *   | 2. Create an empty stack of indexes of items we have visited
     *   |    in the input array but don't yet know the answer for in the output array.
     *   | 3. Iterate over each element in the input array:
     *   |     1. Is it smaller than the item indexed by the top of the stack?
     *   |         1. Yes. It is the first such element to be so. Fill in the corresponding
     *   |            element in our output array, remove the item from the stack, and try
     *   |            again until the stack is empty or the answer is no.
     *   |         2. No. Continue to 3.2.
     *   |     2. Add this index to the stack. Continue iteration from 3.
     * Lets now proof the linear complexity:
     *   each index is accessed only once,
     *   each element is added to the stack once and removed at most once,
     *   so, lets divide all the operations into three groups:
     *      | ACC — accesses,
     *      | INS — insertions,
     *      | ERS — erasions,
     *   it is clear, that: ERS <= INS, INS = n,
     *   and the total number of accesses cannot exceed n,
     *   hence ACC + INS + ERS <= 3 * N.
     */
    auto get_predecessors = [](const vector<int>& data, vector<int>& pred, orderT direction) {
        if (data.empty()) {
            return;
        }
        int n = data.size();
        std::stack<pair<int, int>> s;
        int i = direction == ASCENDING ? 0 : n - 1;
        int last = direction == ASCENDING ? n : -1;
        for (; i !=  last; i += (direction == ASCENDING ? 1 : -1)) {
            while (!s.empty() && s.top().first >= data[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pred[i] = s.top().second;
            } else {
                pred[i] = direction == ASCENDING ? -1 : n;
            }
            s.push({data[i], i});
        }
    };
    if (matrix.empty()) {
        return {{0, 0}, {-1, -1}};
    }
    size_t n = matrix.size(), m = matrix[0].size();
    vector<int> height(m), prev(m, -1), next(m, m);
    std::stack<pair<int, int>> s;
    pair<int, int> dimensions, bottom_left;
    int max_area = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            height[j] = (matrix[i][j] ? 0 : height[j] + 1);
        }
        get_predecessors(height, prev, ASCENDING);
        get_predecessors(height, next, DESCENDING);
        for (size_t j = 0; j < m; ++j) {
            int submatrix_area = (next[j] - prev[j] - 1)  * height[j];
            if (submatrix_area > max_area) {
                max_area = submatrix_area;
                dimensions = {next[j] - prev[j] - 1, height[j]};
                bottom_left = {i, prev[j] + 1};
            }
        }
    }
    return {dimensions, bottom_left};
}

int main() {
    size_t n, m;
    std::cin >> n >> m;
    vector<vector<int>> data(n, vector<int>(m, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> data[i][j];
        }
    }
    auto answ = maxZeroSubmatrix(data);
    std::cout << answ.first.first << " * " << answ.first.second << "\n" 
              << "[" << answ.second.first << ", " << answ.second.second << "]" << std::endl;
    return 0;
}

