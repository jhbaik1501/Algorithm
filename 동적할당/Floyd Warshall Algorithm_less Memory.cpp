#include <stdio.h>


int D[n+1][n+1];

int F(int W[n+1][n+1], n)
{
    for (int i =1; i<=n; i++)
        for(int j =1; j<=n; j++)
            D[i][j] = W[i][j];

    for (int k =1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for(int j =1;j<=n;j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}