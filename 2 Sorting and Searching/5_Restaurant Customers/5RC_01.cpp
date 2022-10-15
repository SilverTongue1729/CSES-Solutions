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

int i,j,t,n,c,ans,cur;
int times[(int)4e5+1][2],temp[(int)4e5+1][2];

void merge_sort(int s, int e, int arr[][2]){
  if (e-s==1) return;
  merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
  for_(i,s,(s+e)/2){ temp[i][0] = arr[i][0]; temp[i][1] = arr[i][1];}
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp[i][0] < arr[j][0]){
      arr[i+j-(s+e)/2][0] = temp[i][0];
      arr[i+j-(s+e)/2][1] = temp[i][1];
      i++;
    }
    else{
      arr[i+j-(s+e)/2][0] = arr[j][0];
      arr[i+j-(s+e)/2][1] = arr[j][1];
      j++;
    }
  while (i<(s+e)/2){
      arr[i+j-(s+e)/2][0] = temp[i][0];
      arr[i+j-(s+e)/2][1] = temp[i][1];
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
    cin >> times[2*i][0] >> times[2*i+1][0];
    times[2*i][1] = 1; times[2*i+1][1] = 0;
  }
  merge_sort(0,2*n,times);

  for_(i,0,2*n){
    if (times[i][1] == 1) cur++;
    else cur--;
    ans = max(ans,cur);
  }
  cout << ans;

  return 0;
}
