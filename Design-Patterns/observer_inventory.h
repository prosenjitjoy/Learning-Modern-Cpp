#ifndef OBSERVER_INVENTORY_H
#define OBSERVER_INVENTORY_H

#include <algorithm>
#include <print>
#include <string>
#include <vector>

class Product;

class Observer {
 public:
  virtual void update(Product* product) = 0;

 protected:
  static std::vector<Product*> products;
};

std::vector<Product*> Observer::products;

// subject
class Product {
 private:
  std::string m_name;
  std::string m_description;
  double m_price;
  int m_inventoryLevel;
  std::vector<Observer*> observers;

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
    notify();
  }

  // observer pattern methods
  void attach(Observer* observer) {
    observers.push_back(observer);
  }

  void detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
  }

  void notify() {
    for (auto observer : observers) {
      observer->update(this);
    }
  }
};

class Cart : public Observer {
 private:
  std::vector<Product*> products;

 public:
  void addProduct(Product* product) {
    products.push_back(product);
    product->attach(this);
  }

  void update(Product* product) {
    // check if the product is in the cart and remove it if inventory level
    // reaches zeros
    for (auto it = products.begin(); it != products.end(); it++) {
      if (*it == product && product->inventoryLevel() == 0) {
        products.erase(it);
        break;
      }
    }
  }

  std::size_t size() {
    return products.size();
  }
};

class Checkout : public Observer {
 private:
  double m_totalPrice;
  std::vector<Product*> products;

 public:
  void update(Product* product) {
    // recalculate total price when inventory level changes
    m_totalPrice = 0;
    for (auto product : products) {
      m_totalPrice += product->price();
    }
  }

  void addProduct(Product* product) {
    products.push_back(product);
    product->attach(this);
    update(product);
  }

  double totalPrice() const {
    return m_totalPrice;
  }
};

#endif  // OBSERVER_INVENTORY_H
