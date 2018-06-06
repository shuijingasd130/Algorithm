## 题目：
- 给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
- 示例:
输入: [2,3,1,1,4]
输出: 2
- 解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
- 说明:
假设你总是可以到达数组的最后一个位置。  
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_45_1.png)

## 思路  
因为总是可以到达最后一个位置，开始遍历，current记录当前可以达到的最远位置，在到达current前先一直都不跳跃，那最远只能到达current这个点，但是遍历到current前肯定可以到达更远的位置，那究竟选哪个最远位置，用pre来记录到current前最远可以到达的位置，当遍历到current后，最少跳跃jump_min+1，current变为pre，遍历整个即可得到最小跳跃数。
算法：
![](https://raw.githubusercontent.com/shuijingasd130/Resource/master/Picture/leetcode_45_2.png)

## 代码
<pre class="cpp">
class Solution {  
public:  
    int jump(vector<int>& nums) {  
        if(nums.size()<2){  //数组长度小于2，不用跳跃，返回0    
            return 0;  
        }  
        int current_max_index = nums[0];  //当前最远可达位置    
        int pre_max_max_index = nums[0];  //遍历过程中，可达的最远位置    
        int jump_min = 1;  
        for(int i=1; i<nums.size(); i++){    
            if(i > current_max_index){  //若无法向前移动，进行跳跃    
                jump_min++;  //跳跃次数增加一次  
                current_max_index = pre_max_max_index;  //更新当前最远可达位置    
            }  
            if(pre_max_max_index < nums[i] + i){  //更新遍历过程可达的最远位置  
                pre_max_max_index = nums[i] + i;  
            }  
        }  
        return jump_min;  
    }  
};  
</pre>
