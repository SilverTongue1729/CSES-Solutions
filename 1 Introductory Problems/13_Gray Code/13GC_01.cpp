// This the better method
// 02 requires more memory
#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,k,t,n,var;

void bin_print(){
  for_(i,n,0)
    putchar((bool)(var & (1<<i))+'0');
  putchar('\n');
}

void graycode(int l){
  if (l<1) return;
  graycode(l-1);
  var ^= (1<<l);
  bin_print();
  graycode(l-1);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  bin_print();
  graycode(n);

  return 0;
}
