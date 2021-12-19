/*
模板特化按对象类型（类和全局函数)分为两种: 类模板的特化和全局模板函数的特化;
按特化的类型分全特化和偏特化(也就是多个模板参数可以选定只特化一个或者多个）,全局模板函数的特化不支持偏特化;
全局模板函数的特化需要关注几个重要元素函数返回值 函数名 形参类型、个数和顺序,eg:template T max_(const T &, const T &);
类模板的特化需要关注几个重要元素类名,形参类型和个数，形参的顺序倒不重要了;
一般调用规律：形参顺序，全特化->偏特化->泛型
一般模板参数：类class，函数typename
*/

#include <iostream>
using namespace std;


/* 类模板 */
namespace templateTest {
    //模板泛化
    template<class T>
    class iterator_traits {
    public:
        iterator_traits()
        {
            cout << "模板泛化 constructor" << endl;
        }
        ~iterator_traits()
        {
            cout << "模板泛化 destructor" << endl;
        }
    };

    //偏特化
    template<class T>
    class iterator_traits<T *> {
    public:
        iterator_traits()
        {
            cout << "模板偏特化 constructor" << endl;
        }
        ~iterator_traits()
        {
            cout << "模板偏特化 destructor" << endl;
        }
    };

    //偏特化
    template<class T>
    class iterator_traits<const T *> {
    public:
        iterator_traits()
        {
            cout << "模板偏特化 const指针 constructor" << endl;
        }
        ~iterator_traits()
        {
            cout << "模板偏特化 const指针 destructor" << endl;
        }
    };

    //全特化
    template<>
    class iterator_traits<int> 
    {
    public:
        iterator_traits()
        {
            cout << "模板全特化 constructor" << endl;
        }
        ~iterator_traits()
        {
            cout << "模板全特化 destructor" << endl;
        }
    };
};

//泛化
template<class U, class T>
class Test
{
public:
    Test()
    {
        cout << "Test 泛化" << endl;
    }
};

//偏特化
template<class T>
class Test<int, T>
{
public:

    Test()
    {
        cout << "Test 偏特化" << endl;
    }
};

//全特化
template<>
class Test<int, char>
{
public:

    Test()
    {
        cout << "Test 全特化" << endl;
    }
};



/* 函数模板 */
template<typename T>
T max(const T& t1, const T & t2)
{
    cout << "模板函数泛化" << endl;
    return t1 > t2 ? t1 : t2;
}

template<>
int max(const int& t1, const int& t2)
{
    cout << "模板函数特化" << endl;
    return t1 > t2 ? t1 : t2;
}


int main()
{
    templateTest::iterator_traits<int> t1;
    templateTest::iterator_traits<float> t2;
    templateTest::iterator_traits<int *> t3;
    templateTest::iterator_traits<const int *> t4;
    Test<int, int> t5;
    Test<float, int> t6;
    Test<int, char> t7;
    cout << "max(5, 10)" << max(5, 10) << endl;
    cout << "max(5.5, 10.5)" << max(5.5, 10.5) << endl;
    system("pause");
}

