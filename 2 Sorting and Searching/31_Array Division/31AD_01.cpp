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

int i,j,t,n,k;

int check(ll msum,vi& vec){
  ll cnt=0,sum=0;
  for_(i,0,n){
    sum += vec[i];
    if (sum>msum){
      if (++cnt==k || vec[i]>msum) return 0;
      sum = vec[i];
    }
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin>>n>>k;
  vi v(n);
  for_(i,0,n) cin>>v[i];
  ll lb=0,ub=2e14,mid;
  while (lb<ub){
    mid = lb+(ub-lb)/2;
    // cout<<"lb="<<lb<<" mid="<<mid<<" ub="<<ub<<endl;
    if (check(mid,v))
      ub = mid;
    else
      lb = mid+1;
  }
  cout<<lb;

  return 0;
}
