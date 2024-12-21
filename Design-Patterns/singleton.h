#include <print>

class Printer {
 public:
  static Printer* getInstance() {
    if (instance == nullptr) {
      instance = new Printer();
    }
    return instance;
  }
  void print(const std::string& message) {
    std::println("{}", message);
  }

 private:
  // Private constructor to prevent external instantiation
  Printer() {
  }

  // Delete copy constructor
  Printer(const Printer&) = delete;

  // Delete copy assignment operator
  Printer& operator=(const Printer&&) = delete;

  inline static Printer* instance;
};
