// This method requires more memory
// 01 is the better method
#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,k,l,t,n;

void bin_print(int k){
  for_(l,n-1,-1)
    putchar((bool)(k & (1<<l))+'0');
  putchar('\n');
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  vi arr(1<<n,0);
  bin_print(0);
  for_(i,0,n)
    for_(j,(1<<i),0)
      bin_print(arr[(1<<(i+1))-j] = (1<<i) + arr[j-1]);

  return 0;
}
