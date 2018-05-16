/*
一个整数序列，如果两相邻元素的差恰好正负 (负正 )交替出现 ，则该序列被称为 摇摆序列 。一个小于 2个元素的序列 直接 为摇摆序列。
例如 :
序列 [1, 7, 4, 9, 2, 5] ，相邻元素的差(6, -3, 5, -7, 3)，该序列为摇摆。
序列 [1,4,7,2,5] (3, 3, -5, 3)、 [1,7,4,5,5]  (6, -3, 1, 0) 不是摇摆序列。
给一个随机序列 ，求这满足摇摆序列定义的最长子序列 的长度。
例如 :
输入 [1,7,4,9,2,5] 结果为 6；输入 [1,17,5,10,13,15,10,5,16,8]，结果为 7([1,17,10,13,10,16,8] ；输入 [1,2,3,4,5,6,7,8,9] ，结果为 2。

思路：
如果遇到持续上升的，只去起点和终点，下降也是
使用状态机实现：
begin为两个元素相同，跳转到Up状态条件为后一个大于前一个，跳转到Down为前一个大于后一个
Up为上升状态，后一个>=前一个保持状态，＜跳转到Down
Down为下降状态，后一个<=前一个保持状态，＞跳转到Up
*/

//结果：

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size(); //序列个数小于2直接为摇摆序列
        }
        static const int Begin = 0; //定义状态机的三个状态
        static const int Up = 1;
        static const int Down = 2;
        int State = Begin;
        int max_length = 1; //摇摆序列长度至少为1  for循环从第二个元素开始
        
        for(int i=1; i<nums.size(); i++){
            switch(State){
                case Begin:
                    if(nums[i] == nums[i-1]){
                        State = Begin;
                    }
                    else if(nums[i]>nums[i-1]){
                        State = Up;
                        max_length++;
                    }
                    else{
                        State = Down;
                        max_length++;
                    }
                    break;
                case Up:
                    if(nums[i] < nums[i-1]){
                        State = Down;
                        max_length++;
                    }
                    break;
                case Down:
                    if(nums[i] > nums[i-1]){
                        State = Up;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};
