// This is finally fucking works lessgo!!!!!
// 1 and 2 are the same except the sort, they give TLE
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

int i,j,n,m,c,ans,lb,ub,ti,stop,par_ind,countval;
int h[(int)2e5+1][2],t[(int)2e5+1],temp[(int)2e5+1];

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

void merge_sort(int s, int e, int arr[][2]){
  if (e-s==1) return;
  merge_sort(s,(s+e)/2,arr); merge_sort((s+e)/2,e,arr);
  for_(i,s,(s+e)/2) temp[i] = arr[i][0];
  i=s; j=(s+e)/2;
  while (i<(s+e)/2 && j<e)
    if (temp[i] < arr[j][0])
      arr[i+j-1-(s+e)/2][0] = temp[i++];
    else
      arr[i+j-1-(s+e)/2][0] = arr[j++][0];
  while (i<(s+e)/2) arr[i+j-1-(s+e)/2][0] = temp[i++];
  while (j<e) arr[i+j-1-(s+e)/2][0] = arr[j++][0];
}

int index(int ind){
  cout<<"ind="<<ind<<endl;
  if (ind==h[ind][1])
    return ind;
  else
    return (h[ind][1] = index(h[ind][1]));
}

int main(){
#ifdef LOCAL
  freopen("/home/sriteja/Competitive Programming/Random/input_01.txt","r",stdin);
  freopen("/home/sriteja/Competitive Programming/Random/output_02.txt","w",stdout);
#endif

  // ios_base::sync_with_stdio(false); cin.tie(0);

  fastscan(n); fastscan(m);
  for_(i,0,n){
    fastscan(h[i][0]);
    h[i][1] = i;
  }
  merge_sort(0,n,h);
  for_(i,0,n) cout<<h[i][0]<<" ";
  cout<<endl;
  for_(i,0,n) cout<<h[i][1]<<" ";
  cout<<endl;
  countval = n-1;
  for_(i,m,0){
    fastscan(ti);
    if (ti < h[0][0]){
      putchar('-');putchar('1');putchar('\n');continue;
    }
    if (countval==-1){
      while(i--){
        putchar('-');putchar('1');putchar('\n');
      }
      break;
    }
    lb=0; ub=n-1;
    stop=0;
    while (lb!=ub){
      par_ind = index(((lb+ub)/2)+1);
      if (ti == h[par_ind][0]){
        stop=1;
        break;
      }
      else if (ti < h[par_ind][0])
        ub = (lb+ub)/2;
      else
        lb = (lb+ub)/2+1;
    }
    par_ind = index(((lb+ub)/2)+stop);
    if (ti < h[par_ind][0]){
      putchar('-');putchar('1');putchar('\n');
    }
    else{
      fastprint(h[par_ind][0]); putchar('\n');
      h[par_ind][1] = h[par_ind+1][1];
      countval--;
    }
  }

  return 0;
}
