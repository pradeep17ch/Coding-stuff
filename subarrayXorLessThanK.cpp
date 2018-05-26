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
#define llrr 2097152

typedef long long  ll;
typedef long double  ldo;
typedef double  db ;
using namespace std;

pair<ll, pll> trie[llrr];
ll leng = 20;

ll query(ll n, ll k)
{
    ll i,p=0,u,v;
    stack<ll> s, s1;
    rep(i,leng)
    {
        s.push(n&1);
        n >>= 1;
    }
    rep(i,leng)
    {
        s1.push(k&1);
        k >>= 1;
    }
    ll root = 0;
    while(!s.empty())
    {
        u = s.top();
        v = s1.top();
        if(u == 0 and v == 0)
        {
            root = 2*root + 1;
        }
        else if(u == 0 and v == 1)
        {
            p += trie[root].ss.ff;
            root = 2*root + 2;
        }
        else if(u == 1 and v == 1)
        {
            p += trie[root].ss.ss;
            root = 2*root + 1;
        }
        else
        {            
            root = 2*root + 2;
        }
        
        s.pop();
        s1.pop();
    }
    return p;
    
}

void insert(ll n)
{
    ll i,u,m;
    m=n;
    stack<ll> s;
    rep(i,leng)
    {
        s.push(n&1);
        n >>= 1;
    }
    ll root = 0;
    while(!s.empty())
    {
        u = s.top();
        if(u == 0)
        trie[root].ss.ff++;
        else
        trie[root].ss.ss++;
        if(trie[2*root + 1 + u].ff == -1)
        {
            trie[2*root + 1 + u].ff = u;
        }
        root = 2*root + 1 + u;
        s.pop();
    }
}

int main()
{
    boost;
    ll n,p,ans,i,j,a[siz],k,t,q;
    
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll l = 0;
        rep(i,llrr)
        {
            trie[i].ff = -1;
            trie[i].ss.ff = 0; 
            trie[i].ss.ss = 0;
        }
        insert(0);
        p=0;
        ans=0;
        rep(i,n)
        {
            cin>>a[i];
            q = p ^ a[i];
            ans += query(q,k);
            insert(q);
            p=q;
            
        }
        
        cout<<ans;on;
    }
    
    
    return 0;
}
