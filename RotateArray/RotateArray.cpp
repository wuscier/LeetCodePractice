// RotateArray.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 历史写法
        //int size = nums.size();
        //if (size == 0) {
        //    return;
        //}

        //int moveSteps = k % size;
        //if (moveSteps == 0) {
        //    return;
        //}

        //vector<int> lastKNums;
        //for (int i = size - 1; i >= 0; i--) {

        //    if (i > size - (k + 1)) {
        //        lastKNums.push_back(nums[i]);
        //        nums[i] = nums[i - k];
        //    }

        //    if (i == size - (k + 1))
        //    {
        //        nums[i] = nums[i - k];
        //    }

        //    if (i < k) {
        //        nums[i] = lastKNums[lastKNums.size() - i - 1];
        //    }
        //}

        // 理解后写法 将后面的k个元素移动到前面
        int size = nums.size();
        while (k > size)
        {
            k -= size;
        }

        vector<int> result(nums.size(), 0);

        int index = 0;
        for (size_t i = size - k; i < size; i++, index++)
        {
            result[index] = nums[i];
        }

        for (size_t i = 0; i < size - k; i++, index++)
        {
            result[index] = nums[i];
        }

        nums = result;
    }
};

int main()
{
    vector<int> v = { 1,2,3,4,5,6,7 };

    Solution solution;
    solution.rotate(v, 3);

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
