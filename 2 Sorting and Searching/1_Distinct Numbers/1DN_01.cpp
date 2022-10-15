#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int t,n,c,ans,i,j;
vi vec(2e5+1,0),temp(2e5+1,0);

void merge(int s, int e){
  if (e-s==1) return;
  merge(s,(s+e)/2); merge((s+e)/2,e);
  for_(i,s,(s+e)/2) temp[i] = vec[i];
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp[i] < vec[j])
      vec[i+j-1-(s+e)/2] = temp[i++];
    else
      vec[i+j-1-(s+e)/2] = vec[j++];
  while (i<(s+e)/2) vec[i+j-1-(s+e)/2] = temp[i++];
  while (j<e) vec[i+j-1-(s+e)/2] = vec[j++];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  for_(i,0,n) cin >> vec[i];

  merge(0,n);

  for_(i,1,n) if (vec[i]!=vec[i-1]) ans++;
  cout << ans+1;

  return 0;
}
