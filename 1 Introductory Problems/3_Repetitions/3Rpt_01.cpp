#include <bits/stdc++.h>

using namespace std;

// ios::sync_with_stdio(false); cin.tie(NULL);

#define for_(i,s,e) for (int i=s; i<e; i++)
typedef long long ll;
typedef vector<int> vi;

int c,d,ans,counter;
ll i,j,k,t,n,a;

int main(){
  d = getchar();
  while((c=getchar()) != '\n'){
    if (c == d)
      counter++;
    else{
      if (counter > ans)
        ans=counter;
      counter = 0;
    }
    d = c;
  }
  if (counter > ans)
    ans=counter;
  cout << ++ans;

  return 0;
}
