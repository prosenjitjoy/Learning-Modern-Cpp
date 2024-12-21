#include "Product.h"

#include <print>

ProductClass::ProductClass(const ProductClass &rhs) {
    m_name = rhs.name();
    m_price = rhs.price();
    m_rating = rhs.rating();
    m_available = rhs.available();
    std::println("copy-constructor invoked!");
}

ProductClass::ProductClass(ProductClass &&rhs) {
    m_name = std::move(rhs.m_name);
    m_price = std::move(rhs.m_price);
    m_rating = std::move(rhs.m_rating);
    m_available = std::move(rhs.m_available);
    std::println("move-constructor invoked!");
}

void ProductClass::set_name(const std::string &name) {
    m_name = name;
}

std::string ProductClass::name() const {
    return m_name;
}

void ProductClass::set_price(const double &price) {
    m_price = price;
}

double ProductClass::price() const {
    return m_price;
}

void ProductClass::set_rating(const int &rating) {
    m_rating = rating;
}

int ProductClass::rating() const {
    return m_rating;
}

void ProductClass::set_availability(const bool &available) {
    m_available = available;
}

bool ProductClass::available() const {
    return m_available;
}
