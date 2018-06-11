# 题目
- n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_51_1.png)

- 上图为 8 皇后问题的一种解法。  
    给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
    每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
- 将N个皇后放摆放在N\*N的棋盘中，互相不可攻击，有多少种摆放方式，每种摆放方式具体是怎样的?  
- 示例:  
- 输入: 4  
- 输出:
```   
    [  
     [".Q..",  // 解法 1
      "...Q",
      "Q...",
      "..Q."],

     ["..Q.",  // 解法 2
      "Q...",
      "...Q",
      ".Q.."]
    ]
```
- 解释: 4 皇后问题存在两个不同的解法。
- **问题**：  
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_51_2.png)  
# 思路  
- 数据结构，棋盘用一个二维数组表示，未占用用0，已占用用1表示；  
    放一个皇后，上、下、左、右、左上、右上、左下、右下八个方向上都要填1，采用方向向量遍历数组实现  
    dx[-1, 1, 0, 0, -1, -1, 1, 1]  
    dy[0, 0, -1, 1, -1, 1, -1, 1]  
    分别代表8个方向，组合表示，dx和dy分别取第一个：[-1, 0]表示左方向，其他类推  
    ![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_51_3.png)  
    要将左方向赋值为1：new_x = x+i\*dx[0]; new_y = y+i\*dy[0];（i为1到N-1，棋盘的大小）  
  
  
- **采用回溯算法实现**，具体思路：
    ![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_51_4.png)
- 过程举例  
    ![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_51_5.png)  
# 代码  
``` cpp
    class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            std::vector<std::vector<std::string>> result;   //存储最终结果
            std::vector<std::vector<int>> mark;   //二维数组，表示棋盘的各个位置的标记  0-->可以放置  1-->不可以放置
            std::vector<std::string> location;   //存储某个摆放结果，完成一次递归需push到result中
            for(int i=0; i<n; i++){   //初始化mark为0 location为.
                mark.push_back(std::vector<int>());
                for(int j=0; j<n; j++){
                    mark[i].push_back(0);
                }
                location.push_back("");
                location[i].append(n, '.');
            }
            
            generate(0, n, location, result, mark);
            return result;
        }
    private:
        void put_down_queen(int x, int y, 
                                std::vector<std::vector<int>> &mark){
            static const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
            static const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
            mark[x][y] = 1;
            for(int i=1; i<mark.size(); i++){
                for(int j=0; j<8; j++){
                    int new_x = x + i*dx[j];
                    int new_y = y + i*dy[j];
                    if(new_x>=0 && new_y>=0 && new_x<mark.size() && new_y<mark.size()){
                        mark[new_x][new_y] = 1;
                    }
                }
            }
        }
        
        void generate(int k, int n,     //k代表完成了第几个皇后的放置（正在放置第k行皇后）
                     std::vector<std::string> &location,    //某次结果的存储
                     std::vector<std::vector<std::string>> &result,    //最终结果的存储
                     std::vector<std::vector<int>> &mark){    //表示棋盘的标记数组
            if(k==n){    //完成第0行至第n-1行的放置
                result.push_back(location);    //将记录的皇后位置push到result中
                return;
            }
            for(int i=0; i<n; i++){    //按顺序尝试0~n-1列（在0~n-1列依次尝试放置皇后）
                if(mark[k][i]==0){    //可以放置皇后
                    std::vector<std::vector<int>> tmp_mark = mark;    //记录回溯前的mark
                    location[k][i] = 'Q';    //记录当前皇后位置
                    put_down_queen(k, i, mark);    //放置皇后
                    generate(k+1, n, location, result, mark);    //递归下一行皇后放置
                    mark = tmp_mark;    //回溯后要做的事：mark重新赋值到当前状态
                    location[k][i]='.';    //将当前尝试的皇后位置重新置.
                }
            }
        }
    };
```