#include <bits/stdc++.h>

using namespace std;

#define for_(i,s,e) for ( i=s; ((i<e)&&(s<e))||((i>e)&&(s>=e)); (s<e)?i++:i--)
#define all(x) x.begin(),x.end()
#define MOD1 1000000007
#define MOD2 998244353
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pi;

#define N 8

int i,j,t,n,c,ans;
vvi res(N,vi(N,0));
vi col(N,0),ldiag(2*N-1,0),rdiag(2*N-1,0);

void queen(int rw){
  int cl;
  if (rw==N){
    ans++;
    return;
  }
  for_(cl,0,N){
    if (res[rw][cl])
      continue;
    if (!(col[cl]||ldiag[N-1-rw+cl]||rdiag[rw+cl])){
      col[cl] = ldiag[N-1-rw+cl] = rdiag[rw+cl] = 1;
      queen(rw+1);
      col[cl] = ldiag[N-1-rw+cl] = rdiag[rw+cl] = 0;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for_(i,0,N){
    for_(j,0,N)
      res[i][j] = getchar()-'.';
    getchar();
  }

  queen(0);
  cout << ans;

  return 0;
}
