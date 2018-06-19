/*
题目：
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

思路：从0号位置跳到jump过程中，最远可以到达的位置用max_index表示，用index向量存储当前位置开始可以跳跃到的最远位置，若位置x可以跳跃到index【x】，则也可以跳跃到i+1,i+2,...,index[x]，使用jump代表当前所处位置，若最终可以到达nums的尾部，则返回true，jump++发生在 未跳跃到nums的尾部 且 小于max_index，max_index更新发生在max_index小于index[jump]
*/

//代码

class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::vector<int> index;
        for(int i=0; i<nums.size(); i++){
            index.push_back(nums[i] + i); //从第i个位置最远可跳跃之第index[i]位置
        }
        int jump = 0;
        int max_index = index[0];
        while(max_index>=jump && jump<index.size()){ //未跳到尾部 且 未超越当前可以跳跃最远位置
            if(max_index<index[jump]){
                max_index = index[jump];
            }
            jump++;
        }
        if(jump == index.size()){
            return true;
        }
        return false;
    }
};