#ifndef FACTORY_H
#define FACTORY_H

// Abstract base class
class AbstractFactorial {
 public:
  virtual int calculate(int n) = 0;
  virtual ~AbstractFactorial() = default;
};

// Concrete products
class RecursiveFactorial : public AbstractFactorial {
  int calculate(int n) override {
    if (n <= 1) {
      return 1;
    }
    return n * calculate(n - 1);
  }
};

class IterativeFactorial : public AbstractFactorial {
 public:
  int calculate(int n) override {
    int result = 1;
    for (int i = 2; i <= n; i++) {
      result *= i;
    }
    return result;
  }
};

// Factory class
class FactorialFactory {
 public:
  static AbstractFactorial* createFactorial(char type) {
    switch (type) {
      case 'R':
        return new RecursiveFactorial();
      case 'I':
        return new IterativeFactorial();
      default:
        return nullptr;
    }
  }
};

#endif  // FACTORY_H
