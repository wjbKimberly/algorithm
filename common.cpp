/*************************************************************************
    > File Name: common.cpp
    > Author: Guo Hengkai
    > Description: Common functions and headers
    > Created Time: Sat 10 Sep 2016 01:55:30 PM CST
 ************************************************************************/
#include "common.h"

vector<int> GetRandomVector(int n, int scope)
{
    vector<int> nums;
    nums.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        nums.push_back(rand() % scope);
    }
    return nums;
}

bool IsSorted(const vector<int>& nums)
{
    if (nums.empty())
    {
        return true;
    }

    for (size_t i = 1; i < nums.size(); ++i)
    {
        if (nums[i - 1] > nums[i])
        {
            return false;
        }
    }
    return true;
}

Node* Vec2Tree(const vector<int>& vec)
{
    if (vec.empty())
    {
        return nullptr;
    }

    size_t n = vec.size();
    vector<Node*> nodes(n, nullptr);
    for (size_t i = n; i > 0; --i)
    {
        if (vec[i - 1] >= 0)
        {
            nodes[i - 1] = new Node(vec[i - 1]);
            size_t child = i << 1;
            if (child <= n)
            {
                nodes[i - 1]->left = nodes[child - 1];
            }
            if (child < n)
            {
                nodes[i - 1]->right = nodes[child];
            }
        }
    }
    return nodes[0];
}
