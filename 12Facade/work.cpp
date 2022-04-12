#include <iostream>
using namespace std;
//4个subwork类
class work1
{
public:
    void work(){cout<<"Doing Sub-Work1..."<<endl;}
};

class work2
{
public:
    void work(){cout<<"Doing Sub-Work2..."<<endl;}
};

class work3
{
public:
    void work(){cout<<"Doing Sub-Work3..."<<endl;}
};

class work4
{
public:
    void work(){cout<<"Doing Sub-Work4..."<<endl;}
};

//facade类
class Facade
{
private:
    /* data */
    work1 *woker1;
    work2 *woker2;
    work3 *woker3;
    work4 *woker4;
public:
    Facade():woker1(new work1()),woker2(new work2()),woker4(new work4()),woker3(new work3()){};
    ~Facade(){
        if(woker1) delete woker1;
        if(woker2) delete woker2;
        if(woker3) delete woker3;
        if(woker4) delete woker4;

    }
    void do1(){
        woker1->work();
        woker3->work();
        woker4->work();
    }

    void do2(){
        woker2->work();
        woker4->work();
        woker3->work();
    }
};

//clien程序
int main(){
    Facade *f = new Facade();
    f->do1();
    cout << "************************"<<endl;
    f->do2();
    system("pause");
    return 0;
}


