#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
#define LIM1 (int)3e5+5
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

int i,j,t,n,c,ans,arr[LIM1][2],lens[LIM1];

int temp2[(int)2e5+1][2];
void merge_sort(int s, int e, int arr[][2]){  // slightly modified for this problem
  if (e-s==1) return;
  merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
  for_(i,s,(s+e)/2){ temp2[i][0] = arr[i][0]; temp2[i][1] = arr[i][1];}
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp2[i][0] < arr[j][0] || ((temp2[i][0] == arr[j][0]) && (temp2[i][1] < arr[j][1]))){
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
  for_(i,0,n){
    cin >> arr[i][0];
    arr[i][1] = i+1;
    lens[i+1] = n-i;
  }
  merge_sort(0,n,arr);

  for_(i,0,n-1)
    if (arr[i][0]==arr[i+1][0])
      lens[arr[i][1]] = arr[i+1][1]-arr[i][1];

  for_(i,n,0){
    lens[i] = min(lens[i],lens[i+1]+1);
    ans = max(ans,lens[i]);
  }

  cout << ans;

  return 0;
}
