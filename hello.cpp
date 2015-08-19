/*************************************************************************
	> File Name: hello.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月17日 星期五 11时21分13秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
//    string s("dca");
//    string p("ab");
//    if(s.find_last_of(p) == string::npos) cout<<"so ga"<<endl;
//    cout<<s.find_last_of(p)<<endl;
//    int arr[] = {2, 5, 4, 3, 9, 2,6};
    int arr[] = {1};
    multiset<int> s(arr, arr + sizeof(arr)/sizeof(int));
    for(multiset<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.upper_bound(3)<<endl;
    return 0;
}

