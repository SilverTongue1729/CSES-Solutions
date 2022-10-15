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

int i,j,t,n,c;
ll ans,p[(int)2e5+1];

ll temp[(int)2e5+1];
void merge_sort(int s, int e, ll arr[]){
  if (e-s==1) return;
  merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
  for_(i,s,(s+e)/2) temp[i] = arr[i];
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp[i] < arr[j])
      arr[i+j-1-(s+e)/2] = temp[i++];
    else
      arr[i+j-1-(s+e)/2] = arr[j++];
  while (i<(s+e)/2) arr[i+j-1-(s+e)/2] = temp[i++];
  while (j<e) arr[i+j-1-(s+e)/2] = arr[j++];
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  for_(i,0,n) cin >> p[i];
  merge_sort(0,n,p);
  for_(i,0,n) ans += abs(p[i]-p[(n+1)/2-1]);
  cout << ans;

  return 0;
}
