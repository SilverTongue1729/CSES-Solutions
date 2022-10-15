// After reading 02 which is from solutions
// This just sorts in two

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// *( .find_by_order(i)) returns iterator to ith element, so use *
// .order_of_key(k) returns number of items strictly < k
indexed_multiset mset;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define endl '\n'
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define MOD1 1000000007
#define LIM1 300005
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef set<int> si;
typedef multiset<int> msi;
typedef pair<int,int> pi;

int i,j,t,n,c;
msi countset;

bool compare1(const vi& v1, const vi& v2){
  return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);  // first column is sorted in ascending
}                                                               // second column is sorted in descending

bool compare2(const vi& v1, const vi& v2){
  return (v1[1] < v2[1]) || (v1[1] == v2[1] && v1[0] > v2[0]);  // first column is sorted in descending
}                                                               // second column is sorted in ascending

bool compare3(const vi& v1, const vi& v2){
  return v1[2] < v2[2];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin >> n;
  vvi v(n,vi(4,0));
  for_(i,0,n) cin >> v[i][0] >> v[i][1], v[i][2] = i; // v[i][3] contains the answers

  sort(all(v),compare2);  // sort based on second column
  for_(i,0,n){
    mset.insert(v[i][0]);
    v[i][3] = i - mset.order_of_key(v[i][0]);
  }
  sort(all(v),compare3);
  for_(i,0,n) cout << v[i][3] << ' '; cout << '\n';

  mset.clear();

  sort(all(v),compare1);  // sort based on first column
  for_(i,0,n){
    mset.insert(v[i][1]);
    v[i][3] = i - mset.order_of_key(v[i][1]);
  }
  sort(all(v),compare3);
  for_(i,0,n) cout << v[i][3] << ' ';

  return 0;
}
