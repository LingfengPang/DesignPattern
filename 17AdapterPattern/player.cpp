#include <iostream>
#include <string>
using namespace std;


class player
{
protected:
    /* data */
    string name;
public:
    player(string n = "null"):name(n){}
    ~player(){}
    virtual void attack()=0;
    virtual void defend()=0;
};


class native:public player
{
private:
public:
    native(string n = "null"):player(n){}
    void attack(){
        cout << this->name << " attacked"<<endl;
    }
    void defend(){
        cout << this->name << " defend"<<endl;
    }
};


class foreign
{
private:
    string name;
public:
    foreign(string n = "null"):name(n){}
    void attack(){
        cout << this->name << " jingong"<<endl;
    }
    void defend(){
        cout << this->name << " fangyu"<<endl;
    }
    string getName(){return name;}
};

class Translator:public player{
    private:
        foreign *f;
    public:
        Translator(string name):f(new foreign(name)),player("null"){}
        void attack(){
            f->attack();
        }
        void defend(){
            f->defend();
        }
        ~Translator(){
            if(f){
                delete f;
                f = nullptr;
            }
        }
};

int main(){
    player *player1 = new native("silly kkg");
    player *player2 = new Translator("yuchunde kkg");
    player1->attack();
    player1->defend();
    player2->attack();
    player2->defend();
    delete player1;
    delete player2;
    system("pause");
    return 0;
}

