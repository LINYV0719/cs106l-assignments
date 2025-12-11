#pragma once
//to avoid multi-include
#include <cstddef>
//to use size_t
#include <string>
#include <vector>

template <typename T>
class myclass{
    private:
    std::vector<T> students = {};
    std::string class_name = "Default Class";
    std::string teacher_name = "Unknown";
    int max_capacity = 10;
    bool isFull() const;

    public:
    myclass(std::string class_name,std::string teacher_name,int max_capacity);
    myclass();
    bool addStudent(const T& student);
    T getStudentAt(size_t index) const;
    void removeLastStudent();
    void printRollCall() const;
};
#include "class.cpp"