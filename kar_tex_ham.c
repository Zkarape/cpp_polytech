#include <stdio.h>
#include <string.h>
#define n 10
#define N 18

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

int	all_zeroes(int res[n][n])
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (res[i][j])
				return (0);
		}
	}
	return (1);
}

int	diagonal_zeroes(int res[n][n])
{
	for (int i = 1; i < n; i++)
	{
		if (res[i][i])
			return (0);
	}
	return (1);
}

int	powerOfMatrix(int A[n][n], int res[n][n], int sum[n][n])
{
	int i = 1, j;
	res[0][0] = 0;
	for (int i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			res[i][j] = (i == j) ? 1 : 0;
		}
	}
	while (1)
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
		if (all_zeroes(res))
			break ;
		if (!diagonal_zeroes(res))
			retrun (-1);
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
		i++;
	}
	return (i);
}

int	repeated(int arr_i[N], int num, int pos)
{
	for (int i = 0; i < pos; i++)
	{
		if (arr_i[i] == num)
			return (1);
	}
	return (0);
}

void	calculations(int A[n][n], int arr_i[N], int arr_j[N])
{
	int	t1 = 0;
	int	t2 = 0;
	int	t3 = 0;
	int	j = 0;
	int	nerqin_kaper = 0;
	int	miavor_kaper = 0;

	for (int i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr_i[i] == arr_j[j])
				break ;
		}
		if (!repeated(arr_i, arr_i[i], i) && j == N)
			t1++;
	}
	printf("t1 == %d\n", t1);
	for (int i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{	
			if (arr_i[i] == arr_j[j])
			{
				if (A[arr_i[i]][arr_j[i]] == 1)
					nerqin_kaper++;
				break ;
			}
		}
		if (!repeated(arr_i, arr_i[i], i) && j != N && arr_j[i] != 0)
			t2++;
	}
	printf("t2 == %d\n", t2);
	for (int j = 0; j < N; j++)
	{
		if (arr_j[j] == 0)
			t3++;
	}
	printf("t3 == %d\n", t3);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 1)
				miavor_kaper++;
		}
	}
	printf("Միջանկյալ տարրերի գործակից։ %f\n", (double)t2 / (double)(n - 1));
	printf("Ներքին տարրերի գործակից։ %f\n", (double)nerqin_kaper / (double)miavor_kaper);
}

int main()
{
	int	A[n][n];
	int	B[n][n];
	int	sum[n][n];
	int	res[n][n];
	int	arr_i[N];
	int	arr_j[N];
	int	i = -1;
	int	j = -1;
	int	k = 0;

	for (int i = 0; i < N; i++)
	{
		printf("arr_i[%d], arr_j[%d] ", i, i);
		scanf("%d %d", &arr_i[i], &arr_j[i]);
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
	while (++i < N)
	{
		if (arr_j[i] != 0)
			A[arr_i[i]][arr_j[i]] = 1;
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
	calculations(A, arr_i, arr_j);
	k = powerOfMatrix(A, res, sum) - 1;
	if (k == -1)
		printf("Մատրիցը ցիկլիկ է\n");
	else
		printf("Մատրիցի կարգն է: %d\n", k);
	printmatrix(sum, 1);
}
