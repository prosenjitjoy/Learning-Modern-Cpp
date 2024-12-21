#include "product.h"

Product::Product(std::string name, double price, bool available) {
    m_name = name;
    m_price = price;
    m_available = available;
}

std::string Product::name() const {
    return m_name;
}

void Product::set_name(std::string name) {
    m_name = name;
}

double Product::price() const {
    return m_price;
}

void Product::set_price(double price) {
    m_price = price;
}

bool Product::available() const {
    return m_available;
}

void Product::set_available(bool available) {
    m_available = available;
}
