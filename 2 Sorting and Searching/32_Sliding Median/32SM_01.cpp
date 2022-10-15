#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
// *( .find_by_order(i)) returns iterator to ith element, so use *
// .order_of_key(k) returns number of items strictly < k
// .find(val) doesn't work, so use .find_by_order(mset.order_of_key(val))

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PB push_back
#define MP make_pair
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

  int k;
  cin>>n>>k;
  vi v(n);
  for_(i,0,n) cin>>v[i];

  ordered_multiset mset;
  for_(i,0,k) mset.insert(v[i]);
  cout<<*mset.find_by_order((k-1)/2)<<" ";
  for_(i,k,n){
    mset.erase(mset.find_by_order(mset.order_of_key(v[i-k])));
    // mset.erase(mset.lower_bound(v[i-k]));
    mset.insert(v[i]);
    cout<<*mset.find_by_order((k-1)/2)<<" ";
  }

  return 0;
}
