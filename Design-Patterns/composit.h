#ifndef COMPOSIT_H
#define COMPOSIT_H

#include <print>
#include <vector>

// Abstract base class for shapes
class Shape {
 public:
  virtual void draw() = 0;
  virtual ~Shape() = default;
};

// Concrete classes for rectangle and triangle
class Rectangle : public Shape {
 public:
  void draw() override {
    std::println("Drawing Rectangle");
  }
};

class Triangle : public Shape {
 public:
  void draw() override {
    std::println("Drawing Triangle");
  }
};

// Composite class for a group of shapes
class CompositeShape : public Shape {
 public:
  void addShape(Shape* shape) {
    shapes.push_back(shape);
  }

  void draw() override {
    for (Shape* shape : shapes) {
      shape->draw();
    }
  }

 private:
  std::vector<Shape*> shapes;
};

#endif  // COMPOSIT_H
