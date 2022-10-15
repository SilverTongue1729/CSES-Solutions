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
ll ans,x[(int)2e5+1][2];

ll temp2[(int)2e5+1][2];
void merge_sort(int s, int e, ll arr[][2]){
  if (e-s==1) return;
  merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
  for_(i,s,(s+e)/2){ temp2[i][0] = arr[i][0]; temp2[i][1] = arr[i][1];}
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp2[i][0] < arr[j][0]){
      arr[i+j-(s+e)/2][0] = temp2[i][0];
      arr[i+j-(s+e)/2][1] = temp2[i][1];
      i++;
    }
    else{
      arr[i+j-(s+e)/2][0] = arr[j][0];
      arr[i+j-(s+e)/2][1] = arr[j][1];
      j++;
    }
  while (i<(s+e)/2){
      arr[i+j-(s+e)/2][0] = temp2[i][0];
      arr[i+j-(s+e)/2][1] = temp2[i][1];
      i++;
    }
  while (j<e){
      arr[i+j-(s+e)/2][0] = arr[j][0];
      arr[i+j-(s+e)/2][1] = arr[j][1];
      j++;
    }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  for_(i,0,n) cin >> x[i][0];
  merge_sort(0,n,x);

  if (x[0][0]!=1){
    cout << '1';
    return 0;
  }
  x[0][1] = 1;

  for_(i,1,n){
    if (x[i][0]-x[i-1][1]>1){
      cout << x[i-1][1]+1;
      return 0;
    }
    x[i][1] = x[i][0]+x[i-1][1];
  }

  cout << x[i-1][1]+1;

  return 0;
}
