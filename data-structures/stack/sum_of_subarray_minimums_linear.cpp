/*
- Input: size n and an array of integers of that length
- Goal:  for every subsegment [l;r] find its minimal element
-        and output their sum.
- Algo: 
-- Complexity: O(n)
-- Idea:       As there are O(n^2) contiguous subsegments,
--             naive solution would have O(N^2 * QUERY) time,
--             where QUERY can be reduced to O(1) by sparse table.
--             Therefore, we can invert the process of thought:
--             instead of traversing all subsegments, we can
--             calculate the number of segments such that
--             element a[i] will be the least one on them.
--             Trivially, to do so we should know only two indices:
--             left[i]: a[left[i]] < a[i] && for all j a[j] < a[i] <=> j <= left[i]
--             right[i]: a[i] >= a[right[i]] && right[i] > i && for all j a[i] >= a[j] <=> j >= right[i]
--             Then we know, how many valid left and right bound variants we have for our segments.
--             How to calulate them quick? 
--             Hint: as we only need to know first of such indices for every i,
--             total complexity must not exceed O(n), as every index will be
--             removed after its answer is calculated.
--             Once again, invert the problem: if j is right[i] for some i < j, 
--             how do we calculate i? First of all, right[i] must be uninitialized
--             when we reach j-th position, and it suffies that a[i] >= a[j]. 
--             We can proceed to an intuitive algorithm: suppose that we are
--             currently in position j; if for any i < j right[i] = null,
--             try to relax all such i; if case of success, remove i from a list.
--             In result, every index will be added and removed only once,
--             and the process can be simulated easily using stack, giving us the final O(n) complexity.
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> right(n+1, n+1), left(n+1, 0);
    stack<int> s;
    for (int i = 1; i <= n; i++) {
        while (s.size() && a[s.top()] >= a[i]) {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long answ = 0;
    for (int i = n; i >= 1; i--) {
        while (s.size() && a[i] < a[s.top()]) {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
        answ += 1ll*(i-left[i])*(right[i]-i)*a[i];
    }
    cout << answ << endl;
    return 0;
}
