//懒汉模式：顾名思义，是一种典型的拖延（lazy）策略。当第一次要用单例类的时候，再产生实例
#include <iostream>

using namespace std;

class Singleton
{
public:
    ~Singleton();
    //提供单例类的访问方法
    static Singleton* getInstance();
    //提供删除方法
    static void deleteInstance();
    void doSomething();
protected:
    Singleton();//构造方法定义为protect
    static Singleton* theSingleton; //单例类对象指针

};

Singleton* Singleton::theSingleton = nullptr;//讲我们的单例对象指针初始化空

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}

Singleton* Singleton::getInstance()
{
    if (!theSingleton)
        theSingleton = new Singleton();
    return theSingleton;
}

void Singleton::deleteInstance()
{
    if (theSingleton) {
        delete theSingleton;
        theSingleton = nullptr;
    }
}

void Singleton::doSomething()
{
    cout << "lazy"  << endl;
}

int main()
{
    Singleton::getInstance()->doSomething();
    return 0;
}