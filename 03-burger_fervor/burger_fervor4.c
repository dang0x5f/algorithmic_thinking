#include <stdio.h>
#define SBT_IMPLEMENTATION
#include "sbt.h"

#define SIZE 10000

unsigned long long total_calls;

int max(int, int);
void solve(int, int, int);

int
main(void)
{
    int m, n, t;
    while(scanf("%d%d%d", &m, &n, &t) != -1){
        start_sbt();
        solve(m,n,t);
        end_sbt();
    }
    return(0);
}

int 
max(int v1, int v2)
{
    if(v1 > v2)
        return(v1);
    else
        return(v2);
}

void
solve(int m, int n, int t)
{
    int result, i, first, second;
    int dp[SIZE];
    /* total_calls = 0; */
    dp[0] = 0;
    for(i = 1; i <= t; i++){
        if(i >= m)
            first = dp[i - m];
        else
            first = -1;
        if(i >= n)
            second = dp[i - n];
        else
            second = -1;
        if(first == -1 && second == -1)
            dp[i] = -1;
        else
            dp[i] = max(first, second) + 1;
    }
    
    result = dp[t];
    if(result >= 0)
        printf("%d\n", result);
    else{
        i = t - 1;
        result = dp[i];
        while(result == -1){
            i--;
            result = dp[i];
        }
        printf("%d %d\n", result, t - i);
    }
    /* printf("Total calls to solve_t: %llu\n", total_calls); */
}
