#pragma once
#include <memory>

class MyClassB;
class MyClassA
{
public:
    MyClassA();
    ~MyClassA();
    void set_ptr(std::shared_ptr<MyClassB> ptr) {
        m_ptr_b = ptr;
    }
    void b_use_count() { 
        std::cout << "b use count : " << m_ptr_b.use_count() << std::endl;
    }
    void show() { 
        std::cout << "this is class MyClassA!" << std::endl;
    }
private:
    std::weak_ptr<MyClassB> m_ptr_b;//ʹ��shared_ptr�ᵼ��ѭ�����õ����⣬�ᵼ���ڴ�й¶

};

MyClassA::MyClassA()
{
    std::cout << "MyClassA()" << std::endl;
}

MyClassA::~MyClassA()
{
    std::cout << "~MyClassA()" << std::endl;
}



class MyClassB
{
public:
    MyClassB();
    ~MyClassB();
    void set_ptr(std::shared_ptr<MyClassA> ptr) {
        m_ptr_a = ptr;
    }
    void a_use_count() {
        std::cout << "a use count : " << m_ptr_a.use_count() << std::endl;
    }
    void show() {
        std::cout << "this is class MyClassB!" << std::endl;
    }
private:
    std::shared_ptr<MyClassA> m_ptr_a;
};

MyClassB::MyClassB()
{
    std::cout << "MyClassB()" << std::endl;
}

MyClassB::~MyClassB()
{
    std::cout << "~MyClassB()" << std::endl;
}



void testClass() {
    std::shared_ptr<MyClassA> ptr_a(new MyClassA);
    std::shared_ptr<MyClassB> ptr_b(new MyClassB);
    std::cout << "count: " << ptr_a.use_count() << std::endl;  // count: 1
    std::cout << "count: " << ptr_b.use_count() << std::endl;  // count: 1

    std::weak_ptr<MyClassA> wk_ptr_a = ptr_a;
    std::weak_ptr<MyClassB> wk_ptr_b = ptr_b;
    if (!wk_ptr_a.expired()) {
        wk_ptr_a.lock()->show();
    }

    if (!wk_ptr_b.expired()) {
        wk_ptr_b.lock()->show();
    }
    wk_ptr_b.reset();                   // ��wk_ptr_b��ָ�����
    if (wk_ptr_b.expired())
    {
        std::cout << "wk_ptr_b is invalid" << std::endl;  // �����wk_ptr_b is invalid ˵����ָ���Ѿ���Ч
    }
    wk_ptr_b = ptr_b;
    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->show();        // �����this is class CB! ���ø�ֵ������wk_ptr_b�ָ���Ч
    }
    std::cout << "count: " << ptr_a.use_count() << std::endl;  // count: 1
    std::cout << "count: " << ptr_b.use_count() << std::endl;  // count: 1

    ptr_a->set_ptr(ptr_b);
    ptr_b->set_ptr(ptr_a);
    std::cout << "count: " << ptr_a.use_count() << std::endl;  // count: 1
    std::cout << "count: " << ptr_b.use_count() << std::endl;  // count: 1
 
}