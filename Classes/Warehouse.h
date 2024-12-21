#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <stdexcept>

#include "Product.h"

class WarehouseClass {
  public:
    WarehouseClass() : m_size{0}, m_capacity{1000}, m_products{nullptr} {
        m_products = new ProductClass[m_capacity];
    }

    void add_product(const ProductClass& p) {
        if (m_size == m_capacity) {
            // resize
        }
        m_products[m_size++] = p;
    }

    void set_size(int size) {
        if (size < 1) {
            throw std::invalid_argument("Invalid size");
        }

        m_size = size;
    }

  private:
    int m_size;
    int m_capacity;
    ProductClass* m_products;
};

#endif  // WAREHOUSE_H
