#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

#include <print>

class Musician {
  public:
    virtual void play() = 0;
};

class Guitarist : public Musician {
  public:
    void play() override {
        std::println("Play a guitar");
    }
};

class Pianist : public Musician {
  public:
    void play() override {
        std::println("Play a piano");
    }
};

#endif  // POLYMORPHISM_H
