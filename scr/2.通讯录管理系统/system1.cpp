#include<iostream>
using namespace std;
#include<string>

struct Person
{
    string name;
    int sex;
    int age;
    string call;
    string addr;
};

#define MAX 1000

struct Addressbooks
{
    Person personArray[MAX];
    int size;
};

void showMenu()
{
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}

void addPerson(Addressbooks * abs)//添加联系人
{
    //判断通讯录是否满员
    if (abs->size == MAX)
    {
        cout << "已满!" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;

        int sex = 0;
        cout << "请输入性别: (1代表男性, 0代表女性)" << endl;
        while (true)
        {
            //如果输入的是1或2,可以退出循环
            cin >> sex;
            if (sex == 1 || sex == 0)
            {
                abs->personArray[abs->size].sex = sex;
                break;
            }
            cout << "输入有误,请重新输入!" << endl;
        }

        int age = 0;
        cout << "请输入年龄: " << endl;
        cin >> age;
        abs->personArray[abs->size].age = age;

        string call;
        cout << "请输入电话号码: " << endl;
        cin >> call;
        abs->personArray[abs->size].call = call;
        
        string addr;
        cout << "请输入家庭地址: " << endl;
        cin >> addr;
        abs->personArray[abs->size].addr = addr;

        //更新通讯录人数
        abs->size++;
        cout << "添加成功!" << endl;

    }
}

void showPerson(Addressbooks * abs)//显示所有联系人
{
    if (abs->size == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "name: " << abs->personArray[i].name << "\t";
            cout << "sex: " << (abs->personArray[i].sex == 1 ?"男":"女") << "\t";
            cout << "age: " << abs->personArray[i].age << "\t";
            cout << "call: " << abs->personArray[i].call << "\t";
            cout << "addr: " << abs->personArray[i].addr << endl;
        }
    }
}

int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;//找到删除的联系人 返回其编号
        }
    }
    return -1;//没找到
}

void deletePerson(Addressbooks * abs)//删除特定联系人
{
    cout << "请输入需要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)//删除联系人即做数据前移
    {
        for (int i = ret; i < abs->size; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->size--;
        cout << "delete successful" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void findPerson(Addressbooks * abs)//查找特定联系人
{
    cout << "请输入查找的联系人信息" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "name: " << abs->personArray[ret].name << "\t";
        cout << "sex: " << (abs->personArray[ret].sex == 1 ?"男":"女") << "\t";
        cout << "age: " << abs->personArray[ret].age << "\t";
        cout << "call: " << abs->personArray[ret].call << "\t";
        cout << "addr: " << abs->personArray[ret].addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

void modifyPerson(Addressbooks * abs)//修改特定联系人
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        while (true)
        {
            cout << "1.name: " << abs->personArray[ret].name << "\t";
            cout << "2.sex: " << (abs->personArray[ret].sex == 1 ?"男":"女") << "\t";
            cout << "3.age: " << abs->personArray[ret].age << "\t";
            cout << "4.call: " << abs->personArray[ret].call << "\t";
            cout << "5.addr: " << abs->personArray[ret].addr << endl;
            cout << "选择您想修改的信息,或者输入0,退回" << endl;
            int want;
            cin >> want;

            if (want == 1)
            {
                string name;
                cout << "请输入姓名: " << endl;
                cin >> name;
                abs->personArray[ret].name = name;
            }
            if (want == 2)
            {
                int sex = 0;
                cout << "请输入性别: (1代表男性, 0代表女性)" << endl;
                while (true)
                {
                    cin >> sex;
                    if (sex == 1 || sex == 0)
                    {
                        abs->personArray[ret].sex = sex;
                        break;
                    }
                    cout << "输入错误,请重新选择!" << endl;
                    break;
                }
            }
            if (want == 3)
            {
                int age = 0;
                cout << "请输入年龄: " << endl;
                cin >> age;
                abs->personArray[ret].age = age;
            }
            if (want == 4)
            {
                string call;
                cout << "请输入电话: " << endl;
                cin >> call;
                abs->personArray[ret].call = call;
            }
            if (want == 5)
            {
                string addr;
                cout << "请输入地址:" << endl;
                cin >> addr;
                abs->personArray[ret].addr = addr;
            }
            if (want == 0)
            {
                break;
            }
        }
        
    }
    else
    {
        cout << "not found" << endl;
    }
}

void cleanPerson(Addressbooks * abs)
{
    abs->size = 0;
    cout << "通讯录已清空" << endl;
}

int main()
{

    Addressbooks abs;

    abs.size = 0;//通讯录初始为0

    int select = 0;

    while (true)
    {
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:
            addPerson(&abs);//利用地址传递
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            cleanPerson(&abs);
            break;
        case 0:
            cout << "thanks" << endl;
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}