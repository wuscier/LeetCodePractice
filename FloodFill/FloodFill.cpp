// FloodFill.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if (image.size() == 0)
        {
            return image;
        }

        int val = image[sr][sc];

        if (val == newColor) {
            return image;
        }

        int width = image[0].size();
        int height = image.size();

        queue<pair<int, int>> q;

        q.push(make_pair(sr, sc));

        while (!q.empty())
        {
            int size = q.size();

            for (size_t i = 0; i < size; i++)
            {
                pair<int, int> point = q.front();
                q.pop();

                // 左
                if (point.first - 1 >= 0 && image[point.first - 1][point.second] == val)
                {
                    q.push(make_pair(point.first - 1, point.second));
                }

                // 上
                if (point.second - 1 >= 0 && image[point.first][point.second - 1] == val)
                {
                    q.push(make_pair(point.first, point.second - 1));
                }


                // 右
                if ((point.first + 1 < height) && (image[point.first + 1][point.second] == val))
                {
                    q.push(make_pair(point.first + 1, point.second));
                }


                // 下
                if (point.second + 1 < width && image[point.first][point.second + 1] == val)
                {
                    q.push(make_pair(point.first, point.second + 1));
                }

                image[point.first][point.second] = newColor;

            }
        }

        return image;
    }
};

int main()
{
    //vector<vector<int>> v = { {1,1,1},{1,1,0},{1,0,1} };
    vector<vector<int>> v = { {0,0,0},{0,1,1} };

    Solution solution;
    solution.floodFill(v, 1, 1, 1);
    std::cout << "Hello World!\n";
}



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vals;
//
//        if (root == nullptr)
//        {
//            return vals;
//        }
//
//        queue<TreeNode*> nodes;
//        nodes.push(root);
//
//        while (!nodes.empty())
//        {
//            int size = nodes.size();
//            vals.push_back(vector<int>());
//
//            for (size_t i = 0; i < size; i++)
//            {
//                TreeNode* node = nodes.front();
//                nodes.pop();
//
//                if (node != nullptr)
//                {
//                    vals.back().push_back(node->val);
//
//                    if (node->left != nullptr)
//                    {
//                        nodes.push(node->left);
//                    }
//
//                    if (node->right != nullptr)
//                    {
//                        nodes.push(node->right);
//                    }
//                }
//            }
//        }
//
//        return vals;
//    }
//};


//int main() {
//    TreeNode* fifteen = new TreeNode(15);
//    TreeNode* seven = new TreeNode(7);
//
//    TreeNode* nine = new TreeNode(9);
//    TreeNode* twenty = new TreeNode(20, fifteen, seven);
//
//    TreeNode* root = new TreeNode(3, nine, twenty);
//
//
//
//
//    Solution solution;
//    solution.levelOrder(root);
//}





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
