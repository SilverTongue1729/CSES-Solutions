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

int i,j,k,t,n;
ll ans,tsum,mdiff;
vl vec(20,0);

void comb(int l,ll sum){
  if (l==n) return;
  if (abs(tsum-2*(sum+vec[l])) < abs(tsum-2*sum)){
    mdiff = min(mdiff,abs(tsum-2*(sum+vec[l])));
    comb(l+1,sum+vec[l]);
    comb(l+1,sum);
  }
  else
    return;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for_(i,0,n){
    cin >> vec[i];
    tsum+=vec[i];
  }
  sort(vec.begin(),vec.begin()+n);
  mdiff = abs(tsum-2*vec[0]);
  comb(1,vec[0]);
  cout << mdiff;

  return 0;
}
