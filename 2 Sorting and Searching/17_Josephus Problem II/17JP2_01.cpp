// This program uses ordered_set from gnu pbds
// 02 uses two vectors to reduce effect of erase
// 03 uses set and gives TLE
// 04 uses only one vector and hence gives TLE
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// *( .find_by_order(i)) returns iterator to ith element, so use *
// order_of_key(k) returns number of items strictly < k

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)


int i,n,k,pos;
ordered_set nums;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for_(i,0,n) nums.insert(i+1);

  while (n){
    auto t = nums.find_by_order(pos = (pos+k) % n--);
    cout << *t << ' ';
    nums.erase(t);
  }

  return 0;
}
