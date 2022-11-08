#pragma once
int test(int number[50], int n)
{
	int max=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int sum = 0;

			for (int k = i; k <= j; k++)
			{
				sum += number[k];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
	}

	return max;
}
