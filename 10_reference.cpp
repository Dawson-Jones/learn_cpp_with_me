// 说白了, 还是指针...

#include <iostream>

using namespace std;

void my_swap(int &r1, int &r2);
int &plus10(int &num);

int main() {
    int num1, num2;
    cout << "input two integers: ";
    cin >> num1 >> num2;
    my_swap(num1, num2);
    cout << num1 << " " << num2 << endl;

    int num = 10;
    int &alias_num = plus10(num);
    cout << num << " " << alias_num << endl;    // 20, 20
}

void my_swap(int &r1, int &r2) {
    int temp = r1;
    r1 = r2;
    r2 = temp;
}

int &plus10(int &num) {
    num += 10;
    return num;
}
