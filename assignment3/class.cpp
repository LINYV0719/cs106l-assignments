#include "class.h"
#include <string>
#include <stdexcept>
#include <iostream>

template <typename T>
myclass<T>::myclass(std::string class_name,std::string teacher_name,int max_capacity){
    this->class_name = class_name;
    this->teacher_name = teacher_name;
    this->max_capacity = max_capacity;

}

template <typename T>
bool myclass<T>::isFull() const{
   return max_capacity <= students.size();
}

template <typename T>
myclass<T>::myclass() = default;

template <typename T>
bool myclass<T>::addStudent(const T& student){
    if(!isFull()){
        students.push_back(student);
        return true;
    }
    else{
        throw std::runtime_error("Classroom is full!"
            "Cannot add more students.");
    }
}

template <typename T>
T myclass<T>::getStudentAt(size_t index) const{
  if(index < students.size()){
    return students.at(index);
  }
  else{
    throw std::out_of_range("Index out of bounds: " + 
        std::to_string(index));
  }
}

template <typename T>
void myclass<T>::removeLastStudent(){
    students.pop_back();
}

template <typename T>
void myclass<T>::printRollCall() const{
    for(const T& student : students){
        std::cout << student << std::endl; 
    }
}


