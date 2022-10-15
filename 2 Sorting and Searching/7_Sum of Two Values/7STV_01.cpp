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

int i,j,t,n,c,ans,x,del;
int a[(int)2e5+3][2];

int temp2[(int)2e5+3][2];
void merge_sort(int s, int e, int arr[][2]){
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

  cin >> n >> x;
  for_(i,0,n-del){
    cin >> a[i][0];
    if (a[i][0] >= x){
      i--; del++;
      continue;
    }
    a[i][1] = i+del+1;
  }
  if (n-del==0){
    cout << "IMPOSSIBLE";
    return 0;
  }

  merge_sort(0,n-del,a);

  i=0; j=n-del-1;
  while (i<j){
    if (2*a[j][0] < x){
      cout << "IMPOSSIBLE";
      return 0;
    }
    else if (a[i][0]+a[j][0]<x)
      i++;
    else if (a[i][0]+a[j][0]>x)
      j--;
    else{
      cout << a[i][1] << ' ' << a[j][1];
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
