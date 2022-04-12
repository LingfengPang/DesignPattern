#include <iostream>
#include <memory>
#include <vector>
using namespace std;
template<class T>
class AbsIterator
{
private:
    /* data */
public:
    virtual T first() = 0;
    virtual T next() = 0;
    virtual T current() = 0;
    //virtual T first();
};
//假设访问的是vector吧
// template<class T>
// class  AbsVec{
//     public:
//     virtual AbsIterator<T>* CreateIterator() = 0;
// };

// template<class T>
// class Vec:public AbsVec{
//     private:
//         vector<int>
// }
//正向迭代器
template<class T>
class Iterator:public AbsIterator<T>
{
private:
    /* data */
    shared_ptr<vector<T>> m_vec;
    int cur;
public:
    Iterator(vector<T> v):m_vec(make_shared<vector<T>>(v)),cur(0){}
    virtual T first(){return m_vec->at(0);}
    virtual T next(){
        if(cur < m_vec->size())
            return m_vec->at(++cur);
        else
            return m_vec->at(m_vec->size()-1);
    }
    virtual T current(){
        return m_vec->at(cur);
    }
};


template<class T>
class RIterator:public AbsIterator<T>
{
private:
    /* data */
    shared_ptr<vector<T>> m_vec;
    int cur;
public:
    RIterator(vector<T> v):m_vec(make_shared<vector<T>>(v)),cur(v.size()-1){}
    virtual T first(){return m_vec->at(m_vec->size()-1);}
    virtual T next(){
        if(cur>=0)
            return m_vec->at(--cur);
        else
            return m_vec->at(0);
    }
    virtual T current(){
        return m_vec->at(cur);
    }
};

int main(){
    vector<int> a(5);
    for(int i = 0;i<5;i++){
        a[i] = i+1;
    }
    AbsIterator<int> *it = new Iterator<int>(a);
    cout << it->current()<<" ";
    for(int i = 1;i<5;i++){
         cout << it->next()<<" ";
    }
    cout << endl;
    AbsIterator<int> *itr = new RIterator<int>(a);
    cout << itr->current()<<" ";
    for(int i = 1;i<5;i++){
         cout << itr->next()<<" ";
    }

    system("pause");
    return 0;
}