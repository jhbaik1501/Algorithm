#include <stdio.h>

int D[n+1][n+1][n+1];


int F(int W[n+1][n+1], n)
{
    for (int i =1; i<=n; i++)
        for(int j =1; j<=n; j++)
            D[0][i][j] = W[i][j];

    for (int k =1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for(int j =1;j<=n;j++)
                D[k][i][j] = min(D[k-1][i][j], D[k-1][i][k] + D[k-1][k][j]);
                
}