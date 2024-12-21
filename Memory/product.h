#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
  public:
    Product() = default;
    Product(std::string, double, bool);
    std::string name() const;
    void set_name(std::string);
    double price() const;
    void set_price(double);
    bool available() const;
    void set_available(bool);

  private:
    std::string m_name;
    double m_price;
    bool m_available;
};

#endif  // PRODUCT_H
