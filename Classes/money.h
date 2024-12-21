#ifndef MONEY_H
#define MONEY_H

#include <compare>

class Money {
  public:
    Money() {};
    explicit Money(double value) : m_value{value} {};
    friend std::strong_ordering operator<=>(const Money&,
                                            const Money&) = default;

  private:
    double m_value;
};

#endif  // MONEY_H
