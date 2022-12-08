#include <iostream>
using namespace std;
#include <fstream>
#include <cstring>
#include "manager.h"
#include "util.h"

//无参构造
Manager::Manager(){}

void Manager::_addStudent(Student &student)
{
    //把 student 加到vector容器中
    stuVector.push_back(student);
}

/**
 * @brief 学生信息添加
 * 
 */
void Manager::addStudent()
{
    //清屏
    Util::clearScreen();
    //显示标题
    cout << Util::title("学生信息添加");

    //创建学生对象
    Student stu;

    //赋值
    cout << "\t\t学号:"; cin >> stu.id;
    cout << "\t\t姓名:"; cin >> stu.name;
    cout << "\t\t宿舍:"; cin >> stu.dormitory;
    cout << "\t\t成绩:"; cin >> stu.score;
    cout << "\t\t住址:"; cin >> stu.addr;

    //把赋值好的学生添加到 vector中
    _addStudent(stu);

    cout << Util::tip("添加成功");
    cout << "\t\t按下回车继续..." ;
    //等待按下回车继续
    Util::pause();
}

/**
 * @brief 显示一个学生信息
 * 
 */
void Manager::showOneStudent(Student &student)
{
    cout << "\t\t";
    cout << student.id << " " << student.name << " " << student.dormitory <<\
    " " << student.score << " "  << student.addr;
    cout << endl;
}

/**
 * @brief 显示所有学生信息
 * 
 */
void Manager::showAllStudent()
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息显示");    //显示标题

    //遍历 vector容器
    for(int i=0;i<stuVector.size();i++)
    {
        //分别显示每个学生的信息
        showOneStudent(stuVector[i]);
    }

    
    cout << "\n\n\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();
}

/**
 * @brief 判断学生是否存在
 * 
 * @param id 要判断的学生学号
 * @return 该生存在返回 Student*  不存在返回NULL 
 */
Student *Manager::isStudentExist(string &id)
{
    //遍历容器
    for(int i=0; i<stuVector.size(); i++)
    {
        //找到该 id  说明该生存在
        if(stuVector[i].id == id)
        {
            //返回该生对象地址
            return &stuVector[i];
        }
    }

    //循环结束没找到， 说明不存在
    return NULL;
}

/**
 * @brief 学生信息删除函数
 * 
 */
void Manager::delStudent()
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息删除");    //显示标题

    //创建 vector容器迭代器,用于遍历容器
    vector<Student>::iterator it = stuVector.begin();
    string id;
    
    cout << "\t\t要删除的学生学号:"; cin >> id;

    //判断该生是否存在
    Student *p = isStudentExist(id);
    if(NULL == p)    //不存在
    {
        cout << Util::tip("该学生不存在");
        goto end;   //去到  end 标签位置
    }

    //用迭代器遍历vector容器
    //为什么用下标[]可以遍历容器，还要用迭代器遍历呢? 因为 vector要删除元素只能用 erase(),参数是一个迭代器
    for( ; it!=stuVector.end(); it++)
    {
        //判断是不是要删除的学生，这就是重载 == 的用处
        if(*it == *p)
        {
            stuVector.erase(it);    //删除
            break;
        }
    }
    cout << Util::tip("删除成功");

end:
    cout << "\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();
}

/**
 * @brief 修改学生信息
 * 
 */
void Manager::updateStudent()
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息修改");    //显示标题

    string id;
    
    cout << "\t\t要修改的学生学号:"; cin >> id;

    //判断学生是否存在
    Student *p = isStudentExist(id);
    if(NULL == p)
    {
        cout << Util::tip("该学生不存在");
        goto end;
    }

    cout << "\t\t新学号:"; cin >> p->id;
    cout << "\t\t新姓名:"; cin >> p->name;
    cout << "\t\t新宿舍:"; cin >> p->dormitory;
    cout << "\t\t新成绩:"; cin >> p->score;
    cout << "\t\t新住址:"; cin >> p->addr;

    cout << Util::tip("修改成功");

end:
    cout << "\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();
}

/**
 * @brief 查找某个学生信息
 * 
 */
void Manager::searchStudent()
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息修改");    //显示标题

    string id;
    
    cout << "\t\t要修改的学生学号:"; cin >> id;

    //判断学生是否存在
    Student *p = isStudentExist(id);
    if(NULL == p)
    {
        cout << Util::tip("该学生不存在");
        goto end;
    }

    cout << "\n";
    //显示该生信息
    showOneStudent(*p);
    
    cout << "\n\n" ;

end:
    cout << "\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();
}


/**
 * @brief 按照学号升序排序
 * 
 */
void Manager::sortStudent()
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息排序");    //显示标题

    //新建一个临时 容器，排序不会影响原来的数据
    vector<Student> tmpVector = stuVector;
    int size = tmpVector.size();    //获取容器大小，也就是学生数量

    //冒泡排序
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            //取出前后两个学生学号
            int a = atoi(tmpVector[j].id.c_str());
            int b = atoi(tmpVector[j+1].id.c_str());
            if( a > b)
            {
                Student stu = tmpVector[j];
                tmpVector[j] = tmpVector[j+1];
                tmpVector[j+1] = stu;
            }
        }
    }

    //显示排序后的学生数据
    for(int i=0;i<tmpVector.size();i++)
    {
        //分别显示每个学生的信息
        showOneStudent(tmpVector[i]);
    }

    
    cout << "\n\n\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();
}

/**
 * @brief 从文件中读取数据
 *
 * @param path 要写入的文件路径
 */
void Manager::read(string path)
{
    ifstream fin;
    fin.open(path);     //in方式打开文本
    if(!fin.is_open())  //若文本打开失败则说明文件不存在
    {
        ofstream fout(path);    //创建一个文件
        fout.close();           //关闭文件退出
        return ;
    }

    //文件数据保存缓冲区，每次保存一行数据
    char data[128]={0};

    //每次从文本中读一行数据到 缓冲区中
    while(fin.getline(data,128))
    {
        string str = data;  //读出来的数据是带空格的 例如"1 1 1 1 1",需要按空格切割出来,拿出五个数据给学生对象赋值
        vector<string> value;   //切割后的数据保存容器
        Util::stringsplit(data,' ',value);  //以 空格 为分割符 切割一行数据

        //新建学生对象并且用切割出来的数据给 成员变量赋值
        Student stu;
        stu.id = value[0];
        stu.name = value[1];
        stu.dormitory = value[2];
        stu.score = atof(value[3].c_str());
        stu.addr = value[4];

        //把赋值好的学生对象加入到 stuVector中
        stuVector.push_back(stu);
        //cout << stu.id << stu.name << stu.dormitory << stu.score << stu.addr << endl;
    }

    //关闭文件
    fin.close();
}

/**
 * @brief 数据写入文件
 * 
 * @param path 要写入的文件路径
 */
void Manager::write(string path)
{
    Util::clearScreen();                    //清屏
    cout << Util::title("学生信息保存");    //显示标题

    int i;
    ofstream fout;     //out 模式文件不存在会自动创建
    fout.open(path);   //打开文件
    if(!fout.is_open())    //判断是否打开成功
    {
        cout << Util::tip("文件打开失败");
        goto end;
    }

    //把数据写入文件
    for(i=0; i<stuVector.size(); i++)
    {
        Student stu = stuVector[i];
        fout << stu.id << " "\
             << stu.name << " "\
             << stu.dormitory << " "\
             << stu.score << " "\
             << stu.addr << " " << endl;
    }
    //关闭文件
    fout.close();

    cout << Util::tip("保存成功");

end:
    cout << "\t\t按下回车继续..." ;
    //等待按下回车
    Util::pause();

}

//退出程序
void Manager::exit()
{
    Util::clearScreen();
    cout << "\n" << Util::title("感谢使用  再见");
}
