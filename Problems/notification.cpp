// Design a notification system where an item is out of stock but as soon as the stock comes, it should notify all the users looking for it 

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
public: 
    virtual void add(Observer *) = 0;
    virtual void remove(Observer *) = 0;
    virtual void notifyObservers() = 0;
    virtual void setStockCount(int count) = 0;
    virtual int getStockCount() = 0;
};

class DrinkObservable : public Observable {
    std::vector<Observer *> observers;
    int stocks = 0;
public: 
    void add(Observer *observer) override {
        observers.push_back(observer);
    }
    void remove(Observer *observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyObservers() {
        for(Observer *observer : observers) {
            observer->update();
        }
    }
    void setStockCount(int newStockCount) override {
        if(this->getStockCount() == 0 and newStockCount > 0) {
            notifyObservers();
        }
        this->stocks = newStockCount;
    }
    int getStockCount() override {
        return this->stocks;
    }
};

class MobileObserver : public Observer {
    std::string name;
    std::string email;
public: 
    MobileObserver(const std::string &name, const std::string &email) {
        this->name = name;
        this->email = email;
    }
    void update() override {
        std::cout << "Mail sent to : " << this->email << std::endl;
    }
};

class EmailObserver : public Observer {
    std::string name;
    std::string email;
public: 
    EmailObserver(const std::string &name, const std::string &email) {
        this->name = name;
        this->email = email;
    }
    void update() override {
        std::cout << "Mail sent to : " << this->email << std::endl;
    }
};

int main() 
{
    DrinkObservable drink;

    MobileObserver observer1("Mani", "mani@gmail.com");
    EmailObserver observer2("Somesh", "somesh@gmail.com");

    drink.add(&observer1);
    drink.add(&observer2);

    drink.setStockCount(100);

    return 0;
}
