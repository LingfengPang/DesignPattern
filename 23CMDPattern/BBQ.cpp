#include <iostream>
#include <vector>
#include <memory>
using namespace std;
class BBQEater{
    public:
    void Beaf(){cout << "A beaf"<<endl;}
    void Fish(){cout << "A Fish"<<endl;}
};
class BBQCmd{
    protected:
        BBQEater *eater;
    public:
        BBQCmd(BBQEater *e){
            eater = e;
        }
        virtual void ExcuteCmd() = 0;
    
};
class BeafCmd:public BBQCmd{
    public:
        BeafCmd(BBQEater *e):BBQCmd(e){}
        void ExcuteCmd(){
            eater->Beaf();
        }
};

class FishCmd:public BBQCmd{
    public:
        FishCmd(BBQEater *e):BBQCmd(e){}
        void ExcuteCmd(){
            eater->Fish();
        }
};
class Waiter{
    private:
        shared_ptr<vector<BBQCmd*>> orders;
    public:
        Waiter():orders(make_shared<vector<BBQCmd*>>()){}
        void add(BBQCmd* e){
            orders->push_back(e);
        }
        void Cook(){
            for(auto it = orders->begin();it!=orders->end();it++){
                (*it)->ExcuteCmd();
            }
        }
};

int main(){
    BBQEater *eater = new BBQEater();
    BBQCmd *beaf = new BeafCmd(eater);
    BBQCmd *fish = new FishCmd(eater);
    Waiter *kkg = new Waiter();
    kkg->add(beaf);
    kkg->add(fish);
    kkg->Cook();

    system("pause");
    return 0;
}