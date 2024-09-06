#include<iostream>
#include<string>

class Shape {
public: 
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

class Circle : public Shape {
public: 
    void draw() const override {
        std::cout << "Circle is drawn" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Square is drawn" << std::endl;
    }
};

class ShapeFactory {
public: 
    static Shape* createShape(std::string inputShape) {
        if(inputShape == "circle") {
            return new Circle();
        }
        else if(inputShape == "square"){
            return new Square();
        }
        else {
            return nullptr;
        }
    }
};

int main()
{
    Shape *circle = ShapeFactory::createShape("circle");
    circle->draw();
    delete circle;

    Shape *square = ShapeFactory::createShape("square");
    square->draw();
    delete square;

    return 0;
}
