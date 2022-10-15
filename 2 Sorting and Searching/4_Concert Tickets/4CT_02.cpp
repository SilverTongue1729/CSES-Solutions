// 3 works
// 1 and 2 are the same except the sort, they give TLE#include <bits/stdc++.h>
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

int i,j,n,m,c,ans,lb,ub,ti,stop;
vi h((int)2e5+1,0),t((int)2e5+1,0),temp((int)2e5+1,0);

int fastscan(int &number){
  bool negative = 0;
  register int c;

  number = 0;
  c = getchar();
  if (c=='-'){
    negative = 1;
    c = getchar();
  }

  for (; (c>='0' && c<='9'); c=getchar())
    number = number*10+c-'0';
  if (negative)
    number *= -1;
  return number;
}

 void fastprint(int num)
{
    bool neg = 0;
    if (num < 0)
      num *= -1, neg = 1;
    if (neg)
      putchar('-');

    char snum[65];
    int i = 0;
    do{
        snum[i++] = num % 10 + '0';
        num /= 10;
    } while (num);

    --i;

    while (i >= 0)
      putchar(snum[i--]);
}

// void merge_sort(int s, int e, vi &arr){
//   if (e-s==1) return;
//   merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
//   for_(i,s,(s+e)/2) temp[i] = arr[i];
//   i=s; j=(s+e)/2;
//   while (i<(s+e)/2 && j<e)
//     if (temp[i] < arr[j])
//       arr[i+j-1-(s+e)/2] = temp[i++];
//     else
//       arr[i+j-1-(s+e)/2] = arr[j++];
//   while (i<(s+e)/2) arr[i+j-1-(s+e)/2] = temp[i++];
//   while (j<e) arr[i+j-1-(s+e)/2] = arr[j++];
// }

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  fastscan(n); fastscan(m);
  for_(i,0,n) fastscan(h[i]); sort(h.begin(),h.begin()+n);
  for_(i,m,0){
    fastscan(ti);
    if (ti < h[0]){
      putchar('-');putchar('1');putchar('\n');
      continue;
    }
    if (n==0){
      while(i--){
        putchar('-');putchar('1');putchar('\n');
      }
      break;
    }
    lb=0; ub=--n;
    stop=0;
    while (lb!=ub){
      if (ti == h[((lb+ub)/2)+1]){
        stop=1;
        break;
      }
      else if (ti < h[((lb+ub)/2)+1])
        ub = (lb+ub)/2;
      else
        lb = (lb+ub)/2+1;
    }
    fastprint(h[(lb+ub)/2+stop]); putchar('\n');
    h.erase(h.begin()+(lb+ub)/2+stop);
  }

  return 0;
}
