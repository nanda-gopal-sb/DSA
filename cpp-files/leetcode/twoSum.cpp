// this is the two sum probem, where given a array and one target variable, returns the indices
// of numbers whoes sum equals target variable.
#include <iostream>
using namespace std;
int *twoSum(int arr[], int target, int size)
{
    int *temp = new int[2];
    temp[0] = -1;
    temp[1] = -1;
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            // cout << arr[i] + arr[j] << "\n";
            if ((arr[i] + arr[j]) == target)
            {
                temp[0] = i;
                temp[1] = j;
                break;
            }
        }
    }
    return temp;
}
int main()
{
	cout<<"Lmao"<<"\n";
}
