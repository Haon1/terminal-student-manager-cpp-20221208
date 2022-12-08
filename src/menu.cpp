#include <iostream>
#include "menu.h"
#include "util.h"

using namespace std;

//显示菜单
void Menu::showMenu()
{
    Util::clearScreen();    //清屏
    cout << "\n\n" ;
    cout << "\t\t|------------------------------------------|\n" ;
    cout << "\t\t|             学生信息系统主菜单           |\n" ;
    cout << "\t\t|------------------------------------------|\n" ;
    cout << "\t\t|              1  学生信息添加             |\n" ;
    cout << "\t\t|              2  学生信息修改             |\n" ;        
    cout << "\t\t|              3  学生信息删除             |\n" ;        
    cout << "\t\t|              4  学生信息排序             |\n" ;
    cout << "\t\t|              5  学生信息查找             |\n" ;
    cout << "\t\t|              6  学生信息显示             |\n" ;
    cout << "\t\t|              7  学生信息保存             |\n" ;
    cout << "\t\t|                                          |\n" ;
    cout << "\t\t|              0   退     出               |\n" ;
    cout << "\t\t|------------------------------------------|\n" ;
    cout << "\t请输入你的选择<0~7>:" ;
    cout << "\t";
}