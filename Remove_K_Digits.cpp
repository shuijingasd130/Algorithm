/*
题目：
已知一个使用字符串表示的非负整数非负整数非负整数非负整数num，将num中的k个数字移除，求移k个数字后，可以获得的最小的可能的新数字。
输入:num=“1432219”,k=3:去掉3个数后，有许多种可能，最小的为1219
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
1.输入的num，字符串长度<=10002，并且字符串长度>=k
2.输入的num字符串不会以任何数量的0字符开头
思路：
若去掉某一位数字，为了使得到的新数字最下，优先最高位最小，其次高位最小，再其次第3位
首先从头开始删数字，后一个大于前一个，则删掉前一个，可删数量减一，即可保证最终得到的数字是从小到大的，如果删完后仍可删，则从后往前删
利用栈实现
*/
//结果：

class Solution {
public:
    string removeKdigits(string num, int k) {
        std::vector<int> S; //作为栈使用
        std::string result = ""; //最终结果
        for(int i=0; i<num.length(); i++){ //从最高位遍历num
            int number = num[i] - '0'; //转换为数字
            while(S.size() != 0 && number<S[S.size()-1] && k>0){ //栈不为空，且栈顶大于number
                S.pop_back();
                k--; //删一个，可删的数少一个
            }
            if(S.size() != 0 || number != 0){
                S.push_back(number);
            }
        }
        
        while(S.size() != 0 && k>0){ //栈不为空，仍可删
            S.pop_back();
            k--;
        }
        for(int i=0; i<S.size(); i++){ //存储结果
            result += to_string(S[i]);
        }
        if(result == "")
            return "0";
        return result;
    }
};