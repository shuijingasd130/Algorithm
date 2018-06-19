## 题目
- 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。
一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
- Example:
输入:
[[10,16], [2,8], [1,6], [7,12]]
输出:
2
- 解释:
对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_452_1.png)
## 思路  
先就左区间排序，寻找射击区间，不断缩小射击区间，使射击区间左端点满足增加射手个数前的第一个气球范围内的同时，将左区间不断右移，右区间不断左移，使射击区间尽可能的被更多的气球包含。
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_452_2.png)
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_452_3.png)
## 代码
``` cpp
bool cmp(const std:: pair<int, int> &a, const std::pair<int, int> &b){  //按照左端点排序
    return a.first < b.first;
}
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0)  //传入为空，返回0
            return 0;
        std::sort(points.begin(), points.end(), cmp);  //排序
        
        int shoot_num = 1;  //初始化射手数量
        int shoot_begin = points[0].first;  //射击区间起始
        int shoot_end = points[0].second;  //射击区间终止
        
        for(int i=1; i<points.size(); i++){
            if(shoot_end >= points[i].first){  //射击区间终止大于新区间起始，更新
                shoot_begin = points[i].first;  //不断缩小射击区间的起始和终止，尽可能的使射击区间可以射到更多气球
                if(shoot_end > points[i].second){  //缩小射击区间的终点，以确保肯定可以射到当前气球
                    shoot_end = points[i].second;
                }
            }
            else{  //不能射到更多气球了
                shoot_num++;  //增加射手
                shoot_begin = points[i].first;  //更新区间
                shoot_end = points[i].second;
            }
        }
        return shoot_num;
    }
};
```

