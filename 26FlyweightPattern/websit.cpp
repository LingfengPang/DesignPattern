#include <iostream>
#include <string.h>
#include <memory>
#include <unordered_set>
using namespace std;
class User{
    private:
        string name;
    public:
        User(string n = "null"):name(n){}
        string getName(){return name;}
};
class WebSit
{  
public:
    virtual void use(User*)=0;
};
//具体网站类
class CWebsit:public WebSit{
    private:
        string name;
    public:
        CWebsit(string n = "null"):name(n){}
        void use(User* u) override{
            cout << "This websit is "<<name<<endl;
            cout << "The user is " <<u->getName()<<endl;
            cout <<"------------------------------------------"<<endl;
        }
};

class WebsitFactory{
    private:
        shared_ptr<unordered_set<string>> hash;
    public:
        WebsitFactory():hash(make_shared<unordered_set<string>>()){}
        WebSit* getWebSit(string name){
            if(hash->count(name) == 0)
                hash->insert(name);
            return new CWebsit(name);
        }
        int count(){
            return hash->size();
        }
};
int main(){
    WebsitFactory *fac = new WebsitFactory();
    User *user1 = new User("zpc");
    User *user2 = new User("zbw");
    WebSit *game1 = fac->getWebSit("epic");
    game1->use(user1);
    WebSit *game2 = fac->getWebSit("steam");
    game2->use(user2);

    WebSit *blog1 = fac->getWebSit("github");
    blog1->use(user1);
    WebSit *blog2 = fac->getWebSit("github");
    blog2->use(user2);

    cout << fac->count()<<endl;

    system("pause");
    delete user1;
    delete user2;
    delete game1;
    delete game2;
    delete blog1;
    delete blog2;
    delete fac;
    return 0;



}

