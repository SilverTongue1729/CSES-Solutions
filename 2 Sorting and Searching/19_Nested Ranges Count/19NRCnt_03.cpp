// First Attempt gives TLE
// Because instead of sorting twice for each direction
// I only sorted once and tried to do something using another set for the opposite direction
// 01 is the solution after reading 02

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define indexed_multiset tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// *( .find_by_order(i)) returns iterator to ith element, so use *
// order_of_key(k) returns number of items strictly < k
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
vvi v(LIM1,vi(5,0));
msi countset;

bool compare1(const vi& v1, const vi& v2){
  return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);  // first column is sorted in ascending
}                                                              // second column is sorted in descending

bool compare2(const vi& v1, const vi& v2){
  return v1[2] < v2[2];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("/home/sriteja/Programming/Random/input_01.txt","r",stdin);
  #endif

  cin >> n;
  for_(i,0,n){ cin >> v[i][0] >> v[i][1]; v[i][2] = i;}
  sort(v.begin(),v.begin()+n,compare1);

  for_(i,0,n){
    mset.insert(v[i][1]);
    // countset.insert(v[i][1]);
    v[i][4] = i - mset.order_of_key(v[i][1]);
    // cout << v[i][4] << '=' << mset.size() << '-' << mset.order_of_key(v[i][1]) << "-1\t" << " inserted " << v[i][1] << '\n';
  }
  mset.clear();
  // cout << '\n';
  sort(v.begin(),v.begin()+n,compare1);

  for_(i,n-1,-1){
    mset.insert(v[i][1]);
    countset.insert(v[i][1]);
    v[i][3] = countset.count(v[i][1]) + mset.order_of_key(v[i][1]) - 1;
    // cout << v[i][4] << '=' << count(all(mset),v[i][1]) << '+' << mset.order_of_key(v[i][1]) << "-1\t" << " inserted " << v[i][1] << '\n';
  }

  sort(v.begin(),v.begin()+n,compare2);

  for_(i,0,n) cout << v[i][3] << ' '; cout << '\n';
  for_(i,0,n) cout << v[i][4] << ' ';

  return 0;
}
