#include<iostream>
using namespace std;
#include<string>

struct Hero
{
    /* data */
    string name;
    int age;
    string sex;
};

void bubbleSort(Hero heroArray[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len -i -1; j++)
        {
            if (heroArray[j].age > heroArray[j + 1].age)
            {
                Hero temp = heroArray[j];
                heroArray[j] = heroArray[j + 1];
                heroArray[j + 1] = temp;
            }
        }
    }
}

void printHero(Hero heroArray[], int len)
{
    for (int i = 0; i < len; i ++)
    {
        cout << "hero name: " << heroArray[i].name << "\thero age:" << heroArray[i].age << endl;
    }
}

int main()
{
    Hero heroArray[5] = 
    {
        {"like1", 18},
        {"like2", 20},
        {"like3", 16},
        {"like4", 22},
        {"like5", 25}
    };
    int len = sizeof(heroArray) / sizeof(heroArray)[0];

    bubbleSort(heroArray, len);

    printHero(heroArray, len);

    return 0;
}
