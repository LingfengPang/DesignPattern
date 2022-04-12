#include <iostream>
#include <string>
using namespace std;
class Girl{
private:
    string name;
public:
    Girl(string name = "null"):name(name){};
    string getName(){return name;}
    void setName(string name = "null"){this->name = name;}
};
//Subject类，定义RealSubject和Proxy的共用接口，这样就可以在任何使用RealSubject的地方都可以使用Proxy。
class Give{
    
    public:
        virtual void give(const string) = 0;
};
//RealSubject：真实处理业务的角色。
class Boy:public Give{
    private:
        Girl g;
    public:
        Boy(string toName = "null"){g.setName(toName);}
        void give(const string what){
            cout << "give " +what+ " to "+g.getName()<<endl;
        }

};

//Proxy：保存一个引用使得代理可以访问实体。
//提供一个与Subject的接口相同的接口，这样代理就可以用来代替实体。
class Proxy:public Give{
    private:
        Boy b;
    public:
        Proxy(string toName = "null"){b = Boy(toName);}
        void give(const string what){
            b.give(what);
        }

};

int main(){
    Girl *g = new Girl();
    Proxy *p = new Proxy(g->getName());
    p->give("flower");
    system("pause");
}
