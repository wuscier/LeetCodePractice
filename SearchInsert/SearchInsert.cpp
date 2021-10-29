// SearchInsert.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


    // 高手赢的地方，返回left
    //class Solution {
    //public:
    //    int searchInsert(vector<int>& nums, int target) {
    //        int left = 0;
    //        int right = nums.size() - 1;
    //        while (left <= right) {
    //            int mid = left + (right - left) / 2;
    //            if (nums[mid] == target) {
    //                return mid;
    //            }
    //            else if (nums[mid] < target) {
    //                left = mid + 1;
    //            }
    //            else {
    //                right = mid - 1;
    //            }
    //        }
    //        return left;

    //    }
    //};

    // 我的差距，返回middle
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left <= right)
        {
            middle = left + (right - left) / 2;

            if (target > nums[middle])
            {
                left = middle + 1;
            }
            else if (target < nums[middle])
            {
                right = middle - 1;
            }
            else {
                break;
            }
        }

        if (target > nums[middle]) {
            return middle + 1;
        }

        return middle;
    }
};

int main()
{
    vector<int> v = {1,3,5,6};
    Solution solution;
    int result =  solution.searchInsert(v, 5);

    std::cout << "Hello World!\n";
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
