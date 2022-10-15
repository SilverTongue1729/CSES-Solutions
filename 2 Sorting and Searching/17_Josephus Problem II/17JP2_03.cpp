// This program uses set and gives TLE
// 01 uses ordered_set from gnu pbds
// 02 uses two vectors to reduce effect of erase
// 04 uses only one vector and hence gives TLE
#include <bits/stdc++.h>
using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
typedef set<int> si;

int i,n,k,pos;
si nums;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for_(i,0,n) nums.insert(i+1);

  while (n){
    auto t = next(nums.begin(),(pos = (pos+k) % n--));
    cout << *t << ' ';
    nums.erase(t);
  }

  return 0;
}
