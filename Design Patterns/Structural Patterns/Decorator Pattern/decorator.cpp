#include<iostream>
#include<string>

// base component
class BasePizza {
public:
    virtual ~BasePizza() = default;
    virtual std::string getDescription() = 0;
    virtual double getCost() = 0;
};

// concrete component
class PlainPizza : public BasePizza {
public: 
    std::string getDescription() override {
        return "Plain Pizza";
    }
    double getCost() override {
        return 100.00;
    }
};

// concrete component
class MargheritaPizza : public BasePizza {
public: 
    std::string getDescription() override {
        return "Margherita Pizza";
    }
    double getCost() override {
        return 200.00;
    }
};


// abstract decorator
class ToppingDecorator : public BasePizza {     // is-A, has-A relationship both
protected:
    BasePizza *basePizza;
public:
    ToppingDecorator(BasePizza *basePizza) : basePizza(basePizza) {}
    virtual ~ToppingDecorator() {
        delete basePizza;
    }
    std::string getDescription() override {
        return basePizza->getDescription();
    }
    double getCost() override {
        return basePizza->getCost();
    }
};

// concrete decorator
class ExtraCheese : public ToppingDecorator {
public:
    ExtraCheese(BasePizza *basePizza) : ToppingDecorator(basePizza) {}
    std::string getDescription() override {
        return basePizza->getDescription() + ", Cheese";
    }
    double getCost() override {
        return basePizza->getCost() + 15.00;
    }
};

// concrete decorator
class Pepperoni : public ToppingDecorator {
public:
    Pepperoni(BasePizza *basePizza) : ToppingDecorator(basePizza) {}
    std::string getDescription() override {
        return basePizza->getDescription() + ", Pepperoni";
    }
    double getCost() override {
        return basePizza->getCost() + 12.00;
    }
};

int main()
{
    PlainPizza *pizza = new PlainPizza();

    // wrapping base pizza with extra cheese
    ExtraCheese *cheesePizza = new ExtraCheese(pizza);
    // wrapping cheese pizza with pepperoni
    Pepperoni *pepperoniPizza = new Pepperoni(cheesePizza);
    // again wrapping the so obtained pizza with cheese
    ExtraCheese *moreCheesePizza = new ExtraCheese(pepperoniPizza);

    std::cout << "Pizza : " << moreCheesePizza->getDescription() << std::endl;
    std::cout << "Cost : Rs. " << moreCheesePizza->getCost() << std::endl;

    delete moreCheesePizza;

    return 0;
}
