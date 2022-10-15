// This program uses two vectors to reduce effect of erase
// 01 uses ordered_set from gnu pbds
// 03 uses set and gives TLE
// 04 uses only one vector and hence gives TLE
#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
typedef vector<int> vi;

int i,n,k,pos,n1,n2;
vi nums,nums1,nums2;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  n1 = n/2; n2 = (n+1)/2;
  nums1.resize(n1); nums2.resize((n+1)/2);
  for_(i,0,n1) nums1[i] = i+1; for_(i,0,n2) nums2[i] = i+n1+1;

  while (n){
    pos = (pos+k) % n--;
    if (pos < n1){
      cout << nums1[pos] << ' ';
      nums1.erase(nums1.begin()+pos);
      n1--;
    }
    else{
      cout << nums2[pos-n1] << ' ';
      nums2.erase(nums2.begin()+pos-n1);
      n2--;
    }
  }

  return 0;
}
