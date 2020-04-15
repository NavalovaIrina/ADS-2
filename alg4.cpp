
int countPairs1(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++) 
	{
		for (int j = i + 1; j < len; j++) 
		{
			if (arr[i] + arr[j] == value)
				k++;
		}
	}
	return k;
}
int countPairs2(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++) 
	{
		for (int j = len - 1; j > i; j--) 
		{
			if (arr[i] + arr[j] == value) 
			{
				k++;
			}
		}
	}
	return k;
}
int countPairs3(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++) 
	{
		int first = i;
		int last = len;
		while (first < last - 1) 
		{
			int mid = (first + last) / 2;
			if (arr[i] + arr[mid] == value) 
			{
				k++;
				int j = mid + 1;
				while (arr[i] + arr[j] == value && j < last) 
				{
					k++;
					j++;
				}
				j = mid - 1;
				while (arr[i] + arr[j] == value && j > first) 
				{
					k++;
					j--;
				}
				break;
			}
			if (arr[i] + arr[mid] > value) 
				last = mid;
			
			else 
				first = mid;
			
		}
	}
	return k;
}
