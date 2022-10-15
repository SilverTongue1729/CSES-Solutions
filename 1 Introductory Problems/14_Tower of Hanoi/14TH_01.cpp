// This the better method, similar to 13GC_01
// The other method would to store moves and exchange the correct numbers (2 and 3, then 1 and 2)
// Look at 13GC_02 which is very similar
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

void tower(int l,int a,int b){
  if (!l) return;
  tower(l-1,a,(2*a-b+2)%3+1);
  cout << a << " " << b << '\n';
  tower(l-1,(2*a-b+23)%3+1,b);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  cout << (int)pow(2,n)-1 << '\n';
  tower(n,1,3);

  return 0;
}
