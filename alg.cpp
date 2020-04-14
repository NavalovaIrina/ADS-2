#include<iostream>
#include <ctime>
#include <cstdlib>

void sort(int* arr, int size)
{
int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

		}

	}
}

int countPairs1(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] + arr[j] == value)
			{
				k++;
			}

		}

	}
	return k;
}


int countPairs2(int* arr, int len, int value)
{
	int k = 0;
	int mid = len / 2;
	for (int i = 0; i <= mid; i++)
	{
		for (int j = len; j > mid; j--)
		{
			if(arr[i]+arr[j]==value)
			{
				k++;
		    }
		}
	}
	return k;
}

int bSearch(int* arr, int size, int value) 
{
	int i = 0;
	int j = size - 1;
	while (i < j)
	{
		int mid = (i + j) / 2;
		 if (value < arr[mid])
			j = mid-1;
		else if (value > arr[mid])
			i = mid+1;
		else
          return mid;
	}
	return -1;
}

int countPairs3(int* arr, int len, int value)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		int first = arr[i];
		int second = value - first;
		int index = bSearch(arr, len, second);
		if (index > -1 && index != i)
		{
			k++;
		}

	}	
	return k;
}

	int main()
	{
		const int size = 12;
		int arr[size] = { 0 };
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		sort(arr, size);
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << countPairs1(arr, size, 10) << std::endl;
		std::cout << std::endl;
		std::cout << countPairs2(arr, size, 10) << std::endl;
		std::cout << std::endl;
	    std::cout << countPairs3(arr, size, 10) << std::endl;
		return 0;

	}
