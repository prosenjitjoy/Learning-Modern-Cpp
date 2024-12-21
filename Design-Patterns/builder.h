#ifndef BUILDER_H
#define BUILDER_H

#include <print>
#include <string>

class AProduct {
 private:
  std::string m_name;
  std::string m_description;
  double m_price;
  int m_inventoryLevel;

 public:
  AProduct(std::string name, std::string description, double price,
           int inventoryLevel)
      : m_name{name},
        m_description{description},
        m_price{price},
        m_inventoryLevel{inventoryLevel} {
  }

  std::string name() const {
    return m_name;
  }

  std::string description() const {
    return m_description;
  }

  double price() const {
    return m_price;
  }

  int inventoryLevel() const {
    return m_inventoryLevel;
  }
};

class ProductBuilder {
 private:
  std::string m_name;
  std::string m_description;
  double m_price;
  int m_inventoryLevel;

 public:
  ProductBuilder() {
  }

  ProductBuilder& setName(std::string name) {
    m_name = name;
    return *this;
  }

  ProductBuilder& setDescription(std::string description) {
    m_description = description;
    return *this;
  }

  ProductBuilder& setPrice(double price) {
    m_price = price;
    return *this;
  }

  ProductBuilder& setInventoryLevel(int inventoryLevel) {
    m_inventoryLevel = inventoryLevel;
    return *this;
  }

  AProduct build() {
    return AProduct(m_name, m_description, m_price, m_inventoryLevel);
  }
};

#endif  // BUILDER_H
