#include <iostream>
#include <string>
#include <vector>

using namespace std;
//抽象观察者
class Observer
{
private:
    /* data */
    string name;

public:
    Observer(string m_name = "null"):name(m_name){}
    inline string getName(){return name;}
     virtual void action() = 0;
    ~Observer(){}
};

class NBAer:public Observer{
    public:
        NBAer(string m_name = "null"):Observer(m_name){}
        void action(){
            cout << this->getName()<<" close NBA,work!!"<<endl;
        }
};

class Gamer:public Observer{
    public:
        Gamer(string m_name = "null"):Observer(m_name){}
        void action(){
            cout  << this->getName()<< " close game,work!!"<<endl;
        }
};

class Subject{
    private:
        vector<Observer*> mate;
        string name;
    public:
        Subject(string m_name = "null"):name(m_name){}
        void addMate(Observer* ob){
            mate.push_back(ob);
        }
        void removeMate(Observer* ob){
            for(auto it = mate.begin();it!=mate.end();it++){
                if((*it)->getName() == ob->getName()){
                    mate.erase(it);
                    break;
                }
            }
        }
        virtual void see()=0;
        void notify(){
            this->see();
            for(auto m:mate)
                m->action();
        }
        //virtual void see()=0;
};


class Watch:public Subject{
    public:
        Watch(string m_name = "null"):Subject(m_name){}
        void see(){
            cout <<"Boss is coming"<<endl;
        }
};

class Boss:public Subject{
    public:
        Boss(string m_name = "null"):Subject(m_name){}
        void see(){
            cout <<"I'm Boss I catch you"<<endl;
        }
};

int main(){
    Observer *ob1 = new NBAer("silly kkg1");
    Observer *ob2 = new Gamer("silly kkg2");
    Observer *ob3 = new NBAer("silly kkg3");
    Observer *ob4 = new Gamer("silly kkg4");

    Subject *sub1 = new Watch("JJG's father");
    Subject *sub2 = new Boss("PM");

    sub1->addMate(ob1);
    sub1->addMate(ob2);

    sub2->addMate(ob3);
    sub2->addMate(ob4);

    sub1->notify();
    cout << "----------------------------"<<endl;
    sub2->notify();

    delete ob1;
    delete ob2;
    delete ob3;
    delete ob4;

    delete sub1;
    delete sub2;
    system("pause");
    return 0;

}