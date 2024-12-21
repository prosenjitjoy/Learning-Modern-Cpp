#ifndef COMMAND_H
#define COMMAND_H

#include <print>

// Command - abstract base class for command
class Command {
 public:
  virtual ~Command() {
  }
  virtual void execute() = 0;
};

// Receiver - concrete classes for commands
class OpenCommand : public Command {
 public:
  OpenCommand() {
  }
  void execute() override {
    std::println("Opening file...");
  }
};

class SaveCommand : public Command {
 public:
  SaveCommand() {
  }
  void execute() override {
    std::println("Saving file...");
  }
};

// Invoker - creates and runs commands
class Invoker {
 public:
  void setCommand(Command* command) {
    m_command = command;
  }
  void executeCommand() {
    m_command->execute();
  }

 private:
  Command* m_command;
};

#endif  // COMMAND_H
