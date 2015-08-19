/*************************************************************************
	> File Name: RegularExpressionMatching.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月14日 星期二 15时25分48秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

/*
bool isMatch(string s, string p)
{
    if(p.empty()) return s.empty();
    else if(p.size() == 1) 
    {
        if(s.empty() || s.size() > 1) return false;
        return (p=="." || s==p);
    }
    else if(s.empty()) return false;
    if(p[1] == '*') 
    {
        if(p[0] == s[0] || (p[0] == '.' && !s.empty())) 
        {
            cout<<"s:"<<s<<",p:"<<p<<endl;
            if(isMatch(s.substr(1), p.substr(2))) 
            {
                cout<<"pattern1"<<endl;
                return true;
            }
            if(isMatch(s, p.substr(2)))
            {
                cout<<"pattern2"<<endl;
                return true;
            }
            if(isMatch(s.substr(1), p))
            {
                cout<<"pattern3"<<endl;
                return true;
            }
        }
        else 
            return isMatch(s, p.substr(2));
    }
    else if(p[0] == s[0] || (p[0] == '.' && !s.empty())) 
        return isMatch(s.substr(1), p.substr(1));
    else return false;
}
*/

bool isMatch(string s, string p)
{
    if(p.empty()) return s.empty();
    if(p.size() == 1) 
    {
        if(s.empty() || s.size()>1) return false;
        return (p[0] == '.' || (p[0] == s[0]));
    }
    else 
    {
        if(p[1] == '*')
        {
            while(!s.empty() && (p[0] == '.' || p[0] == s[0]))
            {
                if(isMatch(s, p.substr(2))) return true;
                s = s.substr(1);
            }
            return isMatch(s, p.substr(2));
        }
        else if(!s.empty() && (p[0] == '.' || p[0] == s[0])) return isMatch(s.substr(1), p.substr(1));
        else return false;
    }
}

int main()
{
//    string s1("aa");
//    string p1("a");
//    cout<<isMatch(s1, p1)<<endl;
//    string s2("aa");
//    string p2("aa");
//    cout<<isMatch(s2, p2)<<endl;
//    string s3("aaa");
//    string p3("aa");
//    cout<<isMatch(s3, p3)<<endl;
//    string s5("aa");
//    string p5(".*");
//    cout<<isMatch(s5, p5)<<endl;
//    string s6("ab");
//    string p6(".*");
//    cout<<isMatch(s6, p6)<<endl;
//    string s7("aab");
//    string p7("c*a*b");
//    cout<<isMatch(s7, p7)<<endl;
    string s8("aaba"); 
    string p8("ab*a*c*a");
    cout<<isMatch(s8, p8)<<endl;

    return 0;
}
