#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define ll long long
#define ull unsigned long long

#define MAX_INT INT_MAX
#define MIN_INT INT_MIN
#define MAX_LL LONG_LONG_MAX
#define MIN_LL LONG_LONG_MIN
#define MAX_ULL ULLONG_MAX
#define PI M_PI
#define E M_E
#define FN(i, n) for (int i = 0; i < n; ++i)
#define FSE(i, s, e) for (int i = s; i <= e; i++)

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ disjoint set
int par[1000000];
int find_root(int a){if(a==par[a])return a;return par[a]=find_root(par[a]);}
bool _find(int a,int b){return find_root(a)==find_root(b);}
void _union(int a,int b){par[find_root(a)]=find_root(b);}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ seive & prime factorization
int _primes[1000000];
int _flag[1000000];
void seive(){
	int idx=0;
	_primes[idx++]=2;
	for(int i=4;i<=1000000;i+=2)_flag[i]=1;
	for(int i=3;i<=1000000;i++){
		if(_flag[i]==0){
			_primes[idx++]=i;
			if(i<=1010){
				for(int j=3*i;j<=1000000;j+=2*i){
					_flag[j]=1;
				}
			}
		}
	}
}

bool _is_prime(long long n)
{ // complexity  O(root(n))
    if (n == 1)
        return false;
    long long l = (long long)sqrt(n + 1);
    for (int i = 2; i <= l; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
map<ll,ll> prime_factors(ll a,map<ll,ll> mp){					// O(sqrt(n));

	ll sq=sqrt(a+1);
	for(int i=0;_primes[i]<=sq;i++){
		int cnt=0;
		while(a%_primes[i]==0){a/=_primes[i];cnt++;}
		if(cnt)mp[_primes[i]]+=cnt;
	}
	if(a>1)mp[a]++;
	return mp;
}


/**
 * Segment tree Start++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/
template <typename T>
struct SegmentTree
{
private:
	T size;
	T *values;
	int valuesBaseIdx;
	T *tree;
	T *lazy;
	// need Associativity & Commutativity
	function<T(T, T)> op;
	T opIdentity = 0;
	// need Distributivity ove op usually + , -
	function<T(T, T)> uop;

	void initializeTree(int at, int l, int r)
	{
		if (l > r)
			return;
		if (l == r)
		{
			tree[at] = values[l - 1 + valuesBaseIdx];
			return;
		}

		int mid = (l + r) / 2;
		int lc = at * 2;
		int rc = at * 2 + 1;

		initializeTree(lc, l, mid);
		initializeTree(rc, mid + 1, r);

		tree[at] = op(tree[lc], tree[rc]);
	}

public:
	void setUop(function<T(T, T)> uop)
	{
		this->uop = uop;
	}

public:
	SegmentTree<T> initialize(int n, T opIdentity, int valuesBaseIdx, T *tree, T *values, T *lazy, function<T(T, T)> op)
	{
		this->size = n;
		this->values = values;
		this->op = op;
		this->uop = op;
		this->lazy = lazy;
		this->tree = tree;
		this->valuesBaseIdx = valuesBaseIdx;

		int limit = 4 * n;

		FN(i, limit)
		{
			tree[i] = lazy[i] = opIdentity;
		}

		initializeTree(1, 1, size);

		return *this;
	}

	T query(int at, int l, int r, int L, int R)
	{
		if (l >= L and r <= R)
		{
			return op(tree[at], lazy[at]);
		}
		if (l > R or r < L)
		{
			return opIdentity;
		}

		int mid = (l + r) / 2;
		int lc = at * 2;
		int rc = at * 2 + 1;

		return op(lazy[at], op(query(lc, l, mid, L, R), query(rc, mid + 1, r, L, R)));
	}

	void rangeUpdate(int at, int l, int r, int L, int R, T val)
	{
		if (l >= L and r <= R)
		{
			lazy[at] = uop(lazy[at], val);
			return;
		}
		if (l > R or r < L or l > r)
		{
			return;
		}

		int mid = (l + r) / 2;
		int lc = at * 2;
		int rc = at * 2 + 1;

		rangeUpdate(lc, l, mid, L, R, val);
		rangeUpdate(rc, mid + 1, r, L, R, val);

		tree[at] = op(uop(tree[lc], lazy[lc]), uop(tree[rc], lazy[rc]));
	}

	void pointUpdate(int at, int l, int r, int P, T val)
	{
		if (P < l or P > r)
		{
			return;
		}
		if (l == r)
		{
			tree[at] = uop(tree[at], val);
			return;
		}

		int mid = (l + r) / 2;
		int lc = at * 2;
		int rc = at * 2 + 1;

		pointUpdate(lc, l, mid, P, val);
		pointUpdate(rc, mid + 1, r, P, val);

		tree[at] = op(tree[lc], tree[rc]);
	}
};

/**
 * Segment tree end ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */