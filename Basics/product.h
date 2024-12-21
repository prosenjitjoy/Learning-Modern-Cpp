#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
  private:
    std::string m_name;
    bool m_avaiable;
    double m_price;
    int m_rating;

  public:
    Product() = default;                 // default constructor
    Product(const Product&);             // copy constructor
    Product(Product&&);                  // move constructor
    Product& operator=(const Product&);  // copy assignment operator
    Product& operator=(Product&&);       // move assignment operator

    void setName(const std::string&);
    std::string name() const;
    void setAvaiable(bool);
    bool available() const;
    void setPrice(double);
    double price() const;
    void setRating(int);
    int rating() const;
};

#endif  // PRODUCT_H
