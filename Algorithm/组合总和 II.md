# 组合总和 II  
## 题目  
- 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。  
    candidates 中的每个数字在每个组合中只能使用一次。  
- 说明：  
    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。  
- 示例 1:  
- 输入:   
    candidates = [10,1,2,7,6,1,5], target = 8,
- 所求解集为:  
    [
      [1, 7],
      [1, 2, 5],
      [2, 6],
      [1, 1, 6]
    ]
- 示例 2:  
- 输入:   
    candidates = [2,5,2,1,2], target = 5,
- 所求解集为:  
    [
      [1,2,2],
      [5]
    ]  
- **用1.2的算法，算法复杂度过高，没有利用target这个条件，存在过多错误尝试，浪费时间**  
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_40_1.png)
- **利用剪枝可以大幅提高效率**  
## 算法思路  
- 在return处增加条件实现剪枝环节：  
    ![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_40_2.png)  
## 代码
``` cpp
    class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                std::vector<std::vector<int>> result;    //最终结果
                std::vector<int> item;
                std::set<std::vector<int>> res_set;    //用于对item去重
                std::sort(candidates.begin(), candidates.end());    //排序
                generate(0, candidates, result, item, res_set, 0, target);
                return result;
            }
        private:
            void generate(int i, std::vector<int>& candidates,
                          std::vector<std::vector<int>>& result,
                          std::vector<int>& item,
                          std::set<std::vector<int>>& res_set,
                         int sum, int target){  //sum为当前子集item中元素的和
                if(i >= candidates.size() || sum>target){
                    return;
                }
                sum += candidates[i];
                item.push_back(candidates[i]);
                if(sum==target && res_set.find(item) == res_set.end()){    //未找到
                    result.push_back(item);
                    res_set.insert(item);
                }
                generate(i+1, candidates, result, item, res_set, sum, target);
                item.pop_back();
                sum -= candidates[i];
                generate(i+1, candidates, result, item, res_set,sum, target);
            }
    };
```

