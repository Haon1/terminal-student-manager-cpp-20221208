#include "util.h"
#include <sstream>
#include <iostream>
using namespace std;
#include <vector>

extern "C" {
    #include <stdlib.h>
    #include <stdio.h>
}

//清屏
void Util::clearScreen()
{
    system("clear");
}

//等待按下回车
void Util::pause()
{
    while(getchar()!='\n');
    getchar();
}

//拼接标题样式
string Util::title(string text)
{
    //"\t\t######\ttext\t######\n\n"
    string title = "\t\t######\t";
    title += text;
    title += "\t######\n\n";

    return title;
}

//拼接提示语样式
string Util::tip(string text)
{
    //"\n\n\t\t添加成功\n\n" 
    string tip = "\n\n\t\t";
    tip += text;
    tip += "\n\n";

    return tip;
}

/**
 * @brief 切割字符串
 *
 * @param str 要切割的字符串
 * @param split 分隔符
 * @param value 切割后的元素保存
 */
void Util::stringsplit(string str,const char split,vector<string>& value)
{
    istringstream iss(str);    // 输入流
    string data;            // 接收缓冲区
    while (getline(iss, data, split))    // 以split为分隔符
    {
        value.push_back(data);
    }
}