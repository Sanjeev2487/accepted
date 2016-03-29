#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
#define FOR(i,a,n) for(int (i) = (a); (i) <= (n) ; ++(i))
#define ROF(i,a,n) for(int (i)=(a);(i) >= (n); --(i))
#define SD(x) scanf("%d",&x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define repstl(v) for(__typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define endl "\n"
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define present_mapset(c,x) ((c).find(x) != (c).end())
#define present_vector(c,x) (find(c.begin(),e.end(),x) != (c).end())
#define TRACE
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif

int a[1000000];
int maxVal = 1000000;
int tree[1000000];

int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx = idx - (idx & (-idx));
    }   
    return sum;
}

void update(int idx,int val)
{
    while(idx <= maxVal)
    {
        tree[idx] += val;
        idx = idx + (idx & (-idx));
    }
}

void update(int a,int b,int val)
{
    update(a,val);
    update(b+1,-val);
    
}

int main(int argc, char const *argv[])
{
    int t; SD(t);
    while(t--)
    {
        int n,u;
        SD(n);
        SD(u);
        memset(tree,0,sizeof(tree));
        int l,r,val;
        maxVal = n+2;
        while(u--)
        {
            SD(l);
            SD(r);
            SD(val);
            update(l+1,r+1,val);   
        }    

        /*
        FOR(i,0,5)
        {
            cerr << tree[i] << " ";
        }
        cerr << endl;
        */
        int q;
        SD(q);
        while(q--)
        {
            SD(u);
            u++;
            printf("%d\n",read(u));// - read(u-1));
        }
    }
    return 0;
}