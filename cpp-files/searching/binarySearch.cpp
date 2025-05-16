#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
      return mid;

    if (arr[mid] < target)
      left = mid + 1;

    else
      right = mid - 1;
  }

  return -1;
}

int main() {
  int arr[] = {0};
  int n;
  std::cout << "Enter the number of elements in the array: ";
  cin >> n;
  int arr[n];
  cout << "Enter the elements of the array in sorted order: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int size = sizeof(arr) / sizeof(arr[0]);
  int target = 10;
  int result = binarySearch(arr, size, target);

  if (result != -1)
    cout << "Element is present at index " << result << endl;
  else
    cout << "Element is not present in array" << endl;
  return 0;
}
