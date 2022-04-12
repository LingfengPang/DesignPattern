#include <iostream>
using namespace std;

class Soft{
    public:
        virtual void run() = 0;
};
class Game :public Soft{
    public:
        virtual void run(){
            cout << "run games!!"<<endl;
        };
};
class MP3 :public Soft{
    public:
        virtual void run(){
            cout << "run mps!!"<<endl;
        };
};

class phone
{
protected:
    Soft *s;
public:
    
    phone(Soft *m_s):s(m_s){}
    ~phone(){
        if(s){
            delete s;
            s = nullptr;
        }
    }
    virtual void run() = 0;

};

class Iphone:public phone{
    public:
    Iphone(Soft *m_s):phone(m_s){}
    virtual void run(){
        cout <<"this is iphone"<<endl;
        s->run();
    };
};

class Mi:public phone{
    public:
    Mi(Soft *m_s):phone(m_s){}
    virtual void run(){
        cout <<"this is Mi"<<endl;
        s->run();
    };
};

int main(){
    // Soft *g = new Game();
    // Soft *mp3 = new MP3();
    phone *ip = new Iphone(new Game());
    phone *mi = new Mi(new MP3());
    ip->run();
    mi->run();
    system("pause");
    return 0;

}
