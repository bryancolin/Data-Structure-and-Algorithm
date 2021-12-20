#include <iostream>
#include <vector>

using namespace std;

int linear_binary_search(vector<int> nums, int left, int right, int target)
{
    while (left <= right)
    {
        int pivot = left + (right - left) / 2;

        if (nums[pivot] < target)
        {
            left = pivot + 1;
        }
        else if (nums[pivot] > target)
        {
            right = pivot - 1;
        }
        else
        {
            return pivot;
        }
    }

    return -1;
}

int recursive_binary_search(vector<int> nums, int left, int right, int target)
{
    if (left <= right)
    {
        int pivot = left + (right - left) / 2;

        if (nums[pivot] < target)
        {
            return recursive_binary_search(nums, pivot + 1, right, target);
        }
        else if (nums[pivot] > target)
        {
            return recursive_binary_search(nums, left, pivot - 1, target);
        }
        else
        {
            return pivot;
        }
    }

    return -1;
}

int main()
{
    vector<int> v;
    for (int i = 10; i < 20; i++)
    {
        v.push_back(i);
    }

    cout << "Linear Binary Search of 12 is at position: " << linear_binary_search(v, 0, v.size() - 1, 12) << endl;
    cout << "Recursive Binary Search of 12 is at position: " << recursive_binary_search(v, 0, v.size() - 1, 12) << endl;
}