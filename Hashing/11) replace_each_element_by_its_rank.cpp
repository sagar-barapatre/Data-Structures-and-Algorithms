#include <iostream>
#include <map>
using namespace std;

// Function to replace each element of the array by its rank in the array
void transform(int arr[], int n)
{
	// create an empty ordered map
	map<int, int> map;

	// store (element, index) pair in the map
	for (int i = 0; i < n; i++)
		map[arr[i]] = i;

	// keys are stored in sorted order in ordered map

	// rank starts from 1
	int rank = 1;

	// iterate through the map and replace each element by its rank
	for (auto i : map)
		arr[i.second] = rank++;	 // i.second stores the index of element i
}

int main()
{
	int arr[] = { 10, 8, 15, 12, 6, 20, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// transform the array
	transform(arr, n);

	// print the transformed array
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}