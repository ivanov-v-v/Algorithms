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
#define INF (numeric_limits<int>::max())
#define MINF (numeric_limits<int>::min())
#define LINF (numeric_limits<long long>::max())
#define LMINF (numeric_limits<long long>::min())
#define EPS (1E-9)
#define PI ((long double)3.14159265358979311600)

#define reunique(container) ((container).resize(unique(all(container))-begin(container)))

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

/*TEMPLATE FUNCTIONS*/
//BIT OPERATIONS
template<typename T> inline int checkbit(T n, T i){return ((n >> i) & T(1));}
inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
template<typename T> inline bool isPowerOfTwo(T n){return (n != 0 and ((n&(n-1)) == 0)); }
inline int binlog(int n){ assert(n > 0); return 32-__builtin_clz(n)-1; }
inline int binlog(ll n) { assert(n > 0); return 64-__builtin_clzll(n)-1;  }

void bitprint(int n, int w=32){ for (int i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }
void bitprint(ll n, int w=64){ for (ll i = w-1; i >= 0; i--) { cout << checkbit(n, i); } cout << "\n"; }

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
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
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

// int read_int(){
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
// }

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
//      outp/= outbuff;
//  }
//}

const int MAXN = 1e5;
const ll MOD = 1e9+7;

int p[MAXN+1];
void initialize() {
    p[0] = 1;
    p[1] = 31;
    for (int i = 2; i <= MAXN; i++) {
        p[i] = mod(p[i-1]*31LL, MOD);
    }
}

int _hash_string(const string& s) {
    int _hash = 0;
    for (int i = 0; i < sz(s); i++) {
        DBN(i, p[i]);
        _hash = mod(_hash+(islower(s[i]) ? (s[i]-'a')+1 : (s[i]-'A')+1)*1LL*p[i], MOD);
    }
    return _hash;
}

struct node {
    int key;
    int cnt;
    int _hash;
    node *tl, *tr;

    node (): key(0), cnt(1), _hash(0) { tl = tr = nullptr; }
} BUFF[MAXN+1];
int CNT = 1;

typedef node* pnode;
pnode Root = nullptr;

void Display(pnode T) {
    if (T) {
        Display(T->tl);
        char c = (T->key-1)+'a';
        cout << c << " ";
        Display(T->tr);
    }
}

inline int cnt(pnode T) { return T ? T->cnt : 0; }
inline int _hash(pnode T) { return T ? T->_hash : 0; }

inline void upd(pnode T) {
    if (T) {
        T->cnt = 1 + cnt(T->tl) + cnt(T->tr);
        T->_hash = mod(_hash(T->tl) + 1LL*T->key*p[cnt(T->tl)] + 1LL*_hash(T->tr)*p[cnt(T->tl)+1], MOD);
    }
}

pnode Merge(pnode& L, pnode& R) {
    if (!L || !R) { return L ? L : R; }
    bool LIsRoot = rand()%(L->cnt+R->cnt+1) > R->cnt;
    if (LIsRoot) {
        L->tr = Merge(L->tr, R);
        upd(L); return L;
    } else {
        R->tl = Merge(L, R->tl);
        upd(R); return R;
    }
}

void Split(pnode T, int k, pnode& L, pnode& R) {
    if (!T) { return void(L = R = nullptr); }
    if (k < cnt(T->tl)+1) {
        Split(T->tl, k, L, T->tl);
        upd(T); R = T;
    } else {
        Split(T->tr, k-cnt(T->tl)-1, T->tr, R);
        upd(T); L = T;
    }
}

// WARNING: 1-indexation
 void Insert(pnode& T, int where, char what) {
     pnode N = BUFF+CNT++;
     N->key = (islower(what) ? what-'a' : what-'A')+1;
     N->_hash = N->key;
     pnode L, R;
     Split(T, where-1, L, R);
     L = Merge(L, N);
     T = Merge(L, R);
 }

 void Erase(pnode& T, int where) {
    pnode L, M, R;
    Split(T, where, L, R);
    Split(L, where-1, L, M);
    T = Merge(L, R);
 }

bool Match(pnode& T, int l, int r, const string& s) {
    if (sz(s) != r-l+1) return false;
    int shash = _hash_string(s);
    pnode L, M, R;
    Split(T, l-1, L, R);
    Split(R, r-l+1, M, R);
    Display(M); cout << "\n";
    bool matched = _hash(M) == shash;
    DBN(_hash(M), shash);
    R = Merge(M, R);
    T = Merge(L, R);
    return matched;
}

int main(){
    fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    initialize();
    string s; cin >> s;
    for (int i = 0; i < sz(s); i++) {
        pnode N = BUFF+CNT++;
        N->key = (s[i]-'a')+1;
        N->_hash = (s[i]-'a')+1;
        Root = Merge(Root, N);
    }
    print(Match(Root, 1, 3, "aba"));
    Erase(Root, 3);
    print(Match(Root, 1, 3, "aba"));
    Insert(Root, 3, 'c');
    print(Match(Root, 1, 3, "aba"));
    return 0;
}
