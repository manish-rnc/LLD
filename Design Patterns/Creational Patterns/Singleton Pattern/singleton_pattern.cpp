#include<iostream>
#include<string>

class SingleTon {
    static SingleTon *instance;
    SingleTon() {
        std::cout<<"object created for once"<<std::endl;
    }
public:
    static SingleTon* getInstance() {
        if(instance == nullptr) {
            instance = new SingleTon();     // critical section
        } 
        return instance;
    }
    ~SingleTon() {
        delete instance;
    }
    void printAddress() {
        std::cout << "Instance Address : " << this << std::endl;
    }
};
SingleTon* SingleTon::instance = nullptr;

int main()
{
    SingleTon *obj1 = SingleTon::getInstance();
    obj1->printAddress();
    SingleTon *obj2 = SingleTon::getInstance();
    obj2->printAddress();

    return 0;
}
