// Revisited later

#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
#define MP make_pair
#define ff first
#define ss second
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c,ans,x,del;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin >> n >> x;
  vector<pair<int,int>> v(n);
  for_(i,0,n-del){
    cin >> t;
    v[i] = {t,0};
    if (v[i].ff >= x){
      i--; del++;
      continue;
    }
    v[i].ss = i+del+1;
  }

  if (n-del==0){
    cout << "IMPOSSIBLE";
    return 0;
  }

  sort(all(v)-del);

  i=0; j=n-del-1;
  while (i<j){
    if (2*v[j].ff < x){
      cout << "IMPOSSIBLE";
      return 0;
    }
    else if (v[i].ff+v[j].ff<x) i++;
    else if (v[i].ff+v[j].ff>x) j--;
    else{
      cout << v[i].ss << ' ' << v[j].ss;
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
