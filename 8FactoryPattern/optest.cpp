#include <iostream>
#include <string>
using namespace std;
//抽象类产品
template <typename T>
class OP{
private:
    T a;
    T b;
public:
    OP():a(1),b(1){}
    OP(T A,T B):a(A),b(B){}
    T geta(){return a;}
    T getb(){return b;}
    virtual T getResult() = 0;
};
//ConcreteProduct(具体产品)
template <typename T>
class OPAdd:public OP<T>{
public:
    OPAdd():OP<T>(){}
    OPAdd(T A,T B):OP<T>(A,B){}
    T getResult(){
        //继承的模板类使用this访问
        return this->geta()+this->getb();
    }
};

template <typename T>
class OPDiv:public OP<T>{
public:
    OPDiv():OP<T>(){}
    OPDiv(T A,T B):OP<T>(A,B){}
    T getResult(){
        if(this->getb()==0){
            throw "Division by zero condition!";
        }
        return this->geta()/this->getb();
    }
};

//工厂类
template <typename T>
class OPFactory{
    public:
    //OPFactory(int a1,int b1):a(a1),b(b1){}
    virtual OP<T> *OPFactoryCreate(T a,T b) = 0;
    // {
    //     OP<T> *op;
    //     switch (operation){
    //         //指向堆区的指针可以在函数内返回
    //         case '+':op = new OPAdd<int>(4,3);break;
    //         case '/':op = new OPDiv<int>(4,2);break;
    //     }
    //     return op;
    // }
};

//具体工厂类，这样子增加一个运算就不需要像简单工厂一样修改抽象工厂类了
template <typename T>
class AddFactory:public OPFactory<T>{
    public:
    OP<T> *OPFactoryCreate(T a,T b){
        return new OPAdd<T>(a,b);
    }
};

template <typename T>
class DivFactory:public OPFactory<T>{
    public:
    OP<T> *OPFactoryCreate(T a,T b){
        return new OPDiv<T>(a,b);
    }
};





int main(){
    AddFactory<int> addfac;
    DivFactory<int> divfac;
    OP<int> *oper1 = addfac.OPFactoryCreate(4,3);
    OP<int> *oper2 = divfac.OPFactoryCreate(4,1);
    cout << oper1->getResult()<<endl;
    cout << oper2->getResult()<<endl;
    system("pause");
}