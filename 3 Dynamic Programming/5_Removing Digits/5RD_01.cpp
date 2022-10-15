// This is the greedy solution which is easier
// 02 has the dp solution

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define indexed_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define MOD1 1000000007
// #define DEBUG
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef array<int, 2> ii;

int i,j,t,n;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin>>n;
  int ans=0;
  while (n){
    int mv=0,tn=n;
    while (tn){
      mv = max(mv,tn%10);
      tn/=10;
    }
    n-=mv;
    ans++;
  }
  cout<<ans;

  return 0;
}
