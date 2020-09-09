#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1;  // 编译为空字符串
    string s2 = "c plus plus";
    string s3 = s2;
    string s4(5, 'a');

    int len = s2.length();
    cout << len << endl;

    string path = "./test.txt";
    const char *str = path.c_str(); // 转化为 c 的类型
    FILE *fp = fopen(str, "rt");

    for (char i : s3) {
        cout << i << " ";
    }
    cout << endl;
    s3[6] = '*';    // 能够被改变
    cout << s3 << endl;

    // use operator '+' to join
    cout << s3 + s4 << endl;

    // insert
    s2.insert(5, "233");
    cout << s2 << endl;

    // delete substring
    // s2: c plu233s plus
    s2.erase(5);
    cout << s2 << endl;
    // s3: c plus*plus
    s3.erase(6, 3);
    cout << s3 << endl;

    // substring
    string substr = s3.substr(0, 6);
    cout << substr << endl;

    // find
    s1 = "first second third";
    s2 = "second";
    int index = s1.find(s2, 5);
    if (index < s1.length())
        cout << "Found at index : " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
