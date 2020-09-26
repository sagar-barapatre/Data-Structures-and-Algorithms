#include<iostream>
#include<vector>
#include<algorithm>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
using namespace std;
bool twosum(int arr[], int sum, int i)
{
	int n = my_sizeof(arr) / my_sizeof(arr[0]);
	int j = n - 1;
	while (i < j)
	{
		if (arr[i] + arr[j] == sum)
			return true;
		else if (arr[i] + arr[j] > sum)
			j--;
		else if (arr[i] + arr[j] < sum)
			i++;
	}
	return false;
}


bool threeSum(int arr[], int n, int sum)
{
	sort(arr, arr + n);
	for (int i = 0 ; i < n - 2 ; i++)
	{
		if (twosum(arr, -arr[i], i + 1))
			return true;

	}
	return false;
}





int main()
{
	int arr[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int sum = 6;

	int n = sizeof(arr) / sizeof(arr[0]);

	threeSum(arr, n, sum) ? cout << "Triplet Exists" :
	                             cout << "Triplet Don't Exist";
	return 0;
}