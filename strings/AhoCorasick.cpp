template <int N, char Aa = 32, char Az = 126>
class AhoCorasick {
    static const int A = Az - Aa + 1;
    int trie[N][A], size;
    int end[N], link[N], endLink[N];

    int addNode() {
        end[size] = 0;
        return size++;
    }

public:
    AhoCorasick() { init(); }

    void init() {
        size = 0;
        addNode();
    }

    void addString(const string& s) {
        int n = s.length();
        int v = 0;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - Aa;
            if (!trie[v][c]) {
                trie[v][c] = addNode();
            }
            v = trie[v][c];
        }
        end[v] = n;
    }

    void build(bool addEdges = false) {
        int queue[N];
        queue[0] = 0;
        link[0] = 0;
        for (int *v = queue, *tail = v + 1; v != tail; ++v) {
            for (int c = 0; c < A; ++c)
                if (trie[*v][c] != 0) {
                    int u = link[*v];
                    while (u != 0 && !trie[u][c]) {
                        u = link[u];
                    }
                    link[trie[*v][c]] = *v == 0 ? 0 : trie[u][c];
                    *tail++ = trie[*v][c];
                } else {
                    if (addEdges) {
                        trie[*v][c] = trie[link[*v]][c];
                    }
                }
            endLink[*v] = end[link[*v]] ? link[*v] : endLink[link[*v]];
        }
    }

    bool search(const string& text) {
        int m = text.length();
        for (int v = 0, i = 0; i < m; ++i) {
            char c = text[i] - Aa;
            while (v != 0 && !trie[v][c]) {
                v = link[v];
            }
            v = trie[v][c];
            for (int u = v; u != 0; u = endLink[u]) {
                if (end[u]) {
                    return true;
                }
            }
        }
        return false;
    }
};
