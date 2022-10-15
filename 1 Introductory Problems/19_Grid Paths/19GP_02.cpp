// 03 is the main one
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

int i,j,t,n,ans,x,y,c,m;
vi path(N*N-1,0);
int grid[N+2][N+2];


void move(){
  if (grid[x][y]||x==0||y==0||x==N+1||y==N+1)
    return;
  if (m==N*N-1){
    ans++;
    return;
  }
  if (x==1&&y==N)
    return;
  // printf("m = %d\n", m);
  m++; grid[x][y] = 1;

  if (x!=N&&grid[x+1][y]==0){ x++; move(); x--;}
  if (y!=N&&grid[x][y+1]==0){ y++; move(); y--;}
  if (x!=1&&grid[x-1][y]==0){ x--; move(); x++;}
  if (y!=1&&grid[x][y-1]==0){ y--; move(); y++;}

  m--; grid[x][y] = 0;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  x=1;y=1;
  move();
  cout << ans;

  return 0;
}
