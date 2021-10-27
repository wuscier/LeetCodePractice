// BinarySearch.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 牛逼写法
    //int search(vector<int>& nums, int target) {
    //    int left = 0, right = nums.size() - 1;
    //    while (right >= left) {
    //        int mid = (left + right) / 2;
    //        if (nums[mid] == target) {
    //            return mid;
    //        }
    //        else if (nums[mid] < target) {
    //            left = mid + 1;
    //        }
    //        else if (nums[mid] > target) {
    //            right = mid - 1;
    //        }
    //    }
    //    return -1;
    //}

    // 我的写法
    int Search(vector<int>& nums, int target)
    {
        if (nums.size() <= 0)
        {
            return -1;
        }

        int beginIndex = 0;
        int endIndex = nums.size() - 1;
        int compareIndex = (endIndex - beginIndex) / 2;

        while (target != nums[compareIndex])
        {
            if (target > nums[compareIndex])
            {
                beginIndex = compareIndex + 1;
                if (beginIndex > endIndex)
                {
                    compareIndex = -1;
                    break;
                }
                compareIndex += ((endIndex - beginIndex) / 2 + 1);
            }
            else if (target < nums[compareIndex])
            {
                endIndex = compareIndex - 1;
                if (endIndex < beginIndex)
                {
                    compareIndex = -1;
                    break;
                }
                compareIndex = (endIndex - beginIndex) / 2;
            }

        }

        return compareIndex;
    }
};


int main()
{
    std::cout << "Hello World!\n";

    //vector<int> v = { -1, 0, 3, 7, 10, 21, 39, 88, 106, 999 };
    vector<int> v = { -1,0,3,5,9,12 };
    Solution solution;
    int index = solution.Search(v, 2);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
