#include <iostream>

using namespace std;

class Stu {
private:
    char *m_name;
    int m_age;
    float m_score;
public:
    // 构造函数， 和类同名
    // 一个类必须有构造函数，要么用户自己定义，要么编译器自动生成。
    // 一旦用户自己定义了构造函数，不管有几个，也不管形参如何，编译器都不再自动生成。
    Stu(char *name, int age, float score);

    void show();
};

// 定义函数
Stu::Stu(char *name, int age, float score) {
    m_name = name;
    m_age = age;
    m_score = score;
}

void Stu::show() {
    cout << m_name << "的年龄是" << m_age << ", 成绩： " << m_score << endl;
}

int main() {
    Stu stu("dawson", 20, 92.5);
    stu.show();

    Stu *pstu = new Stu("milly", 18, 96);
    pstu->show();
    delete pstu;
}


