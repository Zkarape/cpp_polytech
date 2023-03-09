#include <stdio.h>
#include <string.h>
#define n 10
int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		;
	return (i);
}

void	printmatrix(int A[n][n], int sum)
{
	if (sum)
		printf("Հասանելիության մատրից\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

void multiply_matrices(int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
	{
            C[i][j] = 0;
            for (int k = 1; k < n; k++)
	    {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void	powerOfMatrix(int A[n][n], int exp, int res[n][n], int sum[n][n])
{
	int i, j;
	for (i = 1; i < n; i++)
	{
		res[0][0] = 0;
		for (j = 1; j < n; j++)
		{
			res[i][j] = (i == j) ? 1 : 0;
		}
	}
	for (i = 1; i <= exp; i++)
	{
		int temp[n][n];
		multiply_matrices(res, A, temp);
		for (j = 1; j < n; j++)
		{
			for (int k = 1; k < n; k++)
			{
				res[j][k] = temp[j][k];
			}
		}
		printf("A^%d:\n", i);
		printmatrix(res, 0);	
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				sum[i][j] += res[i][j];
			}
		}
		printf("\n");
	}
}

int main()
{
	int		exp = 8;
	int		A[n][n];
	int		B[n][n];
	int		sum[n][n];
	int		res[n][n];
	char		arr_i[] = "112234455546778895";
	char		arr_j[] = "456365878979809006";
	int		arr_ii[ft_strlen(arr_i)];
	int		arr_ji[ft_strlen(arr_j)];
	int		i = -1;
	int		j = -1;
	while (++i < ft_strlen(arr_i))
	{
		arr_ii[i] = arr_i[i] - 48;
		arr_ji[i] = arr_j[i] - 48;
	}
	i = -1;
	A[0][0] = 0;
	sum[0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		A[i][0] = i;
		res[i][0] = i;
		sum[i][0] = i;
		for (int j = 1; j < n; j++)
		{
			A[0][j] = j;
			A[i][j] = 0;
			sum[0][j] = j;
			sum[i][j] = 0;
			res[0][j] = j;
			res[i][j] = 0;
		}
	}
	i = -1;
	while (++i < ft_strlen(arr_i))
	{
		if (arr_ji[i] != 0)
			A[arr_ii[i]][arr_ji[i]] = 1;
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	powerOfMatrix(A, exp, res, sum);
	printmatrix(sum, 1);
}
