#ifndef ADAPTER_H
#define ADAPTER_H

#include <print>

// Target interface
class TargetInterface {
 public:
  virtual int add(int a, int b) = 0;
};

// Adaptee class with incompatible interface
class Adaptee {
 public:
  int sum(int a, int b) {
    return a + b;
  }
};

// Class adapter
class ClassAdapter : public TargetInterface, private Adaptee {
 public:
  int add(int a, int b) override {
    return sum(a, b);
  }
};

// Object adapter
class ObjectAdapter : public TargetInterface {
 public:
  ObjectAdapter(Adaptee& adaptee) : adaptee{adaptee} {
  }

  int add(int a, int b) override {
    return adaptee.sum(a, b);
  }

 private:
  Adaptee& adaptee;
};

#endif  // ADAPTER_H
