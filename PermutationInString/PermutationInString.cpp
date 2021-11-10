// PermutationInString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



//class Solution {
//public:
//    bool checkInclusion(string s1, string s2) {
//        int n = s1.length(), m = s2.length();
//        if (n > m) {
//            return false;
//        }
//        vector<int> cnt(26);
//        for (int i = 0; i < n; ++i) {
//            --cnt[s1[i] - 'a'];
//        }
//        int left = 0;
//        for (int right = 0; right < m; ++right) {
//            int x = s2[right] - 'a';
//            ++cnt[x];
//            while (cnt[x] > 0) {
//                --cnt[s2[left] - 'a'];
//                ++left;
//            }
//            if (right - left + 1 == n) {
//                return true;
//            }
//        }
//        return false;
//    }
//};


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
        {
            return false;
        }

        sort(s1.begin(), s1.end());

        for (size_t i = 0; i + s1.length() - 1 < s2.length(); i++)
        {
            string subStr = s2.substr(i, s1.length());
            sort(subStr.begin(), subStr.end());

            if (subStr == s1)
            {
                return true;
            }
        }

        return false;
    }
};


int main()
{
    vector<int> v(26);
    string s1 = "ab";
    string s2 = "eidboaoo";

    Solution solution;
    solution.checkInclusion(s1, s2);

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
