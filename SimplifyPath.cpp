/*************************************************************************
	> File Name: SimplifyPath.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月07日 星期二 08时51分30秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

string simplifyPath(string path)
{
    path += "/";
    string result;
    size_t last = 0;
    size_t pos = path.find("/", last);
    while(pos != string::npos)
    {
        string temp = path.substr(last, pos-last);
        if(temp=="..")
        {
            if(!result.empty())
                result.resize(result.find_last_of("/"));
        }
        else if(!temp.empty() && temp!=".")
            result = result+"/"+temp;
        last = pos+1;
        pos = path.find("/", last);
    }
    return result.empty() ? "/" : result;
}

int main()
{
    string str("/a/./b/../../c/");
    cout<<simplifyPath(str)<<endl;

    return 0;
}

