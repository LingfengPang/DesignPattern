#include <iostream>
#include <string>
using namespace std;

class ShopStrategy
{
protected:
    double price;//单价
    int num ;//数量
public:
    ShopStrategy():price(0),num(0){}
    ShopStrategy(double p,int n):price(p),num(n){}
    virtual double cash() const = 0;
    
};
//正常
class Normal :public ShopStrategy{
    public:
    Normal(double p,int n):ShopStrategy(p,n){}
    double cash() const{
        return this->price * this->num;
    }
};
//打折
class Rebate :public ShopStrategy{
    private:
        double rate;
    public:
    Rebate(double p,int n,double r):ShopStrategy(p,n),rate(r){}
    double cash() const{
        return this->price * this->num*rate;
    }
};

//返利
class Return :public ShopStrategy{
    private:
        double limit;
        double back;
    public:
    Return(double p,int n,double r,double b):ShopStrategy(p,n),limit(r),back(b){}
    double cash() const{
        double sum =  this->price * this->num;
        if(sum >= limit)
            sum -= back;
        return sum;
    }
};


enum STRATEGY {NORMAL, REBATE, RETURN}; //标签
class Shop
{
private:
	ShopStrategy *shop;
public:
	Shop(enum STRATEGY  ra) 
	{ 
		if(ra == NORMAL)
			shop = new Normal(10,100);
		else if(ra == REBATE)
			shop = new Rebate(10,100,0.8);
		else if(ra == RETURN)
			shop = new Return(10,100,300,100);
		else 
			shop = nullptr;
	}
	~Shop() { delete shop; }
	void sell() { cout<<shop->cash()<<endl; }
};

int main(){
    Shop s1(NORMAL);
    Shop s2(REBATE);
    Shop s3(RETURN);
    s1.sell();
    s2.sell();
    s3.sell();
    system("pause");
}




