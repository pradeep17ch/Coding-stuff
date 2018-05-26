#include<bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define ins insert
#define mp make_pair
#define len(s) s.length()
#define forp(i,a,b) for( i=a;i<=b;i++)
#define rep(i,n)    for( i=0;i<n;i++)
#define ren(i,n)    for( i=n-1;i>=0;i--)
#define forn(i,a,b) for( i=a;i>=b;i--)
#define on cout<<endl
#define o2(a,b) cout<<a<<" "<<b
#define os cout<<" "
#define all(v) v.begin(),v.end()
#define mem(n,m) memset(n,m,sizeof(n))
#define pii pair<int,int>
#define pll pair<long long,long long>
#define sii set<int>
#define sll set<long long>
#define vii vector<int>
#define vll vector<long long>
#define mll map<long long, long long>
#define lob lower_bound
#define upb upper_bound
#define ret return 0
#define present(s,x) (s.find(x) != s.end())
#define cpresent(s,x) (find(all(s),x) != s.end())
#define ford(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define fors(container, it, a, b) for(__typeof(container.begin()) it = a; it != b; it++)

#define boost ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define EPSILON 1e-9
#define PI 3.14159265358979323846
#define inf 999999999999999999
#define siz 100001
#define SIZ 1000001
#define SIZE 200001

typedef long long  ll;
typedef long double  ldo;
typedef double  db ;
using namespace std;

ll trie[2*siz + 5];

ll query(ll n)
{
    ll i,p=0,u;
    stack<ll> s;
    rep(i,17)
    {
        s.push(n&1);
        n >>= 1;
    }
    ll root = 0;
    while(!s.empty())
    {
        u = s.top();
        
        if(trie[2*root + 2 - u] != -1)
        {
            p <<= 1;
            p = p + 1 - u;
            root = 2*root + 2 - u;
        }
        else
        {
            p <<= 1;
            p = p + u;
            root = 2*root + 1 + u;
        }
        
        s.pop();
    }
    
    return p;
    
}

void insert(ll n)
{
    ll i,u;
    stack<ll> s;
    rep(i,17)
    {
        s.push(n&1);
        n >>= 1;
    }
    ll root = 0;
    while(!s.empty())
    {
        u = s.top();
        if(trie[2*root + 1 + u] == -1)
        {
            trie[2*root + 1 + u] = u;
        }
        root = 2*root + 1 + u;
        s.pop();
    }
}

int main()
{
    ll n,i,j,a[siz], max=0, maxsofar=0;
    mem(trie, -1);
    
    cin>>n;
    
    rep(i,n)
    {
        cin>>a[i];
        max = a[i]^query(a[i]);
        insert(a[i]);
        if(max>maxsofar) maxsofar = max;
    }
    
    cout<<maxsofar;
    
    
    
    return 0;
}