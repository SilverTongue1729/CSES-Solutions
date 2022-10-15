#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

ll t,i,j,k,n,m,a,b,ans;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> t;
  while(t--){
    cin >> a >> b;
    (((a+b)%3==0) && ((a>=b&&a<=2*b) || (b>a&&b<=2*a))) ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
