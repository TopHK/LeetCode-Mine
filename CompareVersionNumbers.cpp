/*************************************************************************
	> File Name: CompareVersionNumbers.cpp
	> Author: 
	> Mail: 
	> Created Time: 2015年07月02日 星期四 12时52分54秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
void print(const vector<string>& strs);
int compareString(string str1, string str2)
{
    int size1 = str1.size();
    int size2 = str2.size();
    if(size1 > size2) return 1;
    else if(size1 < size2) return -1;
    else 
    {
        if(str1.compare(str2) > 0) return 1;
        else if(str1.compare(str2) < 0) return -1;
        else return 0;
    }
}

void processString(const string& version, vector<string>& levelsOfVersion)
{
    size_t pos1 = 0;
    size_t pos2 = 0;
    size_t posOfNotZero;
    while(pos1 != string::npos)
    {
        pos2 = version.find('.', pos1);
        string temp;
        if(pos2 != string::npos)
            temp = version.substr(pos1, pos2-pos1);
        else 
            temp = version.substr(pos1);
        posOfNotZero = temp.find_first_not_of('0');
        if(posOfNotZero!=string::npos)
        {
            temp = temp.substr(posOfNotZero);
            levelsOfVersion.push_back(temp);
        }
        else levelsOfVersion.push_back("0");
        if(pos2 == string::npos) return;
        pos1 = pos2+1;
    }
}

int compareVersion(string version1, string version2)
{
    if(version1 == version2) return 0;
    vector<string> levelsOfVersion1;
    vector<string> levelsOfVersion2;
    processString(version1, levelsOfVersion1);
    processString(version2, levelsOfVersion2);
    print(levelsOfVersion1);
    print(levelsOfVersion2);
    int size1 = levelsOfVersion1.size();
    int size2 = levelsOfVersion2.size();
    int i = 0;
    int j = 0;
    while(i<size1 && j<size2)
    {
        int compare = compareString(levelsOfVersion1[i], levelsOfVersion2[j]);
        if(compare > 0) return 1;
        else if(compare < 0) return -1;
        i++;
        j++;
    }
    if(i < size1) 
    {
        if(levelsOfVersion1[i] == "0") return 0;
        else return 1;
    }
    else if(j < size2) 
    {
        if(levelsOfVersion2[j] == "0") return 0;
        else return -1;
    }
    else return 0;
}

void print(const vector<string>& strs)
{
    for(int i=0; i<strs.size(); ++i)
        cout<<strs[i]<<" ";
    cout<<endl;
}

int main()
{
    string version1 = "1.0";
    string version2 = "1";
    cout<<compareVersion(version1, version2)<<endl;

    return 0;
}

