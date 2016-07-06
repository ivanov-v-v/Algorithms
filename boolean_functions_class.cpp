#define _CRT_DISABLE_PERFCRIT_LOCKS
#define _ CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES

/*Allocation control*/
//#define CUSTOM_VECTOR
#define CUSTOM_ALLOCATOR

/*Hidden features*/
//#define BUILTIN_TREE
//#define BINARY_IO
//#define INT_128

#define DEBUG

#ifdef BUILTIN_TREE
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
#endif

#include <bits/stdc++.h>
//#include <gmpxx.h>
//#include <NTL/ZZ.h>
using namespace std;
//using namespace NTL;

/*MACROS*/
//FUNCTIONS
#define in_range(i, l, r) for(ll i = l; i < r; i++)

#define all(v) begin(v), end(v)
#define rall(v) (v).rbegin(), (v).rend()

#define tr(it, container) for(auto it = begin(container); it != end(container); it++)
#define rtr(it, container) for(auto it = (container).rbegin(); it != (container).rend(); it++)

#define present(element, container) ((container).find(element) != end(container))

#define _T(...) __VA_ARGS__
#define forever() for(;;)

//ABBREVIATIONS
#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }
template<class T> T peek(queue<T>& q) { T top_el = q.front(); q.pop(); return top_el; }

//TYPE SAFETY
#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)

//CONSTANTS
#define INF (numeric_limits<int>::max())
#define MINF (numeric_limits<int>::min())
#define LINF (numeric_limits<long long>::max())
#define LMINF (numeric_limits<long long>::min())
#define EPS (1E-9)
#define PI ((long double)3.1415926535897932384626433832795028841971693993751)

#define reunique(container) ((container).resize(unique(all(container))-begin(container)))

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<int>> graph;

/*TEMPLATE FUNCTIONS*/
//BIT OPERATIONS
template<typename T> inline int bit(T n, T i){return ((n >> i) & T(1));}
inline int bitcount(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + ((v >> 4) & 0xF0F0F0F)) * 0x1010101) >> 24; }
inline int bitcount(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bitcount(t) + bitcount(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << bit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << bit(n, i); } cout << "\n"; }

/*TEMPLATE ALGORITHMS*/
template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}
template<typename T> inline bool between(T x, T l, T r) { return l <= x && x <= r; }

/*COMBINATORS*/
template <typename Collection, typename UnaryOperation> void foreach(Collection &col, UnaryOperation op){for_each(all(col), op);}
template <typename Collection, typename UnaryOperation> Collection fmap(Collection &col, UnaryOperation op){transform(all(col), col.begin(), op); return col;}
template <typename Collection, typename binop> Collection zip(Collection& fc, Collection& sc,binop op) {transform(all(fc), sc.begin(), fc.begin(), op); return fc;}
template <typename Collection, typename Condition> bool exists(Collection& col,Condition con) {auto exist = find_if(all(col), con); return exist != col.end();}
template <typename Collection, typename Predicate> Collection filterNot(Collection& col, Predicate predicate) {auto returnIterator = remove_if(all(col), predicate); col.erase(returnIterator, end(col)); return col;}

//STL INPUT
void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r) cin >> arr[i]; }

//STL OUTPUT
template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const std::set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r) {cout << arr[i] << " ";}; cout << "\n"; }

//VARIADIC INPUT
template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }

//VARIADIC OUTPUT
template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }

//VARIADIC TYPE DECLARATION
template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::tensor(args...); }

#ifdef INT_128
typedef __int128 bigInt;
istream& operator >>(istream& in, bigInt& n){
    in >> ws; n = 0;
    for(char ch = getchar(); isdigit(ch); ch = getchar()){
        n = n*bigInt(10) + bigInt(ch-'0');
    }
    return in;
}
ostream& operator <<(ostream& out, bigInt n){
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int representation[36];
    int pos = 0;
    while(n){
        representation[pos++] = digits[n % 10];
        n /= 10;
    }
    for(int i = pos-1; i >= 0; i--){
        out << representation[i];
    }
    return out;
}
#endif // INT_128

//DEBUG
#define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 5,4,3,2,1))
#define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
#define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,N,...) N
#define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
#define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
#define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
#define macro_dispatcher___(macro, nargs) macro ## nargs
#define DBN1(a)         cerr<<#a<<" = "<<(a)<<"\n"
#define DBN2(a,b)       cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<"\n"
#define DBN3(a,b,c)     cerr<<#a<<" = "<<(a)<<", "<<#b<<" = " <<(b)<<", "<<#c<<" = "<<(c)<<"\n"
#define DBN4(a,b,c,d)   cerr<<#a<<" = "<<(a)<<", "<<#b<<" ="<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define DBN5(a,b,c,d,e) cerr<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
#define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
#define tri triple<int,int,int>
#define trll triple<ll,ll,ll>
template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }

#ifdef BINARY_IO
const int BUSFIZE = 2048;
static char inbuf[BUSFIZE + 16];
static char *inp = inbuf;
static char *linp = inbuf + BUSFIZE;
int read_int()
{
    if (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
    bool minus = false;
    if (*inp == '-') minus = true, ++inp;
    if (*inp == 0)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    int res = *inp++ - '0';
    if (inp == linp)
    {
        memset(inbuf, 0, BUSFIZE);
        cin.read(inbuf, BUSFIZE);
        inp = inbuf;
    }
    while (*inp >= '0' && *inp <= '9')
    {
        res = res * 10 + *inp - '0';
        ++inp;
        if (inp == linp)
        {
            memset(inbuf, 0, BUSFIZE);
            cin.read(inbuf, BUSFIZE);
            inp = inbuf;
        }
    }
    return minus ? -res : res;
}
static char outbuf[BUSFIZE + 16];
static char *outp = outbuf;
static char *loutp = outbuf + BUSFIZE;
void write_int(int x, bool last = false)
{
    char *begp = outp;
    do
    {
        int t = x / 10;
        char c = x - 10 * t + '0';
        *outp++ = c;
        x = t;
    } while (x);
    char *endp = outp - 1;
    while (begp < endp)
    {
        swap(*begp, *endp);
        ++begp;
        --endp;
    }
    *outp++ = '\n';
    if (last || outp > loutp)
    {
        cout.write(outbuf, outp - outbuf);
       outp = outbuf;
    }
}
#endif

#ifdef CUSTOM_VECTOR
template <class T>
    struct custom_vector : vector<T> {
    custom_vector() : vector<T>() { }
    custom_vector( int n ) : vector<T>(n) { }
    custom_vector( int n, T x ) : vector<T>(n, x) { }
    T &operator [] ( size_t i ) {
        return vector<T>::at(i);
    }
};

#define vector custom_vector
#endif

ll inverse(ll a, ll m) {
    ll x, y;
    ll g = gcd_ex(a, m, x, y);
    if (g != 1) {
        cout << "Not invertible\n";
        return -1;
    }
    return mod(x, m);
}

pll solve(ll a, ll b, ll c) {
    ll x, y;
    ll g = gcd_ex(a, b, x, y);
    assert(c % g == 0);
    DBN(x, y);
    return {x * (c/g), y * (c/g)};
}

ll chinese(vector<pll> system) {
    ll M = accumulate(all(system), 1LL, [](ll prod, pll entry) { return prod*entry.scd; });
    int n = system.size();
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll Mi = M/system[i].scd;
        res += Mi*inverse(Mi, system[i].scd)*system[i].fst;
    }
    res %= M;
    for (int i = 0; i < n; i++) {
        cout << res%system[i].scd << " " << system[i].scd << "\n";
    }
    return res;
}

ll legendre(ll q, ll p) {
    q %= p;
    ll res = 1;
    while (q != 0) {
        DBN(q, p, res);
        while (q % 2 == 0) {
            q /= 2;
            if (p % 8 == 3 || p % 8 == 5) {
                res *= (-1);
            }
            DBN(q, p, res);
        }
        if (q != 1 && ((p % 4 == 3) ^ (q % 4 == 3))) {
            res *= (-1);
        }
        swap(q, p);
        q %= p;
//        DBN(q, p, res);
    }
    DBN(q, p, res);
    return p == 1 ? res : 0;
}

ll modpow(ll n, ll d, ll m) {
    ll res = 1;
    while (d) {
        if (d & 1)
            res = mod(res*n, m);
        n = mod(n*n, m);
        d >>= 1;
    }
    return res;
}

ll phi(ll n) {
    ll res = n;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            res -= res/i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) res -= res/n;
    return res;
}

ll ord(ll n, ll m) {
    ll k = 1;
    while (modpow(n, k, m) != 1) { k++; }
    return k;
}

vector<ll> primitive_roots(ll m) {
    vector<ll> result;
    ll phi = ::phi(m);
    for (ll g = 0; g < m; g++) {
        if (gcd(g, m) == 1) {
            if (ord(g, m) == phi) {
                result.pb(g);
            }
        }
    }
    return result;
}

ll ind(ll n, ll g, ll m) {
    ll root = g, k = 1;
    while (root != n) {
        root = mod(root*g, m);
        k++;
    }
    return k;
}

vector<ll> continuous_fraction(ll a, ll b) {
    vector<ll> coefficients;
    while (b) {
        coefficients.push_back(a/b);
        b ^= a ^= b ^= a %= b;
    }
    return coefficients;
}

pll restore_fraction(const vector<ll>& a) {
    ll n = sz(a);
    if (n == 1) return {a[0], 1};
    vector<ll> p(n), q(n);
    p[0] = a[0], q[0] = 1;
    p[1] = a[0]*a[1] + 1, q[1] = a[1];
    for (int i = 2; i < n; i++) {
        p[i] = a[i]*p[i-1] + p[i-2];
        q[i] = a[i]*q[i-1] + q[i-2];
    }
    return {p[n-1], q[n-1]};
}

class BooleanFunction{
private:

    vector<string> tokenized;
    vector<string> params;
    vector<int> table;

    bool latex_mode = 0;
    int arity = 0;

    inline int priority(const string& op) {
        return
                op == "!" ? 3 :
                op == "&" ? 2 :
                op == "|" ? 1 :
                op == "->" ? 0 :
                -1;
    }

    inline bool is_op(const string& word) {
        return
                word == "(" ||
                word == ")" ||
                word == "!" ||
                word == "&" ||
                word == "|" ||
                word == "->";
    }

    inline void process_op(vector<int>& vars, const string& op) {
//        if (op == "(" || op == ")") return;
        int rhs = vars.back(); vars.pop_back();
        if (op == "!") {
            vars.push_back(!rhs);
            return;
        }
        int lhs = vars.back(); vars.pop_back();
        if (op == "&") { vars.push_back(lhs & rhs); }
        else if (op == "|") { vars.push_back(lhs | rhs); }
        else if (op == "->") { vars.push_back(lhs <= rhs); }
    }

    int stoi(const string& s) {
        int val = 0;
        tr(it, s) {
            assert(isdigit(*it));
            val = val*10 + (*it-'0');
        }
        return val;
    }

public:

    BooleanFunction(){}

    int get_arity() { return arity; }

    vector<int> get_table() { return table; }
    void set_table(const vector<int>& data) {
        table = vector<int>(data);
        arity = binlog(sz(table));
        for (int i = 1; i <= arity; i++) {
            params.pb("x"+to_string(i));
        }
    }

    void set_latex_mode(bool flag) { latex_mode = flag; }

    void parse(const string& f) {
        const int n = sz(f);
        string word;

        set<string> names;
        map<string, int> id;

        for (int i = 0; i < n; i++) {
            if (f[i] == ' ') continue;
            if (f[i] == '(') { tokenized.pb("("); continue; }
            if (f[i] == ')') { tokenized.pb(")"); continue; }
            if (!latex_mode && f[i] == '!') { tokenized.pb("!"); continue; }
            word.pb(f[i]);
            if (i+1 == n || f[i+1] == '(' || f[i+1] == ')' || f[i+1] == ' ') {
                if (word == (latex_mode ? "\\neg" : "!")) {
                    tokenized.pb("!");
                }
                else if (word == (latex_mode ? "\\land" : "&")) {
                    tokenized.pb("&");
                }
                else if (word == (latex_mode ? "\\lor" : "|")) {
                    tokenized.pb("|");
                }
                else if (word == (latex_mode ? "\\Rightarrow" : "->")) {
                    tokenized.pb("->");
                }
                else {
                    if (!present(word, names)) {
                        id[word] = names.size();
                        names.insert(word);
                        params.pb(word);
                    }
                    tokenized.pb(to_string(id[word]));
                }
//                print(i, word);
                word.clear();
            }
        }
        arity = names.size();
//        print(tokenized);
    }

    void read(const string& f) { parse(f); }

    bool process(const vector<int>& valset) {
//        DBN(valset);
        vector<string> ops;
        vector<int> vars;

        tr(it, tokenized) {
//            DBN(*it);
//            DBN("IN", vars, ops);
            if (is_op(*it)) {
                if (*it == "(") ops.push_back("(");
                else if (*it == ")") {
//                    DBN(vars, ops);
                    while (!ops.empty() && ops.back() != "(") {
                        process_op(vars, ops.back()); ops.pop_back();
                    } ops.pop_back();
//                    DBN(vars, ops);
                } else {
                    while (!ops.empty() && priority(ops.back()) >= priority(*it)) {
//                        DBN(*it, ops.back(), priority(ops.back()), priority(*it));
                        process_op(vars, ops.back()); ops.pop_back();
                    }
                    ops.push_back(*it);
                }

            } else {
//                DBN(*it, stoi(*it));
                vars.push_back(valset[stoi(*it)]);
            }
//            DBN("OUT", vars, ops);
        }
//        DBN(ops);
//        exit(0);
        while (!ops.empty()) {
            process_op(vars, ops.back());
            ops.pop_back();
        }
//        print(vars);
        assert(vars.size() == 1);
        return vars.back();
    }

    vector<int> calc_table() {
        table = vector<int>(1<<arity);
        for (int mask = 0; mask < (1<<arity); mask++) {
            vector<int> mvec;
            for (int i = 0; i < arity; i++) {
                mvec.pb(bit(mask, i));
            }
            reverse(all(mvec));
            table[mask] = process(mvec);
        }
        return table;
    }

    vector<int> calc_Gegalkine_polynomial(){
        if (sz(table) == 0) calc_table();
        vector<int> d (table), Gegalkine {d[0]};
        while (sz(d) > 1) {
            vector<int> new_row;
            for (int i = 0; i < sz(d)-1; i++) {
                new_row.pb((d[i]+d[i+1])%2);
            }
            Gegalkine.pb(new_row[0]);
            d = new_row;
        }
        int addends = accumulate(all(Gegalkine), 0);
        for (int mask = 0, cnt = 0; mask < (1<<arity); mask++) {
            if (Gegalkine[mask]) {
                cnt++;
                for (int j = 0, shown = 0, total = __builtin_popcount(mask); j < arity; j++) {
//                    print(mask, j);
                    if (bit(mask, j)) {
                        shown++;
//                        DBN(j, arity);
                        cout << params[j];
                        if (shown != total) cout << ".";
                    }
                }
                if (cnt != addends) cout << " + ";
            }
        }
        return Gegalkine;
    }

    vector<int> calc_CNF() {
        if (!sz(table)) calc_table();
        vector<int> conjuncts;
        int zeros = sz(table)-accumulate(all(table), 0);
        for (int mask = 0, cnt = 0; mask < (1<<arity); mask++) {
            if (!table[mask]) {
                cnt++;
                conjuncts.pb(mask);
                cout << "(";
                for (int i = 0; i < arity; i++) {
                    if (bit(mask, i)) { cout << "!" << params[i]; }
                    else { cout << params[i]; }
                    if (i+1 != arity) cout << " | ";
                }
                cout << ")";
                if (cnt != zeros) cout << " & ";
            }
        }
        return conjuncts;
    }
    vector<int> calc_DNF() {
        if (!sz(table)) calc_table();
        vector<int> disjuncts;
        int ones = accumulate(all(table), 0);
        for (int mask = 0, cnt = 0; mask < (1<<arity); mask++) {
            if (table[mask]) {
                cnt++;
                disjuncts.pb(mask);
                for (int i = 0; i < arity; i++) {
                    if (bit(mask, i)) { cout << params[i]; }
                    else { cout << "!" << params[i]; }
                    if (i+1 != arity) cout << ".";
                }
                if (cnt != ones) cout << " | ";
            }
        }
        return disjuncts;
    }
};

void run_boolean_playground(){
        BooleanFunction test;
//    vector<int> data;
//    for (int x; scanf("%d", &x) == 1; ) {
//        data.pb(x);
//    }
//    test.set_table(data);
    string formula;
    getline(cin, formula);
    test.set_latex_mode(0);
    test.read(formula);

    auto res = test.calc_table();
    cout << "Truth table:\n";
    deque<string> table;
    int maxm = (1<<test.get_arity())-1;
    for (int i = maxm; i > 0; i = (i-1)&maxm) {
        string row;
        for (int j = 0; j < test.get_arity(); j++) {
            row.pb(bit(i, j)+'0');
        }
        reverse(all(row));
        row += (" --> ");
        row += to_string(res[i]);
        table.pb(row);
        row.clear();
        if (i == 1) {
             for (int j = 0; j < test.get_arity(); j++) {
                row.pb('0');
            } row += " --> ";
            row += to_string(res[0]);
            table.pb(row);
        }
    }
    reverse(all(table));
    for (auto &row : table)
        print(row);

    print(""); cout << "ANF: ";
    test.calc_Gegalkine_polynomial(); print("");
    cout << "CNF: ";
    test.calc_CNF(); print("");
    cout << "DNF: ";
    test.calc_DNF(); print("");
}

int main(){
//        fastIO();
//        freopen("aquarium.in", "r", stdin);
//        freopen("aquarium.out", "w", stdout);
    int n; cin >> n;
    int full = (1<<n)-1;

    auto G = tensor<ll>(n, n);
    read(G);

    auto d = tensor<ll>(1<<n, n);

    for (int mask = 1; mask <= full; mask++) {
        for (int v = 0; v < n; v++) {
            if (!bit(mask, v)) continue;
            if (mask == (1<<v)) {
                d[mask][v] = 0;
            } else {
                d[mask][v] = INF;
                int from = mask^(1<<v);
                for (int u = 0; u < n; u++) {
                    if (bit(from, u) && G[u][v]) {
//                        if (mask == full && v == 0) {
//                            cout << "Before " << u << " " << d[mask][v] << "\t";
//                            cout << d[from][u] << ": " << G[u][v] << " " << d[from][u] + G[u][v] << "\t";
//                        }
                        d[mask][v] = min(d[mask][v], d[from][u]+G[u][v]);
//                        if (mask == full && v == 0) {
//                            cout << "After " << d[mask][v] << "\n";
//                        }
                    }
                }
            }
        }
    }

//    for (int mask = 0; mask <= full; mask++) {
//        auto row = d[mask];
//        reverse(all(row));
//        for (int i = n-1; i >= 0; i--) {
//            cout << bit(mask, i);
//        } cout << ": ";
//        for (int i = 0; i < n; i++) {
//            cout << row[i] << "\t";
//        } cout << "\n";
//    }
    auto answ = min_element(all(d[full]));
    ll cost = *answ; int pos = answ-begin(d[full]);
    print(cost);
    cout << pos+1 << " ";
    int curr = full^(1<<pos), prev = full;
    while (cost) {
        for (int i = 0; i < n; i++) {
            if (!bit(curr, i) || !G[i][pos]) continue;
            if (d[curr][i]+G[i][pos] == d[prev][pos]) {
                cout << i+1 << " ";
                cost -= G[i][pos];
                pos = i;
                prev = curr;
                curr ^= (1<<i);
                break;
            }
        }
    }
    cout << "\n";
    return 0;
}

#ifdef CUSTOM_ALLOCATOR
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
inline void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    assert(mpos <= MAX_MEM);
    return (void *) res;
}
inline void operator delete ( void * ) { }
#endif // CUSTOM_ALLOCATOR
