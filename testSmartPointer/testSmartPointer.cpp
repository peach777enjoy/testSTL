// testSmartPointer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
测试智能指针，unique_ptr,shared_ptr,weak_ptr,还可以用auto_ptr
unique_ptr是独占指针，不支持拷贝和赋值
shared_ptr是共享指针，可以拷贝赋值,通过引用计数记录有多少个共享指针指向同一个对象。
*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

void testUnique() {
    //1.构造
    //int t = 1;
//std::unique_ptr<int> up(&t);           //不支持这样的构造方式，不支持指针赋值
    std::unique_ptr<int> up(new int(11));
    //std::unique_ptr<int> up2 = up1;        // err, 不能通过编译
    std::cout << *up << std::endl;    //11
    
    //2.移动
    std::unique_ptr<int> up3 = std::move(up); //当前指针指向改变up::null  up3:11
    std::cout << *up3 << std::endl;
    // std::cout << *up << std::endl;   // err, 运行时错误，空指针
    up3.reset();    //显示释放内存
    up.reset();    //不会导致运行时错误
    // std::cout << *up3 << std::endl;   // err, 运行时错误，空指针
    std::unique_ptr<int> up4(new int(22));
    up4.reset(new int(44));
    std::cout << *up4 << std::endl; //44
    up4 = nullptr; //显示销毁所指对象，同时智能指针变为空指针，与up.reset()等价

    //3.release释放控制权，不释放内存
    std::unique_ptr<int> up5(new int(55));
    int *p = up5.release(); //只是释放控制权，不会释放内存
    std::cout << *p << std::endl;    //55
    // cout << *up5 << endl; // err, 运行时错误，不再拥有内存
    delete p; // 释放堆区资源
}

void testShared() {
    std::shared_ptr<int> sp1(new int(22));
    std::shared_ptr<int> sp2 = sp1;
    std::cout << *sp1 << std::endl;
    std::cout << *sp2 << std::endl;
    std::cout << "use_count:" << sp2.use_count() << std::endl; //2
    sp1.reset(); //显示让引用计数减一
    std::cout << *sp2 << std::endl;
    std::cout << "use_count:" << sp2.use_count() << std::endl; //1

    //make_shared函数
    std::shared_ptr<int> p3 = std::make_shared<int>(42);
    std::shared_ptr<std::string> p4= std::make_shared<std::string>(10,'5');
    std::shared_ptr<int> p5 = std::make_shared<int>(10);
    auto p6 = std::make_shared<std::vector<std::string>>();
    auto q = p6;
}

void testWeak() {

}

int main()
{
    std::cout << "start!!!\n";
    //testUnique();
    //testShared();
    testWeak();
    std::cout << "end!!!\n";

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
