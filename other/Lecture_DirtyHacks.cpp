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
#define INF (numeric_limits<int>::max())
#define MINF (numeric_limits<int>::min())
#define LINF (numeric_limits<long long>::max())
#define LMINF (numeric_limits<long long>::min())
#define EPS (1E-9)
#define PI ((long double)3.14159265358979311600)

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

int read_int(){
 while (*inp && (*inp < '0' || *inp > '9') && *inp != '-') ++inp;
 bool minus = false;
 if (*inp == '-') minus = true, ++inp;
 if (*inp == 0) {
     memset(inbuff, 0, BUFFSIZE);
     cin.read(inbuff, BUFFSIZE);
     inp = inbuff;
 }
 int res = *inp++ - '0';
 if (inp == linp) {
     memset(inbuff, 0, BUFFSIZE);
     cin.read(inbuff, BUFFSIZE);
     inp = inbuff;
 }
 while (*inp >= '0' && *inp <= '9') {
     res = res*10 + *inp - '0';
     ++inp;
     if (inp == linp) {
         memset(inbuff, 0, BUFFSIZE);
         cin.read(inbuff, BUFFSIZE);
         inp = inbuff;
     }
 }
 return minus ? -res : res;
}
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

// Битовое сжатие
// Значение динамики -- битовая маска
// Вместо булевого массива обрабатываем битовые маски
// Оптимизирует время работы как по константе, так и по асимптотике

void Example1() {
// Транзитивное замыкание графа по булевской матрице смежности
// для каждой вершины v исходного графа G(V, E)
// добавить ребро в вершину u, если u достижима из v

// // Наивное решение
   int n; cin >> n;
//    auto G = tensor<bool>(n, n);
// // Алгоритм Флойда-Уоршелла
//    read(G);
//     for (int k = 0; k < n; k++) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 G[i][j] |= G[i][k] && G[k][j];
//             }
//         }
//     }
// // Оптимизированное решение
    // auto b = tensor<bitset<1000>>(1000);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         int x; cin >> x;
    //         b[i][j] = x;
    //     }
    // }
    // // b[i] -- все вершины, достижимые из i-ой
    // for (int k = 0; k < n; k++) {
    //     for (int i = 0; i < n; i++) {
    //         if (b[i][k]) {
    //             b[i] | b[k];
    //         }
    //     }
    // }
//  // Оптимизированное решение, рукописный битсет
    auto b = tensor<int>(1000, 1000/32+1);
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int x; cin >> x;
            if (x) {
                b[i][j/32] |= 1 << (j%32); 
            }
        } 
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (b[i][k]) {
                for (int j = 0; j < n/32+1; j++) {
                    b[i][j] |= b[k][j];
                }
            }
        }
    }
}

void Example2() {   // задача о рюкзаке
    // самая простая реализация, может упасть на TL
    int n; // <= 10 000
    cin >> n;
    vector<int> a(n);
    read(a);
    // заведём булевский массив для всех сумм, которые мы можем набрать
    int s; cin >> s;   // 100 000
    // vector<bool> d(100001);
    // for (int i = 0; i < n; i++) {
    //     int x = a[i];
    //     for (int j = s-x; j >= 0; j--) {    // цикл идёт в обратную сторону
    //         if (d[j]) { d[j+x] = true; }    // чтобы каждый предмет взять не более одного раза
    //     }
    // }
    // оптимизация: вместо d будем хранить bitset
    bitset<100100> d;
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        // но здесь нужно учесть, что в rvalue каждый раз создаётся новый объект
        d |= d << a[i]; // сложение в наивное реализации, по сути сдвигает бит на x
                        // такая реализация позволяет сдвинуть на x за одну операцию сразу ВСЕ позиции

    }   
}

void Example3() { // пихать 200 000 * 400 000 за секунду
    // даны две битовые строки s1, s2
    // дан запрос: p1, p2, len
    // нужно посмотреть на подстроки s1[p1:p1+len-1], s2[p2:p2+len-1]
    // и подсчитать расстояние Хэмминга между ними

    // наивное решение
    // string a, b;
    // cin >> a >> b;
    // int q; cin >> q;
    // for (int t = 0; t < q; ++t) {
    //     int x, y, len;
    //     cin >> x >> y >> len;
    //     int ans = 0;
    //     for (int i = 0; i < len; i++) {
    //         ans += (a[x+i] != b[y+i]);
    //     }
    // }

    // оптимизация: хранить "битсеты" вместо строк
    // сравнивать сразу группы побайтово
    // чтобы эффективно разбивать на блоки и подсчитывать ответ на пересечении
    // построим для каждой строки ВОСЕМЬ побитовых сжатий: в зависимости от позиции левой границы
    // суффикса в числе (8 бит начиная с нулевого, с первого, ..., с седьмого)
}

void Example4() {
    // Наивное решение с подсчётом времени работы
    vector<int> a(101010);
    int n = read_int();
    for (int i = 0; i < n; i++) {
        a[i] = read_int();
    }
    int q; q = read_int();
    double begin = clock();
    ll answ = 0;
    while (--q) {
        int t, x, y;
        t = read_int();
        x = read_int();
        y = read_int();
        --x, --y;
        if (t == 1) {
            while (x<y && x%16) {
                answ += a[x++];
            }
            while ((y-x+1)%16) {
                answ += a[y--];
            }

            int *ap = a+x;
            int k = y-x+1;
            // развёртывание цикла
            // if -- завтратная процессорная операция
            // нужно минимизировать количество обращений к ней
            const int T = 8;
            int kT = k/T;
            int rT = kT;
            __m128i *ptr = (__m128i*)ap;

            while(rT > 0) {
                kT = min(rT, 256);  // за счёт того, что числа меньше 10^6
                rT -= kT;           // мы можем суммировать по 2000 интов до переполнения
                                    // при суммировании с использованием SSE мы суммируем сразу чанки по 8 элементов
                                    // поэтому можем просуммировать 2000/8 ~ 256 блоков по 8 
                int s = 0;
                __m128i sum = __mm_set1_epi32(0);
                int kT4 = kT/4;
                while (kT4--) {
                    sum = _mm_add_epi32(ptr[0], sum);
                    sum = _mm_add_epi32(ptr[1], sum);
                    sum = _mm_add_epi32(ptr[2], sum);
                    sum = _mm_add_epi32(ptr[3], sum);
                    ptr += 4;
                }
                int *asum = (int*)&sum;
                answ += (ll)asum[0] + asum[1] + asum[2] + asum[3];
            }
        } else {
            int val; 
            scanf("%d", &val);

            while (x<y && x%16) {
                a[x] ^+ val;
                ++x;
            }

            while ((y-x+1)%16) {
                a[y] ^= val;
                --y;
            }

            // Магия SSE
            int *ap = a+x
            int k = y-x+1;
            const int T = 4;
            int kT = k/T;

            __m128i *ptr = (__m128i*) ap;
            __m128i mask = __mm_set1_epi32(val);
    
            int kT4 = kT/4;

            while(kT4--) {
                __m128i res = _mm_xor_si128(*ptr, mask);
                __mm_store_si128(ptr, res);
                ++ptr;
                res = _mm_xor_si128(*ptr, mask);
                __mm_store_si128(ptr, res);
                ++ptr;
                res = _mm_xor_si128(*ptr, mask);
                __mm_store_si128(ptr, res);
                ++ptr;
                res = _mm_xor_si128(*ptr, mask);
                __mm_store_si128(ptr, res);
                ++ptr;
            }
        }
    }
    double end = clock();
    cout << (end-begin)/CLOCK_PER_SEC << endl;
}

// Усложнённая задача "Коробки": dp[N][K] = s, N -- длина суффикса
//                                             K -- сколько коробок взяли
//                                             S -- минимальный суммарный вес
// пересчитывать аналогично НВП (O(N log N))
// сначала -- жадная сортировка, потом -- динамика
// принцип: порядок в корректном ответе совпадает с порядком сортировки
// инвариант: для любого корректного подмножества ответ можно получить жадно

// основа решения жадными алгоритмами -- правильно придумать компаратор

int main(){
    // fastIO();
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);
    return 0;
}
