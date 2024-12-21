#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

// bad design choice
class Product {
 private:
  std::string m_name;
  std::string m_description;
  double m_price;
  int m_inventoryLevel;

 public:
  Product(std::string name, std::string description, double price,
          int inventoryLevel) {
    m_name = name;
    m_description = description;
    m_price = price;
    m_inventoryLevel = inventoryLevel;
  }

  std::string name() const {
    return m_name;
  }
  void setName(std::string name) {
    m_name = name;
  }

  std::string description() const {
    return m_description;
  }
  void setDescription(std::string description) {
    m_description = description;
  }

  double price() const {
    return m_price;
  }
  void setPrice(double price) {
    m_price = price;
  }

  int inventoryLevel() const {
    return m_inventoryLevel;
  }
  void setInventoryLevel(int inventoryLevel) {
    m_inventoryLevel = inventoryLevel;
  }
};

class Electronic : public Product {
 private:
  std::string m_brand;
  std::string m_model;

 public:
  Electronic(std::string name, std::string description, double price,
             int inventoryLevel, std::string brand, std::string model)
      : Product(name, description, price, inventoryLevel) {
    m_brand = brand;
    m_model = model;
  }

  std::string brand() const {
    return m_brand;
  }
  void setBrand(std::string brand) {
    m_brand = brand;
  }

  std::string model() const {
    return m_model;
  }
  void setModel(std::string model) {
    m_model = model;
  }
};

class TV : public Electronic {
 private:
  std::string m_screenType;
  int m_screenSize;
  std::string m_resolution;

 public:
  TV(std::string name, std::string description, double price,
     int inventoryLevel, std::string brand, std::string model,
     std::string screenType, int screenSize, std::string resolution)
      : Electronic(name, description, price, inventoryLevel, brand, model) {
    m_screenType = screenType;
    m_screenSize = screenSize;
    m_resolution = resolution;
  }

  std::string screenType() const {
    return m_screenType;
  }
  void setScreenType(std::string screenType) {
    m_screenType = screenType;
  }

  int screenSize() const {
    return m_screenSize;
  }
  void setScreenSize(int screenSize) {
    m_screenSize = screenSize;
  }

  std::string resolution() const {
    return m_resolution;
  }
  void setResolution(std::string resolution) {
    m_resolution = resolution;
  }
};

#endif  // PRODUCT_H
