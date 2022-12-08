#include <iostream>
using namespace std;
#include "menu.h"
#include "manager.h"


int main(int argc, char *argv[])
{
    Manager mgr;    //创建学生管理对象
    mgr.read();     //从文件中读取上次运行的学生数据

    int select;

    while(1)
    {
        Menu::showMenu();   //显示菜单
        cin >> select;      //输入选择
        switch(select)
        {
            case 0: mgr.exit();             return 0;   //退出
            case 1: mgr.addStudent();       break;  //增
            case 2: mgr.updateStudent();    break;  //改
            case 3: mgr.delStudent();       break;  //删
            case 4: mgr.sortStudent();      break;  //排序
            case 5: mgr.searchStudent();    break;  //查找某个
            case 6: mgr.showAllStudent();   break;  //显示所有
            case 7: mgr.write();            break;  //保存

            default: break;
        }
    }

    return 0;
}