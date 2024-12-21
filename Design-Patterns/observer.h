#ifndef OBSERVER_H
#define OBSERVER_H

#include <print>
#include <vector>

class MouseEvent {
 public:
  MouseEvent(int x, int y) : m_x{x}, m_y{y} {
  }

  int getX() const {
    return m_x;
  }

  int getY() const {
    return m_y;
  }

 private:
  int m_x;
  int m_y;
};

class MouseMoveObserver {
 public:
  virtual void onMouseMove(const MouseEvent& event) = 0;
};

class MouseMoveSubject {
 public:
  void attach(MouseMoveObserver* observer) {
    observers.push_back(observer);
  }

  void detach(MouseMoveObserver* observer) {
    for (auto it = observers.begin(); it != observers.end(); it++) {
      if (*it == observer) {
        observers.erase(it);
        break;
      }
    }
  }

  void notify(const MouseEvent& event) {
    for (auto observer : observers) {
      observer->onMouseMove(event);
    }
  }

 private:
  std::vector<MouseMoveObserver*> observers;
};

class MouseMoveLogger : public MouseMoveObserver {
 public:
  void onMouseMove(const MouseEvent& event) override {
    std::println("Mouse moved to {}, {}", event.getX(), event.getY());
  }
};

class MouseMovePrinter : public MouseMoveObserver {
 public:
  void onMouseMove(const MouseEvent& event) override {
    std::println("Mouse move event received");
  }
};

#endif  // OBSERVER_H
