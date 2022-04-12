#include "animal.h"
using namespace std;

int main(){
    Animal *a[2];//多态
    a[0] = new Cat("kkg1");
    a[1] = new Dog("kkg2");
    for(int i = 0;i<2;i++)
        a[i]->shout();
    system("pause");
    
}