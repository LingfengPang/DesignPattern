#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Resume
{
private:
    /* data */
    string name;
    int age;
    string experience;
    //Resume *mr;
public:
    Resume(string n = "null",int a = 0,string e = "null"):name(n),age(a),experience(e){}
    ~Resume(){
    }
    void setName(string n){name = n;}
    void setAge(int a){age = a;}
    void setExp(string exp){experience = exp;}
    Resume* ResumeClone(){//这是浅拷贝吗
        return this;
    }
    Resume* ResumeCloneDeep(){
        Resume *newResume = new Resume(name,age,experience);
        return newResume; 
    }
    void show(){
        cout << "---------------------"<<endl;
        cout << "name: "<<name<<endl;
        cout << "age:  "<<age<<endl;
        cout << "exp:  "<<experience<<endl;
        cout << "---------------------"<<endl;
    }

};

int main(){
    //浅复制测试
    shared_ptr<Resume> r1 (new Resume("kkg",24,"no"));
    shared_ptr<Resume> r2 (r1->ResumeClone());
    r1->show();
    r2->setExp("hdu");
    r1->show();
    r1.reset();
    //r2.reset();
    //深复制测试
    shared_ptr<Resume> r3(new Resume("kkg2",24,"nono"));
    shared_ptr<Resume> r4(r3->ResumeCloneDeep());
    r3->show();
    r4->setExp("hdu22");
    r3->show();
    r3.reset();
    r4.reset();
    system("pause");
    return 0;


}


