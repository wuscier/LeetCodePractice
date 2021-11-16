// MaxAreaIsland.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<pair<int, int>, int> iteratedCells;
        queue<pair<int, int>> q;

        int maxArea = 0;

        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && iteratedCells.find(make_pair(i, j)) == iteratedCells.end())
                {
                    q.push(make_pair(i, j));

                    int area = 0;
                    while (!q.empty())
                    {
                        int size = q.size();
                        for (size_t k = 0; k < size; k++)
                        {
                            pair<int, int> p = q.front();
                            q.pop();

                            area++;

                            if (p.second + 1 < grid[0].size() && grid[p.first][p.second + 1] == 1)
                            {
                                if (iteratedCells.find(make_pair(p.first,p.second+1)) == iteratedCells.end())
                                {
                                    q.push(make_pair(p.first, p.second + 1));
                                    iteratedCells.emplace(make_pair(make_pair(p.first, p.second + 1), 0));
                                }
                            }

                            if (p.first + 1 < grid.size() && grid[p.first + 1][p.second] == 1)
                            {
                                if (iteratedCells.find(make_pair(p.first + 1, p.second)) == iteratedCells.end())
                                {
                                    q.push(make_pair(p.first + 1, p.second));
                                    iteratedCells.emplace(make_pair(make_pair(p.first + 1, p.second), 0));
                                }
                            }

                            if (p.second -1 >= 0 && grid[p.first][p.second -1] == 1)
                            {
                                if (iteratedCells.find(make_pair(p.first, p.second - 1)) == iteratedCells.end())
                                {
                                    q.push(make_pair(p.first, p.second - 1));
                                    iteratedCells.emplace(make_pair(make_pair(p.first, p.second - 1), 0));
                                }
                            }

                            if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == 1)
                            {
                                if (iteratedCells.find(make_pair(p.first - 1, p.second)) == iteratedCells.end())
                                {
                                    q.push(make_pair(p.first - 1, p.second));
                                    iteratedCells.emplace(make_pair(make_pair(p.first - 1, p.second), 0));
                                }
                            }

                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};


int main()
{
    //vector<vector<int>> v = { {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    //    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} };

    vector<vector<int>> v = { {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1} };

    Solution solution;
    solution.maxAreaOfIsland(v);


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
