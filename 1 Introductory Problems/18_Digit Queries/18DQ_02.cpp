#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

ll i,j,t,n,ans,q;
ll k,kred;
vl pow10arr(21,1);

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  for_(i,1,21)
    pow10arr[i] = pow10arr[i-1]*10;

  cin >> q;
  while(q--){
    cin >> k;

    kred = k;
    for (i=1,kred=k;kred>0;i++)
      kred-=i*9*pow10arr[i-1];
    i--;
    kred+=i*9*pow10arr[i-1];
    i--;
    ans = ((kred/(i+1))/(ll)pow10arr[(-1*kred+1)%(i+1)+i]) % 10;
    if (kred%(i+1)==0 && i!=0)
      ans--;
    else if (kred%(i+1)==1)
      ans++;
    if (ans<0)
      ans+=10;

    printf("%lld\n", ans);
  }

  return 0;
}
