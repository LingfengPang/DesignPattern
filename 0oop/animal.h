#include <iostream>
#include <string>

using namespace std;
// class Animal
// {
// private:
//     /* data */
//     string name;
//     int num;

// public:
//     Animal(string n): name(n),num(1){}
//     Animal(): name("none"),num(1){}
//     ~Animal(){}
//     int getnum(){return num;}
//     virtual void shout() = 0;//多态，子类重写父类方法
// };

// class Cat : public Animal
// {
// private:
//     //子类可以有自己的属性
// public:
//     Cat(string n): Animal(n){}
//     Cat(): Animal(){}
//     ~Cat(){}
//     void shout(){
//         for(int i = 0;i<getnum();i++)
//              cout << "miao"<<endl;
//         }
// };

// class Dog : public Animal
// {
// private:
//     //子类可以有自己的属性
// public:
//     Dog(string n): Animal(n){}
//     Dog(): Animal(){}
//     ~Dog(){}
//     void shout(){
//         for(int i = 0;i<Animal::getnum();i++)
//              cout << "wang"<<endl;
//         }
// };

//重构代码
class Animal//抽象类，不能实例化
{
private:
    /* data */
    string name;
    int num;

public:
    Animal(string n): name(n),num(1){}
    Animal(): name("none"),num(1){}
    ~Animal(){}
    int getnum(){return num;}
    virtual string getshout() = 0;//多态，子类重写父类方法
    void shout(){
        cout << getshout() <<endl;
    }
};

class Cat : public Animal
{
private:
    //子类可以有自己的属性
public:
    Cat(string n): Animal(n){}
    Cat(): Animal(){}
    ~Cat(){}
    string getshout(){return "miao";}
};


class Dog : public Animal
{
private:
    //子类可以有自己的属性
public:
    Dog(string n): Animal(n){}
    Dog(): Animal(){}
    ~Dog(){}
    string getshout(){return "wang";}
};