#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
typedef long long ll;
typedef vector<int> vi;

int i,j,k,t,n,a,b,x,y;
int arr[30];
ll ans;

int main(){
  #ifdef mlocal
    freopen("test.in", "r", stdin);
  #endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;

  for_(i,0,30){
    arr[i] = n&1;
    n>>=1;
  }

  ans=1;
  for_(i,30,-1)
    ans = ans*ans*(arr[i]+1) % MOD1;

  cout << ans;

  return 0;
}
