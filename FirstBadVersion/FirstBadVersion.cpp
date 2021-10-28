// FirstBadVersion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {
    //return version > 3;
    return version > 1702766718;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle = 1;
        int bad = 1;
        while (left <= right)
        {
            //middle = (left + right) / divide;
            middle = (left + (right - left) / 2);
            bool isBad = isBadVersion(middle);

            if (isBad)
            {
                bad = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return bad;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Solution solution;
   int result = solution.firstBadVersion(2126753390);
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
