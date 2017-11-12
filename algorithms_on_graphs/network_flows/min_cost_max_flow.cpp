template<typename T, typename C>
class edge{
public:
    int from, to;
    int next;
    T f, c;
    C cost;
    friend ostream& operator <<(ostream&, const edge&);
};

template<typename T, typename C>
ostream& operator<<(ostream& out, const edge<T, C> &e) {
    out << "[" << e.from << " -> " << e.to << ", " << e.f << "\\" << e.c << ", " << e.cost <<  "]";
    return out;
}

template<typename T, typename C>
class min_cost_max_flow {

    int n, m;
    int s, t;

    vector<edge<T, C>> edges;
    vector<int> head;

    void add_edge(int a, int b, T c, C cost) {
        edges.pb({a, b, head[a], 0, c, cost});
        edges.pb({b, a, head[b], 0, 0, -cost});
        head[a] = sz(edges)-2;
        head[b] = sz(edges)-1;
    }

    void read_network() {
        read(n, m);
        s = 0, t = n + 1;
        head = vector<int>(t + 1, -1);
        in_range(i, 0, m) {
            int a, b; T c; C cost;
            read(a, b, c, cost);
            add_edge(a, b, c, cost);
        }
        n = t+1;
        m = sz(edges);
    }

    vector<C> d;
    vector<int> state, pr;
    deque<int> q;
    bool levite() {
        fill(all(d), numeric_limits<C>::max());
        fill(all(state), 2);

        d[s] = 0;
        q.push_front(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            state[v] = 0;
            for (int i = head[v]; i != -1; i = edges[i].next) {
                edge<T, C> &e = edges[i];
                if (e.f >= e.c) continue;
                if (d[e.to] > d[v]+e.cost) {
                    d[e.to] = d[v]+e.cost;
                    if (state[e.to] == 0) { q.push_front(e.to); }
                    if (state[e.to] == 2) { q.push_back(e.to); }
                    state[e.to] = 1;
                    pr[e.to] = i;
                }
            }
        }
        return d[t] < numeric_limits<C>::max();
    }
    C push_flow() {
        T f = numeric_limits<T>::max();
        for (int v = t; pr[v] != -1; v = edges[pr[v]].from) {
            f = min(f, edges[pr[v]].c - edges[pr[v]].f);
        }
        for (int v = t; v != s; v = edges[pr[v]].from) {
            edges[pr[v]].f += f;
            edges[pr[v]^1].f -= f;
        }
        return d[t];
    }

public:
    C process() {
        read_network();
        d = vector<C>(n);
        pr = state = vector<int>(n);

        C min_cost = 0;

        while (levite())
            min_cost += push_flow();
        return min_cost;
    }

};
int main(){
    cout << new min_cost_max_flow<int, int>)->process() << endl;
    return 0;
}
