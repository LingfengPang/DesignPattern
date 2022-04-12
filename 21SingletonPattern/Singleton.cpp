#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton& Instance()
    {
        static Singleton theSingleton;
        return theSingleton;
    }
    void doSomeThong();
private:
    Singleton();
    ~Singleton();
};

Singleton::Singleton()
{
}

Singleton::~Singleton()
{
}
void Singleton::doSomeThong()
{
    cout << "Singleton" << endl;
    //cout << "C++最推荐的单例类写法" << endl;
}

int main()
{
    Singleton::Instance().doSomeThong();
    system("pause");
    return 0;
}