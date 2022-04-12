#include <iostream>
using namespace std;
//游戏角色状态-备忘录类，存储组织者状态，防止其他类访问
class RoleState{
    private:
        int vit;//生命
        int atk;
        int def;
    public:
        RoleState(int v = 100,int a = 100,int d = 100):vit(v),atk(a),def(d){}
        int getVit(){
            return vit;
        }
        void setVit(int v){vit = v;}
        int getAtk(){
            return atk;
        }
         void setAtk(int v){atk = v;}
        int getDef(){
            return def;
        }
        void setDef(int v){def = v;}
        RoleState& operator=(RoleState& rhs){
            vit = rhs.vit;
            atk = rhs.atk;
            def = rhs.def;
            return *this;
        }

        void show(){
            cout << "vit: "<<vit<<endl;
            cout << "atk: "<<atk<<endl;
            cout << "def: "<<def<<endl;
        }

};
//游戏角色组织者类，负责创建备忘录，建立记录恢复备忘录
class Role{
    private:
    int vit;//生命
    int atk;
    int def;
    //RoleState *m_state;
    public:
        Role(int v = 100,int a = 100,int d = 100):vit(v),atk(a),def(d){};
        Role(RoleState *roler):vit(roler->getVit()),atk(roler->getAtk()),def(roler->getDef()){};
        RoleState *save(){
            RoleState *m_state = new RoleState(vit,atk,def);
            return m_state;
        }
        void RecoveryState(RoleState *s){
            this->vit = s->getVit();
            this->atk = s->getAtk();
            this->def = s->getDef();
        }
                void show(){
            cout << "vit: "<<vit<<endl;
            cout << "atk: "<<atk<<endl;
            cout << "def: "<<def<<endl;
        }
        void fight(){
            vit = 1;
            def = 1;
            atk = 1;
        }
};

//负责保存备忘录
class RoleStateCaretaker{
    private:
        RoleState *m_state;
    public:
        RoleStateCaretaker():m_state(new RoleState()){}
        RoleState* get(){return m_state;}
        void set(RoleState *s){
            m_state->setAtk(s->getAtk());
            m_state->setDef(s->getDef());
            m_state->setVit(s->getVit());
        }

};

int main(){
    //备忘录设计模式
    cout << "kkg will fight with boss"<<endl;
    Role *sillykkg= new Role();
    sillykkg->show();
    cout << "kkg save the game"<<endl;
    RoleStateCaretaker *stateAdmin = new RoleStateCaretaker();
    stateAdmin->set(sillykkg->save());

    cout << "after fighting with boss, kkg is injured"<<endl;
    sillykkg->fight();
    sillykkg->show();

     cout << "kkg load the game"<<endl;
    sillykkg->RecoveryState(stateAdmin->get());
    sillykkg->show();

    system("pause");
    return 0;
    

}
