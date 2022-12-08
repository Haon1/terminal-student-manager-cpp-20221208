#include <iostream>
#include <student.h>

//无参构造
Student::Student(){}

//带参构造,初始化成员变量
Student::Student(string id, string name, string dormitory, float score, string addr)
{
    this->id = id;
    this->name = name;
    this->dormitory = dormitory;
    this->score = score;
    this->addr = addr;
}

//重载 == 符
bool Student::operator==(Student &other)
{
    if(id==other.id && name==other.name && dormitory==other.dormitory && score==other.score && addr==other.addr)
        return true;
    else
        return false;
}