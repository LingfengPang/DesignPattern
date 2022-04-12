#include <iostream>
#include <string>

using namespace std;
//抽象人类
class Person
{
protected:
    /* data */
public:
    Person(){}
    ~Person(){}
    virtual void showDecorate()=0;
};

//具体人类
class Zhejiang:public Person{
    private:
        string name;
    public:
        Zhejiang(string n = "null"):name(n){}
       ~Zhejiang(){}
       void showDecorate(){
           cout << "Z " <<name << "Decorate :"<<endl;
       }
};

class Jiangsu:public Person{
    private:
        string name;
    public:
        Jiangsu(string n = "null"):name(n){}
       ~Jiangsu(){}
       void showDecorate(){
           cout <<"J "<< name << "Decorate :";
       }
};

//抽象服饰类
class Decorator : public Person
{
private:
	Person *m_person;  //要装饰的手机
public:
	Decorator(Person *person): m_person(person) {}
	virtual void showDecorate() { m_person->showDecorate(); }
};

class TShirt:public Decorator{
    public:
    TShirt(Person *m_person):Decorator(m_person){}
    void showDecorate(){
        Decorator::showDecorate();
        cout << " A Tshirt"<<endl;
    }
};
//懒得改名了，直接cv了
class TShirt2:public Decorator{
    public:
    TShirt2(Person *m_person):Decorator(m_person){}
    void showDecorate(){
        Decorator::showDecorate();
        cout << " A Tshirt2"<<endl;
    }
};

int main(){
    Person *zj = new Zhejiang("zpc");
    Person *p1 = new  TShirt(zj);
    Person *p2 = new  TShirt2(zj);
    p1->showDecorate();
    cout <<"-------------------------"<<endl;
    p2->showDecorate();
    delete zj;
    delete p1;
    delete p2;
    system("pause");
    return 0;
}




