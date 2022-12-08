#ifndef _UTIL_H__
#define _UTIL_H__
#include <iostream>
using namespace std;
#include <vector>

class Util
{
public:
    //清屏
    static void clearScreen();

    //等待按下回车
    static void pause();

    //拼接标题样式
    static string title(string text);

    //拼接提示语样式
    static string tip(string text);

    //string 切割
    static void stringsplit(string str,const char split,vector<string>& value);
};

#endif
