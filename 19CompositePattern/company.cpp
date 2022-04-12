#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class AbsCompany{
    protected:
        string name;
    public:
        AbsCompany(string m_name = "null"):name(m_name){}
        virtual void add(AbsCompany*){}
        virtual void remove(AbsCompany*){}
        virtual void duty(){}
};

class Company:public AbsCompany{
    private:
        shared_ptr<vector<AbsCompany*>> child;
    public:
        Company(string m_name = "null"):AbsCompany(m_name),child(make_shared<vector<AbsCompany*>>()){
            
        }
        void add(AbsCompany* c){
            child->push_back(c);
        } 
        void remove(AbsCompany *c){
            for(auto it = child->begin();it!=child->end();it++){
                if(*it == c){
                    child->erase(it);
                }
            }
        }
        void duty(){
            cout << "This is " << name <<endl;
            for(auto it = child->begin();it!=child->end();it++){
                (*it)->duty();
            }
        }
};
//叶子节点
class HR:public AbsCompany{
    public:
        HR(string m_name = "null"):AbsCompany(m_name){
            
        }
        void add(AbsCompany* c){
            cout <<"I can't add"<<endl;
        } 
        void remove(AbsCompany *c){
            cout <<"I can't remove"<<endl;
        }
        void duty(){
            cout << "This is " << name << " Mt duty is recruitment"<<endl;
        }
};
//叶子节点
class Finance:public AbsCompany{
    public:
        Finance(string m_name = "null"):AbsCompany(m_name){
            
        }
        void add(AbsCompany* c){
            cout <<"I can't add"<<endl;
        } 
        void remove(AbsCompany *c){
            cout <<"I can't remove"<<endl;
        }
        void duty(){
            cout << "This is " << name << " Mt duty is paying money"<<endl;
        }
};

int main(){
    Company *cp = new Company("202");
    cp->add(new HR("yhw"));
    cp->add(new Finance("zpc"));
    cp->duty();
    system("pause");
    return 0;
}
