#include<iostream>
using namespace std;

class Base {
public:
    Base() {}
    // ~Base();     // 只调用了基类的 DestructFunction 导致内存泄漏

    virtual ~Base();
};

class Subclass : public Base {
public:
    Subclass() {}
    ~Subclass();
};

Base::~Base() {
    cout << "Base destructor is called." << endl;
}

Subclass::~Subclass() {
    cout << "Subclass destructor is called." << endl;
}

int main() {
    Base *b = new Subclass;
    delete b;
    return 0;
}