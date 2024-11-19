#include <iostream>
#include <vector>

int linearSearch(int* arr, int target, int size) {
  for (size_t i = 0; i < size; ++i) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int main() {
  int n, target;
  std::cout << "Enter the number of elements: ";
  std::cin >> n;

  int arr[n];
  std::cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
  }

  std::cout << "Enter the target element to search: ";
  std::cin >> target;

  int result = linearSearch(arr, target, n);
  if (result != -1) {
    std::cout << "Element found at index " << result << std::endl;
  } else {
    std::cout << "Element not found" << std::endl;
  }

  return 0;
}