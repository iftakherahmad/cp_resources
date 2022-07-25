#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000010

char str[SIZE];
char pat[SIZE];
int psa[SIZE];

void calculatePSA()
{
    psa[0] = 0;
    int pl = strlen(pat), sl = strlen(str);
    for (int i = 1; i < pl; i++)
    {
        int pgrs = psa[i - 1];
        while (pgrs > 0 and pat[pgrs] != pat[i])
            pgrs = psa[pgrs - 1];
        psa[i] = pgrs + ((pat[i] == pat[pgrs]) ? 1 : 0);
        psa[i] = psa[i];
    }
}

int getCount()
{
    int pgrs = 0;
    int ans = 0;
    int pl = strlen(pat), sl = strlen(str);

    for (int i = 0; i < sl; i++)
    {
        if (pat[pgrs] == str[i])
        {
            pgrs++;
            if (pgrs == pl)
            {
                ans++;
                pgrs = psa[pl - 1];
            }
        }        else if (pat[pgrs] != str[i])
        {
            while (pgrs > 0 and pat[pgrs] != str[i])
                pgrs = psa[pgrs - 1];
            pgrs += (pat[pgrs] != str[i] ? 0 : 1);
        }
    }
    return ans;
}

int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w+", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("\n%s\n%s", str, pat);
        calculatePSA();

        printf("Case %d: %d\n", t, getCount());
    }

    return 0;
}