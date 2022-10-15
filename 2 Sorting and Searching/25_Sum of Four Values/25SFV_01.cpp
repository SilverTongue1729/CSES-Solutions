#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// *( .find_by_order(i)) returns iterator to ith element, so use *
// .order_of_key(k) returns number of items strictly < k

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)(a.size())
#define LIM1 300005
// #define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef array<int, 2> ii;

int i,j,t,n;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  int x;
  cin >> n >> x;
  vector<pi> v(n);
  for_(i,0,n) cin >> v[i].ff, v[i].ss = i+1;
  sort(all(v));

  int val=0,val1=0;
  for_(j,0,n-3){
    val1 = x-v[j].ff;
    if (val1 <= 0) break;
    for_(i,j+1,n-2){
      val = val1-v[i].ff;
      if (val <= 0) break;
      int lb=i+1,ub=n-1;
      while (lb<ub && v[lb].ff+v[ub].ff!=val)
        (v[lb].ff+v[ub].ff<val) ? lb++ : ub--;
      if (v[lb].ff+v[ub].ff==val && lb!=ub){
        printf("%d %d %d %d", v[j].ss,v[i].ss,v[lb].ss,v[ub].ss);
        return 0;
      }
    }
  }
  printf("IMPOSSIBLE");

  return 0;
}
