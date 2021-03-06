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
#define ford(container, it) for(__typeof(container.begin()) it =
container.begin(); it != container.end(); it++)
#define fors(container, it, a, b) for(__typeof(container.begin()) it =
a; it != b; it++)

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

vll v[siz];
bool visit[siz], art[siz];
ll low[siz], disc[siz], parent[siz], child;

void dfs(ll u, ll timeS)
{
    ll i;
    visit[u] = true;
    low[u] = disc[u] = timeS+1;
    child=0;
    rep(i,v[u].size())
    {
        if(!visit[v[u][i]])
        {
            child++;
            parent[v[u][i]] = u;
            dfs(v[u][i], timeS+1);
            low[u] = min(low[u], low[v[u][i]]);
            if(parent[u]==-1 and child>1)
            {
                art[u] = true;
            }
            else if(parent[u]!=-1 and low[v[u][i]] >= disc[u])
            {
                art[u] = true;
            }
        }
        else if(parent[u]!=v[u][i])
        {
            low[u] = min(low[u], disc[v[u][i]]);
        }
    }
}

int main()
{
    ll a,b,n,m,i;

    mem(visit, false);
    mem(art, false);
    mem(parent, -1);

    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(0, 0);

    rep(i,n)
    {
        if(art[i])
        {
            cout<<i;os;
        }
    }

    return 0;
}

