/*************************************************************************
	> File Name: LetterCombinationsOfAPhoneNumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年06月28日 星期日 17时10分59秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

class Solution
{
private:
    vector<string> result;
    map<char, string> digitLetter;
public:
    void letterCombinationsCore(string digits, int start, string& oneResult)
    {
        if(start == digits.size())
        {
            result.push_back(oneResult);
            return;
        }
        char digit = digits[start];
        string letters = digitLetter[digit];
        for(int i=0; i<letters.size(); ++i)
        {
            string temp(oneResult);
            temp += letters[i];
            letterCombinationsCore(digits, start+1, temp);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(digits.empty()) return result;
        string oneResult;
        char nums[] = {'2', '3', '4', '5', '6', '7', '8', '9'};
        string letters[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i=0; i<8; ++i)
            digitLetter[nums[i]] = letters[i];
        letterCombinationsCore(digits, 0, oneResult);
        return result;
    }
};

int main()
{
    string str1 = "23";
    Solution sol;
    vector<string> result = sol.letterCombinations(str1);
    for(int i=0; i<result.size(); ++i)
        cout<<result[i]<<endl;
    return 0;
}
