#include<iostream>
#include<vector>
#include<algorithm>

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
public:
    virtual void add(Observer *observer) = 0;
    virtual void remove(Observer *observer) = 0;
    virtual void notify() = 0;
};

class ConcreteObservable: public Observable {
private:
    std::vector<Observer *> listOfObservers;
    std::string data;
public:
    void add(Observer *observer) override {
        listOfObservers.push_back(observer);
    }
    void remove(Observer *observer) override {
        listOfObservers.erase(std::remove(listOfObservers.begin(), listOfObservers.end(), observer), listOfObservers.end());
    }
    void notify() override {
        for(Observer *observer : listOfObservers) {
            observer->update();
        }
    }
    void setData(const std::string &data) {
        if(this->data != data) {
            this->data = data;
            notify();
        }
    }
};

class ConcreteObserver : public Observer {
    std::string nameOfObserver;
public:
    ConcreteObserver(const std::string &name) {
        this->nameOfObserver = name;
    }
    void update() override {
        std::cout << "Data has been updated for " << this->nameOfObserver << std::endl;
    }
};

int main()
{
    ConcreteObservable observable;
    ConcreteObserver observer1("observer1");
    ConcreteObserver observer2("observer2");
    ConcreteObserver observer3("observer3");

    observable.add(&observer1);
    observable.add(&observer2);
    observable.add(&observer3);

    observable.setData("some data added");
    observable.notify();

    return 0;
}
