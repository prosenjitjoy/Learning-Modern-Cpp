#ifndef INHERITANCE_H
#define INHERITANCE_H

class Rectangle {
  public:
    Rectangle() = default;
    Rectangle(int width, int height) {
        m_width = width;
        m_height = height;
    }
    void set_width(int width) {
        m_width = width;
    }
    void set_height(int height) {
        m_height = height;
    }
    int area() const {
        return m_width * m_height;
    }

  private:
    int m_width;
    int m_height;
};

class Square : public Rectangle {
  public:
    Square() = default;
    Square(int size) : Rectangle(size, size) {
    }
    int area() {
        m_area = Rectangle::area();
        return m_area;
    }

  private:
    int m_area;
};

#endif  // INHERITANCE_H
