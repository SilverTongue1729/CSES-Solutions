#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int i,j,k,t,n,ans;

int main(){
#ifdef mlocal
  freopen("test.in", "r", stdin);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;

  while(n)
    ans += n/=5;

  cout << ans;

  return 0;
}
