#include <stdio.h>
#include <unistd.h>
#include <math.h>

int main()
{
    int k, N, i, j = 0;
    int temp = 0;       
    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter K: ");
    scanf("%d", &k);
    int table[N + 2][k];
    int sums[k];
    int sums2[k];
    int nor[k];
    const char *gorconner[] = {
        "միջավայր",
        "ունակություններ",
        "ֆիզիկական վիճակ",
        "հոգեբանական վիճակ",
        "աշխատասիրություն",
        "t_j"
    };
    for(int o = 0; o < k; o++)
    {
        sums[o] = 0;
    }
    printf("    ");
    for (j = 0; j < k + 1; j++)
    {
        printf("%4s | ", gorconner[j]);
    }
    printf("\n");
    for (i = 0; i < N; i++)
    {
        printf("%2d|     ", i + 1);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &table[i][j]);
            sums[j] += table[i][j];
            printf("     ");
        }
        printf("\n");
    }
    printf("գումար|  ");
    for(j = 0; j < k; j++)
    {
        table[i][j] = sums[j];
        printf("     %d         ", sums[j]);
    }
    printf("\n");
    printf("   նոր|  ");
    for(int o = 0; o < k; o++)
    {
        sums2[o] = sums[o];
    }
    //bubble
    for (i = 0; i < k-1; i++) 
    {
        for (j = 0; j < k-i-1; j++) 
        {
            if (sums2[j] > sums2[j+1]) 
            {
                temp = sums2[j];
                sums2[j] = sums2[j+1];
                sums2[j+1] = temp;
            }
        }
    }
    //    
    for(int j = 0; j < k; j++)
    {
        for(int i = 0; i < k; i++)
        {
            if (sums[j] == sums2[i])
                sums2[i] = j;
        }
    }
    for(j = 0; j < k; j++)
    {
        printf("     %d         ", sums2[j]);
    }
    printf("\n");
    //calculate S
    double s = 0, sum = 0;
    for (int i = 0; i < k; i++)
    {
        s += (sums[i] - 0.5 * N * (k + 1)) * (sums[i] - 0.5 * N * (k + 1));
    }
    
}