// See https://codeforces.com/blog/entry/83295
//
// Try to think of calculating costs by adding distance between pairs of elements (from opposite ends)
// so 1 3 4 6 7 8 is (8-1)+(7-3)+(6-4)
// and try to calculate the change in cost after each step
// when erasing, the change is -abs(element-median)
// when inserting, the change is abs(element-median)
// by looking at examples, you can see that this will work out
// except when window size is even
// In that case you need to subtract (curmed - prevmed) from the costs
// You can see that this works out by trying out different cases
// if prevmed==curmed then you don't need to subtract anything because
// this means that both the inserted and deleted elements were on the same side of the median so
// any differences in the initial change calculation will be adjusted
// if prev!=curmed then elements are on different sides so
// then you need to perform the subtraction to compensate for the inaccuracies in the initial change
// the subtraction works perfectly because prevmed and curmed have to be consecutive elements

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

  ll k;
  cin>>n>>k;
  vi v(n);
  for_(i,0,n) cin>>v[i];

  ll sum=0,med=0;
  ordered_multiset mset;
  for_(i,0,k) mset.insert(v[i]);
  med = *mset.find_by_order((k-1)/2);
  for (auto itr:mset) sum += abs(itr-med);
  cout<<sum<<" ";
  for_(i,k,n){
    sum-=abs(v[i-k]-med);
    if ((k&1)==0) sum+=med;
    *mset.erase(mset.find_by_order(mset.order_of_key(v[i-k])));

    mset.insert(v[i]);
    med = *mset.find_by_order((k-1)/2);
    sum+=abs(v[i]-med);
    if ((k&1)==0) sum-=med;
    cout<<sum<<" ";
  }

  return 0;
}
