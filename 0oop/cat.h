#include <iostream>
#include <string>

using namespace std;
class Cat
{
private:
    /* data */
    string name;
    int num;

public:
    Cat(string n): name(n),num(1){}
    Cat(): name("none"),num(1){}
    ~Cat();
    void shout(){
        for(int i = 0;i<num;i++)
             cout << "miao"<<endl;
        }
};



Cat::~Cat()
{
}
