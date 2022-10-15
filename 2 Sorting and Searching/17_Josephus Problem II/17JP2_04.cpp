// Gives TLE as it uses vector and erase() is O(N) not O(logN)
// 01 uses ordered_set from gnu pbds
// 02 splits vector into 2 parts to reduce effect of erase
// 03 uses set and gives TLE
#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
typedef vector<int> vi;

int i,n,k,pos;
vi nums;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  nums.resize(n);
  for_(i,0,n) nums[i] = i+1;

  while (n){
    pos = (pos+k) % n--;
    cout << nums[pos] << ' ';
    nums.erase(nums.begin()+pos);
  }

  return 0;
}
