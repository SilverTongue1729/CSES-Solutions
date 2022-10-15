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
typedef array<int, 2> ii;

int i,t,n,c;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin >> n;
  vector<tuple<int,char,int>> v(2*n);
  int a,b;
  for_(i,0,n){
    cin >> a >> b;
    v[2*i] = {a,'1',i};
    v[2*i+1] = {b,'2',i};
  }

  sort(all(v));

  stack<int> st;
  for_(i,n-1,-1) st.push(i+1);
  vi ans(n);
  int cur=0,maxcur=0;
  for (auto j : v){
    if (get<1>(j) == '1'){
      cur++;
      ans[get<2>(j)] = st.top();
      st.pop();
    }
    else{
      cur--;
      st.push(ans[get<2>(j)]);
    }
    maxcur = max(maxcur,cur);
  }

  cout << maxcur << '\n';
  for_(i,0,n) cout << ans[i] << ' ';

  return 0;
}
