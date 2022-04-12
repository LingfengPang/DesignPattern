//饿汉模式
//饿汉模式与懒汉模式相反，是程序一开始就生成唯一实例。这样就不用检查是否存在实例，而且也无需考虑产生实例时的线程安全。

#include <iostream>

using namespace std;

class Singleton {
public:
    ~Singleton();
    //提供单例对象访问
    static Singleton& getInstance();
    void doSomething();
protected:
    //构造函数声明为 保护方法
    Singleton();
    //单例对象指针
    static Singleton theSingleton;
};
Singleton Singleton:: theSingleton = Singleton::getInstance();  //////
//提供单例类对象访问
Singleton& Singleton::getInstance() {
    return theSingleton;
}

void Singleton::doSomething()
{
    cout << "饿懒汉模式" << "\n" << "单例模式" << endl;
}

Singleton::Singleton()
{
}
Singleton::~Singleton()
{}

int main()
{
    Singleton::getInstance().doSomething();
    return 0;
}//很不负责的把这段代码放在这