#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class ProductClass {
  public:
    ProductClass() = default;           // default constructor
    ProductClass(const ProductClass&);  // copy constructor
    ProductClass(ProductClass&&);       // move
    // constructor
    ProductClass& operator=(const ProductClass&) = default;  // copy assignment
    ProductClass& operator=(ProductClass&&) = default;       // move assignment

    void set_name(const std::string&);
    std::string name() const;
    void set_price(const double&);
    double price() const;
    void set_rating(const int&);
    int rating() const;
    void set_availability(const bool&);
    bool available() const;

  private:
    std::string m_name;
    double m_price;
    int m_rating;
    bool m_available;
};

#endif  // PRODUCT_H
