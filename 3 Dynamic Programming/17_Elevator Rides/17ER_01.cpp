#include <bits/stdc++.h>
using namespace std;

// #define for_(i,s,te) for (ll i=s,e=te; ((i<e)&&(s<e)) || ((i>e)&&(s>=e)); (s<e)?i++:i--)
#define for_(i,s,e) for (ll i=s;i<(ll)e; i++)
#define for__(i,s,e) for (ll i=s;i>(ll)e; i--)
#define mod(x) ((x) % MOD)
#define mid(x) midpoint(x)
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define bg begin()
#define ed end()
#define sz(a) int(a.size())
#define all(x) (x).bg,(x).ed
#define allr(x) x.rbegin(),x.rend()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define nl "\n"
#define _ << ' ' <<
#define pb push_back
#define MP make_pair
#define UB upper_bound
#define LB lower_bound
#define ff first
#define ss second
#define int ll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
// typedef array<int, 2> ii;
const ll MOD = 1e9+7; // 998244353;

template<typename T1, typename T2> inline istream& operator >> (istream& in, pair<T1,T2>& a) { in>>a.first>>a.second; return in; }
template<typename T1, typename T2> inline ostream& operator << (ostream& out, pair<T1,T2> a) { out<<a.first<<" "<<a.second; return out; }
template<typename T> istream& operator >> (istream& in, vector<T>& v) { for_(i,0,sz(v)) cin>>v[i]; return in; }
void read(auto&... args) { ((cin >> args), ...); }
void put(auto&&... args) { ((cout << args << " "), ...); }

#ifdef LOCAL
#include "/home/sriteja/Competitive Programming/Debugging/print.cpp"
#endif

void solve(){
  int n,x; read(n,x);
  vi w(n); read(w);
  


}

signed main(){
#ifdef LOCAL
  freopen("/home/sriteja/Competitive Programming/Random/input_01.txt","r",stdin);
  freopen("/home/sriteja/Competitive Programming/Random/output_01.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tt=1;
  while (tt--) solve();

  return 0;
}
