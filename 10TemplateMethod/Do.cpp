#include <iostream>

using namespace std;

class AbstractDo
{
private:
    /* data */
public:
    virtual void DoA() = 0;
    virtual void DoB() = 0;
    virtual void DoC() = 0;
    void Do(){
        DoA();
        DoB();
        DoC();
    }
};

class Go:public AbstractDo{
public:
    void DoA(){
        cout << "get up"<<endl;
    }
    void DoB(){cout << "eat food"<<endl;}
    void DoC(){cout << "go to work"<<endl;}
};

class Leave:public AbstractDo{
public:
    void DoA(){
        cout << "go home"<<endl;
    }
    void DoB(){cout << "watch TV"<<endl;}
    void DoC(){cout << "sleep"<<endl;}
};

int main(){
    AbstractDo *doer1 = new Go();
    AbstractDo *doer2 = new Leave();
    doer1->Do();
    cout << "************************"<<endl;
    doer2->Do();
    system("pause");
    return 0;

}


