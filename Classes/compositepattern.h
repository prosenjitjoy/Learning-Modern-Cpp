#ifndef COMPOSITEPATTERN_H
#define COMPOSITEPATTERN_H

#include <format>
#include <string>
#include <vector>

class ListOfTasks {
  public:
    virtual void setTask(std::string) = 0;
    virtual std::string getTask() const = 0;
    virtual bool isDone() const = 0;
    virtual void setDeadline(std::string) = 0;
    virtual std::string getDeadline() const = 0;
};

class Task : public ListOfTasks {
  public:
    Task() : m_task_description(), m_done{false} {
    }
    Task(std::string task) : m_task_description{task} {
    }
    Task(std::string task, std::string deadline)
        : m_task_description(task), m_deadline{deadline} {
    }

    void setTask(std::string task) {
        m_task_description = task;
    }

    std::string getTask() const {
        return std::format("{} --- {}\n", m_task_description,
                           this->getDeadline());
    }

    void markDown() {
        m_done = true;
    }

    bool isDone() const {
        return m_done == true;
    }

    void setDeadline(std::string deadline) {
        m_deadline = deadline;
    }

    std::string getDeadline() const {
        return m_deadline;
    }

  private:
    std::string m_task_description;
    std::string m_deadline;
    bool m_done;
};

class Project : public ListOfTasks {
  public:
    Project() : m_project_name{}, m_done{false} {
    }
    Project(std::string name) : m_project_name{name} {
    }
    Project(std::string name, Task task)
        : m_project_name{name}, m_tasks{new Task(task)} {
    }
    Project(std::string name, std::vector<ListOfTasks*> taskList)
        : m_project_name{name}, m_tasks{taskList} {
    }
    Project(std::string name, std::string projectDate, Task t,
            std::string taskDate)
        : m_project_name{name}, m_deadline{projectDate} {
        m_tasks.push_back(new Task(t));
        m_tasks[0]->setDeadline(taskDate);
    }

    void setTask(std::string taskName) {
        m_tasks.push_back(new Task(taskName));
    }
    void setProject(std::string name) {
        m_tasks.push_back(new Project(name));
    }
    std::string getTask() const {
        std::string str{};
        str += this->m_project_name + '\n';
        for (auto i : m_tasks) {
            str += i->getTask();
        }
        return str;
    }
    void setDeadline(std::string deadline) {
        m_deadline = deadline;
    }
    std::string getDeadline() const {
        return m_deadline;
    }
    bool isDone() const {
        for (auto i : m_tasks) {
            return i->isDone();
        }
        return true;
    }

  private:
    std::string m_project_name;
    std::vector<ListOfTasks*> m_tasks;
    std::string m_deadline;
    bool m_done;
};

#endif  // COMPOSITEPATTERN_H
