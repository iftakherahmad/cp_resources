/**
 * @author cf:spider_void
 * @since temp:27May2022
 */
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<long long,null_type,greater_equal<long long>,rb_tree_tag,tree_order_statistics_node_update>

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

/**
 * Strart CONFIG *************************************************************
 * */
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++1
// Array
#define MAX_COMMON_ARA_LEN 200010
#define MAX_COMMON_CHAR_ARA_LEN 200010
#define MULTIPLE_TEST_CASE true
// graph
#define MAX_NODES 200010

/**
 * End CONFIG ****************************************************************
 */

/**
 * Start Utils
 */
int in();
void out(int a);
ll inL();
void outL(long long x);
void outAra(int *ara, int s, int e);
void clearGds();
/**
 * End Utils
 */

set<int> gst;
map<int, int> gmp;
vector<int> gvec;
// ordered_set gost;

/**
 *Start Custom Code
 *
 */

// vector<vector<int>> adjL(MAX_NODES);
// int mark[MAX_NODES];
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++2
// char str[MAX_COMMON_CHAR_ARA_LEN];
int cia[MAX_COMMON_ARA_LEN];
// int cia1[MAX_COMMON_ARA_LEN];
// int cia2[MAX_COMMON_ARA_LEN];
// ll cla[MAX_COMMON_ARA_LEN];
//***************************************************************************************

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++3
void solveCase(int t)
{
    int n = in();
    bool b = true;
    bool a = true;
    int mna = MAX_INT;
    int mnb = MAX_INT;
    string ara[5] = {"Hi", "Hellow", "h"};
    FN(i, n)
    {
        cia[i] = in();
        if (i % 2 == 0)
        {
            mna = min(mna, cia[i]);
            if (i != 0 and mna <= mnb)
            {
                a = false;
            }
        }
        else
        {
            mnb = min(mnb, cia[i]);
            if (mna <= mnb)
                a = false;
        }
        if (i != 0 && cia[i] < cia[i - 1] && i % 2 == 1)
        {
            b = false;
        }
    }

    puts(a or n % 2 == 1 or !b ? "Mike" : "Joe");
}
//***************************************************************************************
int main()
{
    int T = 1;
    if (MULTIPLE_TEST_CASE)
    {
        scanf("%d", &T);
    }

    FSE(t, 1, T)
    {
        clearGds();
        solveCase(t);
    }

    return 0;
}

//****************************************************************************************

/**
 *End Custom Code
 *
 */

int in()
{
    int x;
    scanf("%d", &x);
    return x;
}

void out(int a)
{
    printf("%d\n", a);
}

ll inL()
{
    long long x;
    scanf("%lld", &x);
    return x;
}

void outL(long long x)
{
    printf("%lld\n", x);
}

void outAra(int *ara, int s, int e)
{
    for (int i = s; i < e; ++i)
    {
        printf("%d ", ara[i]);
    }
    printf("\n");
}

void clearGds()
{
    gst.clear();
    gmp.clear();
    gvec.clear();
}