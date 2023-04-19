#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define len 17

int stlen(char *s)
{
	int i = -1;
	while (s[++i])
		;
	return (i);
}

int count(char *s, char c)
{
	int i = -1;
	int k = 0;
	while (s[++i])
	{
		if (s[i] == c)
			k++;
	}
	return (k);
}

void sorting(double probs[len], int n)
{
	int i = -1;
	int j = -1;
	double tmp;
	while (++i < n)
	{
		j = i + 1;
		while (++j < len)
		{
			if (probs[j] > probs[i])
			{
				tmp = probs[j];
				probs[j] = probs[i];
				probs[i] = tmp;
			}
		}
	}
	for (int i = 0; i < len; i++)
		printf("d == %f, ", probs[i]);
	printf("\n");
	sorting(probs, n - 1);
}

int main()
{
	char anun[] = "Zhenya Karapetyan";
	double probs[len];
	int i = 0;
	while (anun[i])
	{
		probs[i] = (double)count(anun, anun[i]) / (double)len;
		printf("probs[i] is: %f\n", probs[i]);
		i++;
	}
	sorting(probs, len);
}
