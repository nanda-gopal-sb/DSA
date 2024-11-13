#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int len = nums1.size();
        for (int i = 1; i <= (len - m); i++)
            nums1.pop_back();
        for (auto num : nums2)
        {
            nums1.push_back(num);
        }
        auto first = nums1.begin();
        auto last = nums1.end();
        sort(first, last);
    }
};