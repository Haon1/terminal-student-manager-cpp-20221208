#ifndef _STUDENT_H__
#define _STUDENT_H__

#include <iostream>
using namespace std;

class Student
{
public:
    Student();
    Student(string id, string name, string dormitory, float score, string addr);


    string id;          //学号
    string name;        //姓名
    string dormitory;    //宿舍号
    float score;        //成绩
    string addr;        //住址

    //重载 ==
    bool operator==(Student &other);
};

#endif
