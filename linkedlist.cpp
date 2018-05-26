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

struct List
{
    ll n;
    List* next;
};

List* head;
List* tail;

void insert(ll n)
{
    List* temp = new List;
    temp->n = n;
    temp->next = NULL;
    
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        List* temp2 = tail;
        temp2->next = temp;
        tail = temp;
    }
}

void insertAt(ll b, ll c)
{
    ll ctr=0;
    List* temp = new List;
    temp->n = b;
    temp->next = NULL;
    List* temp2 = head;
    List* prev = NULL;
    while(ctr<c-1)
    {
        prev = temp2;
        temp2 = temp2->next;
        ctr++;
    }
    if(prev == NULL)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        prev->next = temp;
        temp->next = temp2;
    }
}

void display()
{
    List* temp = new List;
    temp = head;
    while(temp!=NULL)
    {
        cout<<temp->n;os;
        temp = temp->next;
    }
}

int main()
{
    ll n,m,i,a[siz],b,c;
    
    head = NULL;
    
    cin>>n;
    rep(i,n)
    {
        cin>>a[i];
        insert(a[i]);
    }
    
    display();on;
    
    cin>>m;
    while(m--)
    {
        cin>>b>>c;
        insertAt(b,c);
    }
    
    display();
    
    return 0;
}