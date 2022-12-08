#include "util.h"

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