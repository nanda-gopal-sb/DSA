// Merge sort in C++
#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[], int lower, int middle, int end) {
  int n1 = middle - lower + 1;
  int n2 = end - middle;

  vector<int> L(n1);
  vector<int> M(n2);

  for (int i = 0; i < n1; i++)
    L[i] = arr[lower + i];

  for (int j = 0; j < n2; j++)
    M[j] = arr[middle + 1 + j];

  int i = 0, j = 0, k = lower;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  mergeSort(arr, 0, size - 1);
  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}
