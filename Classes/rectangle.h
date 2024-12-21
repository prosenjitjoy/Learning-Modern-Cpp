#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
  public:
    Rectangle(int length = 0, int width = 0) {
        m_length = length;
        m_width = width;
    }

    static int length() {
        return m_length;
    }

    int width() {
        return m_width;
    }

    virtual void setLength(int length) {
        m_length = length;
    }
    virtual void setWidth(int width) {
        m_width = width;
    }

    int perimeter() {
        return 2 * (m_length + m_width);
    }

  private:
    inline static int m_length;
    int m_width;
};

#endif  // RECTANGLE_H
