#include<iostream>
using namespace std;
#include<string>
#include<ctime>

struct Student
{
    string name;

    int score;
};

struct Teacher
{

    string name;

    Student stu[5];
};

void printInfo(Teacher tea[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << "tea name: " << tea[i].name << endl;

        for (int j = 0; j < 5; j++)
        {
            cout << "\tstu name: " << tea[i].stu[j].name << endl;
            cout << "\tstu score: " << tea[i].stu[j].score << endl;
        }
    }
}


void allocateSpace(Teacher tea[], int len)
{

    string nameSeed = "ABCDE";
    for (int i = 0; i < len; i++)
    {
        tea[i].name = "Teacher_";
        tea[i].name += nameSeed[i];

        for (int j = 0; j < 5; j++)
        {
            tea[i].stu[j].name = "Student_";
            tea[i].stu[j].name += nameSeed[j];

            int random = rand() % 61 + 40; // 0 ~ 60 + 40
            tea[i].stu[j].score = random;
        }

    }
}

int main()
{


    srand((unsigned int)time(NULL));
    
    Teacher tea[3];

    int len = sizeof(tea) / sizeof(tea[0]);

    allocateSpace(tea, len);

    printInfo(tea, len);



    return 0;
}