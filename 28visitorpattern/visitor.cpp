/*
转载自https://blog.csdn.net/kenjianqi1647/article/details/119632572
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
class ConcreteElementA;//学到了，子类可以这么声明
class ConcreteElementB;
 
class Visitor
 
{
 
public:
 
     virtual void VisitConcreteElementA(ConcreteElementA *pElementA) = 0;
     virtual void VisitConcreteElementB(ConcreteElementB *pElementB) = 0;
 
};
 
 
/*具体访问者 用于定义对不同类型元素对象的操作*/
class ConcreteVisitor1 : public Visitor
 
{
public:
     void VisitConcreteElementA(ConcreteElementA *pElementA){
          cout <<"A1:" <<typeid(pElementA).name()<<endl;
        // 现在根据传进来的pElementA，可以对ConcreteElementA中的element进行操作
    }
 
     void VisitConcreteElementB(ConcreteElementB *pElementB){
          cout <<"B1:" <<typeid(pElementB).name()<<endl;
         // 现在根据传进来的pElementB，可以对ConcreteElementB中的element进行操作
    }
 
};
 
 
/*具体访问者2*/
class ConcreteVisitor2 : public Visitor
{
 
public:
     void VisitConcreteElementA(ConcreteElementA *pElementA){
           cout <<"A2:" <<typeid(pElementA).name()<<endl;
    }
     void VisitConcreteElementB(ConcreteElementB *pElementB){
          cout <<"B2:" <<typeid(pElementB).name()<<endl;
    }
};
 
 
/*抽象元素类 声明accept()方法，用于接受访问者的访问*/
class Element
 
{
public:
     virtual void Accept(Visitor *pVisitor) = 0;//accept用于接受访问者的访问
};
 
/*具体元素类 通过调用Visitor类的visit()方法实现对元素的访问*/
class ConcreteElementA : public Element
{
public:
     void Accept(Visitor *pVisitor)//通过调用visitor对象的 visit()方法实现对元素对象的访问
    {
        pVisitor->VisitConcreteElementA(this);
    }
};
 
/*具体元素类 */
class ConcreteElementB : public Element
{
public:
     void Accept(Visitor *pVisitor)
    {
     pVisitor->VisitConcreteElementB(this);
    }
};
 
// ObjectStructure类(对象结构类)，能枚举它的元素，可以提供一个高层的接口以允许访问者访问它的元素
class ObjectStructure
{
private:
     vector<Element *> elements;
public:
     void Attach(Element *pElement){
         elements.push_back(pElement);
    }
 
     void Detach(Element *pElement)   
    {
 
         vector<Element *>::iterator it = find(elements.begin(), elements.end(), pElement);
         if (it != elements.end())
         {
              elements.erase(it);
         }
    }
 
     void Accept(Visitor *pVisitor){
     // 为每一个element设置visitor，进行对应的操作
         for (vector<Element *>::const_iterator it = elements.begin(); it != elements.end(); ++it)
         {
              (*it)->Accept(pVisitor);
         }
     }
};
 
int main()
{
     //实例化对象结构，用于存放元素对象，提供遍历其内部元素的方法
     ObjectStructure *pObject = new ObjectStructure;
      //实例化具体元素 并将创建好的元素放入对象结构中
     ConcreteElementA *pElementA = new ConcreteElementA;
     ConcreteElementB *pElementB = new ConcreteElementB;
     pObject->Attach(pElementA);
     pObject->Attach(pElementB);
     //实例化访问者                                                                                                                                                                                                            
     ConcreteVisitor1 *pVisitor1 = new ConcreteVisitor1;
     ConcreteVisitor2 *pVisitor2 = new ConcreteVisitor2;
     //调用accept方法 来接受访问者对象的访问
     pObject->Accept(pVisitor1);
     pObject->Accept(pVisitor2);
 
     if (pVisitor2) delete pVisitor2;
     if (pVisitor1) delete pVisitor1;
     if (pElementB) delete pElementB;
     if (pElementA) delete pElementA;
     if (pObject) delete pObject;
     system("pause");
     return 0;
}
 