// SquaresOfASortedArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //vector<int> result;
        //int left = 0;
        //int right = nums.size() - 1;
        //while (left <= right)
        //{
        //    int leftSquare = nums[left] * nums[left];
        //    int rightSquare = nums[right] * nums[right];
        //    if (leftSquare > rightSquare)
        //    {
        //        result.push_back(leftSquare);
        //        left++;
        //    }
        //    else {
        //        result.push_back(rightSquare);
        //        right--;
        //    }
        //}

        //std::reverse(result.begin(), result.end());

        //return result;

        vector<int> result;
        int left = 0;
        int right = nums.size() - 1;
        int leftSquare = -1;
        int rightSquare = -1;

        while (left <= right)
        {
            if (leftSquare == -1)
            {
                leftSquare = nums[left] * nums[left];
            }

            if (rightSquare == -1)
            {
                rightSquare = nums[right] * nums[right];
            }

            if (leftSquare > rightSquare)
            {
                result.push_back(leftSquare);
                leftSquare = -1;
                left++;
            }
            else {
                result.push_back(rightSquare);
                rightSquare = -1;
                right--;
            }
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    vector<int> v = { -7,-3,2,3,11 };
    Solution solution;
    solution.sortedSquares(v);
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
