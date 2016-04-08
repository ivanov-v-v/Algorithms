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
#define EPS (double)1e-9
#define PI (long double)3.14159265358979311600

/*TYPES*/
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
template<class T1, class T2> istream& operator >>(istream& in, pair<T1, T2>& P){in >> P.fst >> P.scd; return in;}
template<class T> istream& operator >>(istream& in, vector<T>& Col){for(auto &el : Col) in >> el; return in;}

//STL OUTPUT
template<class T1, class T2> ostream& operator <<(ostream& os, const pair<T1, T2>& p){os << "(" << p.fst << ", " << p.scd << ")"; return os;}
template<class T> ostream& operator <<(ostream& os, const vector<vector<T>>& v){for(auto &row : v){ for(auto &el : row) os << el << " "; os << "\n";} return os;}
template<class T> ostream& operator <<(ostream& os, const vector<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T> ostream& operator <<(ostream& os, const set<T>& Col){for(auto &el : Col) os << el << " "; return os;}
template<class T1, class T2> ostream& operator <<(ostream& os, const map<T1, T2>& Col){for(auto &el : Col) os << el << " "; return os;}

//VARIADIC INPUT
template<typename First> void read(First& t){ cin >> t; }
template<typename First, typename... Args> void read(First& f, Args&... args){ cin >> f; read(forward<Args&>(args)...); }

//VARIADIC OUTPUT
template<typename T> void print(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void print(First&& f, Args&&... args){ cout << f << " "; print(forward<Args&&>(args)...); }
template<typename T> void printLn(T&& t){ cout << t << "\n"; }
template<typename First, typename... Args> void printLn(First&& f, Args&&... args){ cout << f << "\n"; printLn(forward<Args&&>(args)...); }

//VARIADIC TYPE DECLARATION
template <typename T, size_t N> struct MakeTensor{ template <typename... Args> static auto make_tensor(size_t first, Args... sizes) -> vector<decltype(MakeTensor<T, N-1>::make_tensor(sizes...))> { auto inner = MakeTensor<T, N-1>::make_tensor(sizes...); return vector<decltype(inner)>(first, inner);} };
template <typename T> struct MakeTensor<T, 1> { static vector<T> make_tensor(size_t size) { return vector<T>(size); }};
template <typename T, typename... Args> auto make_tensor(Args... args) -> decltype(MakeTensor<T, sizeof...(Args)>::make_tensor(args...)){ return MakeTensor<T, sizeof...(Args)>::make_tensor(args...); }

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

//#define DEBUG

//EXTREMELY FAST I/O
//const int BUFFSIZE = 2048;
//static char inbuff[BUFFSIZE + 16];
//static char *inp = inbuff;
//static char *linp = inbuff + BUFFSIZE;
//
//int read_int(){
//	while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
//	bool minus = false;
//	if (*inp == '-') minus = true, ++inp;
//	if (*inp == 0) {
//		memset(inbuff, 0, BUFFSIZE);
//		cin.read(inbuff, BUFFSIZE);
//		inp = inbuff;
//	}
//	int res = *inp++ - '0';
//	if (inp == linp) {
//		memset(inbuff, 0, BUFFSIZE);
//		cin.read(inbuff, BUFFSIZE);
//		inp = inbuff;
//	}
//	while (*inp >= '0' && *inp <= '9') {
//		res = res*10 + *inp - '0';
//		++inp;
//		if (inp == linp) {
//			memset(inbuff, 0, BUFFSIZE);
//			cin.read(inbuff, BUFFSIZE);
//			inp = inbuff;
//		}
//	}
//	return minus ? -res : res;
//}
//
//static char outbuff[BUFFSIZE + 16];
//static char *outp = outbuff;
//static char *loutp = outbuff+BUFFSIZE;
//
//void write_int(int x, bool last = false) {
//	char *begp = outp;
//	if (x == 0) {
//        *outp++ = '0';
//	}
//	while(x) {
//		int quot = x/10;
//		char c = x - 10*quot + '0';
//		*outp++ = c;
//		x = quot;
//	}
//	char *endp = outp-1;
//	while(begp < endp) {
//		swap(*begp, *endp);
//		++begp, --endp;
//	}
////	*outp++ = '\n';
//	if (last || outp > loutp) {
//		cout.write(outbuff, outp - outbuff);
//		outp = outbuff;
//	}
//}
//

void fastIO(){ ios::sync_with_stdio(false); cin.tie(nullptr); }

// const int MAXN = 1e5;
// int a[MAXN+1];
// int t[4*MAXN+1];

// void build(int v = 1, int tl = 0, int tr = MAXN-1) {
// 	if (tl == tr) {
// 		t[v] = a[tl];
// 		return;
// 	}
// 	int tm = (tl + tr)/2;
// 	build(2*v, tl, tm);
// 	build(2*v+1, tm+1, tr);

// 	t[v] = t[2*v] + t[2*v+1];
// }

// void update(int pos, int val, int v = 1, int tl = 0, int tr = MAXN-1) {
// 	if (tl == tr) {
// 		t[v] = val;
// 		return;
// 	}
// 	int tm = (tl + tr)/2;
// 	if(pos <= tm) {
// 		update(pos, val, 2*v, tl, tm);
// 	}
// 	else {
// 		update(pos, val, 2*v+1, tm+1, tr);
// 	}
// 	t[v] = t[2*v]+t[2*v+1];
// }

// int get(int l, int r, int v = 1, int tl = 0, int tr = MAXN-1) {
// 	if (tl == l && tr == r) {
// 		return t[v];
// 	}
// 	int tm = (tl + tr)/2;
// 	return get(l, min(tm, r), 2*v, tl, tm) + get(max(l, tm+1), r, 2*v+1, tm+1, tr);
// }

//IMPLICIT SEGMENT TREE

//const int N = 1e5;
//int tr[N*32];
//int lp[N*32];
//int rp[N*32];
//int a[N+1000];
//int root = 1;
//int lastn = 2; //номер последней неиспользованной вершины
//
////NO BUILD
//
//void update(int& cur, int l, int r, int pos, int val) {
//	if (cur == 0) {
//		cur = lastn++;
//	}
//	if (l == r) {
//		tr[cur] = val;
//	} else {
//		int m = (l + r)/2;
//		if (pos <= m) {
//			update(lp[cur], l, m, pos, val);
//		} else {
//			update(rp[cur], m+1, r, pos, val);
//		}
//		tr[cur] = tr[lp[cur]] + tr[rp[cur]];
//	}
//}
//
//int get_sum(int cur, int l, int r, int x, int y) {
//		if (cur == 0) {
//			return 0;
//		}
//		if (l == x && r == y) {
//			return tr[cur];
//		} else {
//			int m = (l + r)/2;
//			if (y <= m) {
//				return get_sum(lp[cur], l, m, x, y);
//			} else if(x > m) {
//				return get_sum(rp[cur], m + 1, r, x, y);
//			} else {
//				return get_sum(lp[cur], l, m, x, m) + get_sum(rp[cur], m+1, r, m+1, y);
//			}
//		}
//}

//задача с NEERC: решение неявным ДО + покраска на отрезке + запрос значения в точке
//ЭЙЛЕРОВ ОБХОД ГРАФА

//const int MAXV = 1e5;
//vector<int> G[MAXV];
//int tin[MAXV];
//int tout[MAXV];
//int curt = 0;
//void go(int v) {
//    tin[v] = curt++;
//    for (auto u : G[v]) {
//        go(u);
//    }
//    tout[v] = curt;
//}


//Неявное ДО отличается отсутствием функции  build
//PERSISTENT SEGMENT TREE
const int N = 1e5;
int tr[N];
int lp[N];
int rp[N];
int roots[N];
int lastn = 1; //номер последней неиспользованной вершины

//NO BUILD

void update(int& cur, int l, int r, int pos, int val) {
    //вот и вся персистентность
    lp[lastn] = lp[cur];
    rp[lastn] = rp[cur];
    tr[lastn] = tr[cur];
    //ня, смерть
    cur = lastn++;
	if (l == r) {
		tr[cur] = val;
	} else {
		int m = (l + r)/2;
		if (pos <= m) {
			update(lp[cur], l, m, pos, val);
		} else {
			update(rp[cur], m+1, r, pos, val);
		}
		tr[cur] = tr[lp[cur]] + tr[rp[cur]];
	}
}

int get_sum(int cur, int l, int r, int x, int y) {
		if (cur == 0) {
			return 0;
		}
		if (l == x && r == y) {
			return tr[cur];
		} else {
			int m = (l + r)/2;
			if (y <= m) {
				return get_sum(lp[cur], l, m, x, y);
			} else if(x > m) {
				return get_sum(rp[cur], m + 1, r, x, y);
			} else {
				return get_sum(lp[cur], l, m, x, m) + get_sum(rp[cur], m+1, r, m+1, y);
			}
		}
}


int main(){
//    fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
//    int n, m;
//    read(n, m);
//    for (int i = 1; i <= m; i++) {
//        roots[i] = roots[i-1];
//        int pos, val;
//        read(pos, val);
//        update(roots[i], 0, n-1, pos, val);
//    }
//    int q;
//    read(q);
//    while(q--) {
//        int v, x, y;
//        read(v, x, y);
//        print(get_sum(roots[v], 0, n-1, x, y));

//    }

    return 0;
}
