#ifndef _MANAGER_H__
#define _MANAGER_H__

#include <vector>
#include "student.h"

class Manager
{
public:
    Manager();

    //添加学生引导函数
    void addStudent();      

    //添加学生功能函数
    void _addStudent(Student &student); 

    //显示一个学生信息
    void showOneStudent(Student &student);  

    //显示所有学生信息
    void showAllStudent();      
    
    //删除学生信息
    void delStudent();   

    //修改学生信息
    void updateStudent();       

    //查询学生信息
    void searchStudent();       

    //按学生成绩排序
    void sortStudent();

    //判断学生是否存在
    Student *isStudentExist(string &id);

    //从文本中读取数据
    void read(string path="student.txt");

    //数据写入文本
    void write(string path="student.txt");

    //退出
    void exit();

private:

    //vector容器，用于存放所有学生数据
    vector<Student> stuVector;
    
};

#endif
