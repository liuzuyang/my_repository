#include <vector>
#include <iostream>
#include "String.h"
#include "strvec.h"


int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using test::String;
    using test::c_strvec;

                //拷贝构造函数测试
//    String s1{ "one" }, s2{ "two" };	//调用String(const char *)
//    cout << s1 << " " << s2 << endl << endl;
//    String s3{ s2 };	//调用拷贝构造函数
//    cout << s1 << " " << s2 << " " << s3 << endl << endl;
//    s3 = s1;	//调用赋值运算符
//    cout << s1 << " " << s2 << " " << s3 << endl << endl;
//    s3 = String{ "Three" };			//调用拷贝构造函数
//    cout << s1 << " " << s2 << " " << s3 << endl << endl;
//
//    std::vector<String> vs;
//    //vs.reserve(4);
//    vs.push_back(s1);	//先copy 内存不足 在copy
//    cout << "size: " << vs.size() << " | "<< "capacity: " << vs.capacity() << endl;
//    vs.push_back(std::move(s2));	//同上
//    cout << "size: " << vs.size() << " | "<< "capacity: " << vs.capacity() << endl;
//    vs.push_back(String{ "Three" });	//copy 同上
//    cout << "size: " << vs.size() << " | "<< "capacity: " << vs.capacity() << endl;
//    vs.push_back("Four");	//	内存不足一次copy
//    cout << "size: " << vs.size() << " | "<< "capacity: " << vs.capacity() << endl;
//    for (const auto &val : vs)
//    {
//        cout << val << " | ";
//    }
//    cout << "结束" << endl;
//    cout << endl;

    String str1{"liuzuyang"};
    String str2{str1};
    String str3{"dudongming"};
    c_strvec c_s1;
    c_s1.push_back("liuzuyang");
    c_s1.push_back("dudongming");
    cout << c_s1[1] << endl;
    cout << str1[0] << endl;
    cout << "str1 == str2: " << (str1 == str2 ? "true" : "false") << endl;
    cout << "str1 == str3: " << (str1 == str3 ? "true" : "false") << endl;
}
