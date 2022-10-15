// This is the main one
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

#define N 7

int i,j,t,n,ans,c;
vi path(N*N-1,0);
bool grid[N+2][N+2];

void move(int x, int y, int m){
  if (grid[x][y]||x==0||y==0||x==N+1||y==N+1) return;
  if (m==N*N-1){ ans++; return; }
  if (x==1&&y==N) return;

  if (((x==1||x==N||(grid[x+1][y]&grid[x-1][y]))&& y!=1&&y!=N &&(grid[x][y+1]^grid[x][y-1])==0)||
      ((y==1||y==N||(grid[x][y+1]&grid[x][y-1]))&& x!=1&&x!=N &&(grid[x+1][y]^grid[x-1][y])==0))
    return;

  grid[x][y] = 1;
  if (path[m]=='?'||path[m]=='R') move(x+1,y,m+1);
  if (path[m]=='?'||path[m]=='D') move(x,y+1,m+1);
  if (path[m]=='?'||path[m]=='L') move(x-1,y,m+1);
  if (path[m]=='?'||path[m]=='U') move(x,y-1,m+1);
  grid[x][y] = 0;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  for_(i,0,N*N-1)
    path[i]=getchar();

  move(1,1,0);
  cout << ans;

  return 0;
}
