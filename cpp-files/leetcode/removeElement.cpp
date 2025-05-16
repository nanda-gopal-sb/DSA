#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            auto pos = nums.begin() + i;
            if (nums[i] == val)
            {
                nums.erase(pos);
            }
        }
        for (auto i : nums)
            cout << i << " ";
        cout << endl;

        return k;
    }
};

int main()
{
    vector<int> lmao = {1, 1, 2, 3, 4, 5, 5};
    Solution sol;
    sol.removeElement(lmao, 1);
}