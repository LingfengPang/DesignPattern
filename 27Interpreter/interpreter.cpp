#include <iostream>
#include <string>

using namespace std;

class PlayContext{
    private:
        string text;
    public:
        PlayContext(string t = " "):text(t){}
        void set(string t){text = t;}
        string get(){return text;}
};
//抽象表达式类
class Expression{
    public:
        virtual string Interpret(PlayContext *s) = 0;
};
//具体表达式类
class Expression1:public Expression{
    string Interpret(PlayContext *s){
        string str;
        for(char &c:s->get()){
            str+=('A'+(c-'0'));
        }
        return str;
    }
};

class Expression2:public Expression{
    string Interpret(PlayContext *s){
        string str;
        for(char &c:s->get()){
            str+=('a'+(c-'0'));
        }
        return str;
    }
};

int main(){
    PlayContext *context = new PlayContext("123111");
    Expression *exp1 = new Expression1();
    cout << exp1->Interpret(context) << endl;
    Expression *exp2 = new Expression2();
    cout << exp2->Interpret(context) << endl;

    if(context) delete context;
    if(exp1) delete exp1;
    if(exp2) delete exp2;

    system("pause");
    return 0;
}