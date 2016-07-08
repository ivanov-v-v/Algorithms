#define _CRT_DISABLE_PERFCRIT_LOCKS
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;

/*MACROS*/
//FUNCTIONS
#define in_range(i, l, r) for(ll i = l; i < r; i++)

#define all(v) begin(v), end(v)
#define rall(v) (v).rbegin(), (v).rend()

#define tr(it, container) for(auto it = begin(container); it != end(container); it++)
#define rtr(it, container) for(auto it = (container).rbegin(); it != (container).rend(); it++)

#define present(element, container) ((container).find(element) != end(container))

#define stringify(something) std::string(#something)
#define _T(...) __VA_ARGS__
#define forever() for(;;)

//ABBREVIATIONS
#define sz(c) (ll(c.size()))
#define pb push_back
#define fst first
#define scd second
#define cmpBy(T, field) [](const T& x, const T& y){ return x.field < y.field; }

//TYPE SAFETY
#define sqrt(x) sqrt(1.0*(x))
#define pow(x, n) pow(1.0*(x), n)

//CONSTANTS
#define INF INT_MAX
#define MINF INT_MIN
#define LINF LONG_LONG_MAX
#define LMINF LONG_LONG_MIN
#define EPS 1E-9
#define PI (long double)3.14159265358979311600

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

/*TEMPLATE FUNCTIONS*/
//BIT OPERATIONS
template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bitcount(int n){return __builtin_popcount(n); }
inline int bitcount(ll n){return __builtin_popcountll(n); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }
template<typename A, typename B, typename C>
function<C(A)> combine(function<B(A)> f, function<C(B)> g) {
    return bind(g, bind(f, placeholders::_1));
}

/*TEMPLATE ALGORITHMS*/
template<typename T> inline T sqr(T x){T x_ = (x); return x_*x_;}
template<typename T> inline T qbr(T x){T x_ = (x); return ((x_*x_)*x_);}
template<typename T> inline int sign(T x){T x_ = (x); return ((x_>T(0))-(x_<T(0)));}
template<typename T> inline T mod(T x, T m){T x_ = (x); return (((x_) >= 0) ? ((x_) % (m)) : ((((x_) % (m))+(m))%(m)));}
template<typename T> inline T gcd(T a, T b){while(b){T t = a % b; a = b; b = t;} return a;}
template<typename T> inline T gcd_ex(T a, T b, T& x, T& y){if(b==0){x=1,y=0; return a;}T x1, y1;T d=gcd_ex(b,a%b,x1,y1);x = y1;y = x1-(a/b)*y1;return d;}
template<typename T> inline T lcm(T a, T b){return (a*(b/gcd(a, b)));}

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
template<class T> inline void getarr(T* arr, int l, int r) { in_range(i, l, r+1) cin >> arr[i]; }

//STL OUTPUT
template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> inline void printarr(T* arr, int l, int r) { in_range(i, l, r+1) {cout << arr[i] << " ";}; cout << "\n"; }

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

//__int128 -- use if supported
//typedef __int128 bigInt;
//istream& operator >>(istream& in, bigInt& n){
//    in >> ws; n = 0;
//    for(char ch = getchar(); isdigit(ch); ch = getchar()){
//        n = n*bigInt(10) + bigInt(ch-'0');
//    }
//    return in;
//}
//ostream& operator <<(ostream& out, bigInt n){
//    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    int representation[36];
//    int pos = 0;
//    while(n){
//        representation[pos++] = digits[n % 10];
//        n /= 10;
//    }
//    for(int i = pos-1; i >= 0; i--){
//        out << representation[i];
//    }
//    return out;
//}

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

#define DEBUG

//EXTREMELY FAST I/O
//const int BUFFSIZE = 2048;
//static char inbuff[BUFFSIZE + 16];
//static char *inp = inbuff;
//static char *linp = inbuff + BUFFSIZE;

//int read_int(){
//  while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
//  bool minus = false;
//  if (*inp == '-') minus = true, ++inp;
//  if (*inp == 0) {
//      memset(inbuff, 0, BUFFSIZE);
//      cin.read(inbuff, BUFFSIZE);
//      inp = inbuff;
//  }
//  int res = *inp++ - '0';
//  if (inp == linp) {
//      memset(inbuff, 0, BUFFSIZE);
//      cin.read(inbuff, BUFFSIZE);
//      inp = inbuff;
//  }
//  while (*inp >= '0' && *inp <= '9') {
//      res = res*10 + *inp - '0';
//      ++inp;
//      if (inp == linp) {
//          memset(inbuff, 0, BUFFSIZE);
//          cin.read(inbuff, BUFFSIZE);
//          inp = inbuff;
//      }
//  }
//  return minus ? -res : res;
//}
//
//static char outbuff[BUFFSIZE + 16];
//static char *outp = outbuff;
//static char *loutp = outbuff+BUFFSIZE;
//
//void write_int(int x, bool last = false) {
//  char *begp = outp;
//  if (x == 0) {
//        *outp++ = '0';
//  }
//  while(x) {
//      int quot = x/10;
//      char c = x - 10*quot + '0';
//      *outp++ = c;
//      x = quot;
//  }
//  char *endp = outp-1;
//  while(begp < endp) {
//      swap(*begp, *endp);
//      ++begp, --endp;
//  }
////    *outp++ = '\n';
//  if (last || outp > loutp) {
//      cout.write(outbuff, outp - outbuff);
//      outp = outbuff;
//  }
//}

struct pt{
    ll x, y;
    pt operator +(const pt& other) { return {x+other.x, y+other.y}; }
    pt operator -(const pt& other) { return {x-other.x, y-other.y}; }
    ll operator *(const pt& other) { return x*other.x + y*other.y; }
    ll operator ^(const pt& other) { return x*other.y - y*other.x; }
};

istream& operator >>(istream& in, pt& P) { in >> P.x >> P.y; return in; }

struct segment{
    pt bp, ep;
    int id;
    ld get_y(ll x) const {
        if (bp.x == ep.x) return bp.y;
        return bp.y + (ep.y-bp.y)*(x-bp.x)/ld(ep.x-bp.x);
    }
    bool operator <(const segment& other) const {
        ll x = max(min(bp.x, ep.x), min(other.bp.x, other.ep.x));
        return this->get_y(x) < other.get_y(x)-EPS;
    }
};

bool overlaps1D(ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1) swap(l1, r1);
    if (l2 > r2) swap(l2, r2);
    return max(l1, l2) <= min(r1, r2);
}

bool intersect(const segment& S1, const segment& S2) {
    pt B1 = S1.bp, E1 = S1.ep, B2 = S2.bp, E2 = S2.ep;
    return  (overlaps1D(B1.x, E1.x, B2.x, E2.x)) &&
            (overlaps1D(B1.y, E1.y, B2.y, E2.y)) &&
            (sign((B2-B1)^(E1-B1)) * sign((E2-B1)^(E1-B1)) <= 0) &&
            (sign((B1-B2)^(E2-B2)) * sign((E1-B2)^(E2-B2)) <= 0);
}

struct event {
    ll x;
    int type;
    int id;
    bool operator <(const event& other) const {
        return (other.x == x) ? type > other.type : x < other.x;
    }
};

typedef set<segment> status;
status T;
vector<status::iterator> position;
status::iterator above(status::iterator it) {
    return ++it;
}
status::iterator below(status::iterator it) {
    return (it == T.begin()) ? T.end() : --it;
}
pii any_intersection(const vector<segment>& data) {
    int n = sz(data);
    position.resize(n);
    vector<event> events;
    in_range(i, 0, n) {
        events.pb({min(data[i].bp.x, data[i].ep.x), 1, i});
        events.pb({max(data[i].bp.x, data[i].ep.x), -1, i});
    }
    sort(all(events));
    for (auto e : events) {
        int id = e.id;
        if (e.type == 1) {
            auto nxt = T.lower_bound(data[id]);
            auto prv = below(nxt);
            if (nxt != T.end() && intersect(*nxt, data[id])) {
                return {nxt->id, id};
            }
            if (prv != T.end() && intersect(*prv, data[id])) {
                return {prv->id, id};
            }
            position[id] = T.insert(nxt, data[id]);
        } else {
            auto nxt = above(position[id]);
            auto prv = below(position[id]);
            if (nxt != T.end() && prv != T.end() && intersect(*nxt, *prv)) {
                return {nxt->id, prv->id};
            }
            T.erase(position[id]);
        }
    }
    return {-1, -1};
}

int main(){
    fastIO();
//    freopen("in", "r", stdin);
//    freopen("smoking.out", "w", stdout);
    int n; cin >> n;
    vector<segment> data(n);
    in_range(i, 0, n) {
        cin >> data[i].bp >> data[i].ep;
        data[i].id = i;
    }
    pii answ = any_intersection(data);
    if (answ.fst >= 0) {
        print("YES");
        print(answ.fst+1, answ.scd+1);
    } else {
        print("NO");
    }
    return 0;
}
