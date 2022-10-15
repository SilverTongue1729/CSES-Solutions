// This uses binary search
// 02 tries to use math
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

int i,j,t,n;
vector<ll> v(LIM1);

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin >> n >> t;
  for_(i,0,n) cin >> v[i];

  ll lb=0,ub=1e18,mid=0,sum=0;
  while (lb<ub){
    mid = lb/2 + ub/2;
    sum=0;
    for_(i,0,n) sum += min(mid/v[i],(ll)1e9);  // The min is very important (continued below)
    if (sum>=t)
      ub = mid;
    else
      lb = mid+1;
  }
  cout << lb;

  return 0;
}

// because in case like
// 2e5 1e9
// 2e5 1's
// sum will exceed limit of ll
