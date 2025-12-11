/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <string>
#include <iostream>

void sandbox() {
    myclass<std::string> math_class("math","Lee",5);
    try {
    math_class.addStudent("Flanc");
    math_class.addStudent("Jane");
    math_class.addStudent("Owe");
    math_class.addStudent("Lowis");
    math_class.addStudent("James");
    } catch (const std::exception& e) {
    std::cerr << "Oops! Something went wrong: " << e.what() << '\n';
    }
    math_class.getStudentAt(3);
    try{
        math_class.printRollCall();
    }catch(const std::exception& e){
        std::cerr << "Oops! Something went wrong: " << e.what() << '\n';
    }
    try{
        math_class.addStudent("Lee");
        math_class.printRollCall();
    }catch(const std::exception& e){
        std::cerr << "Oops! Something went wrong: " << e.what() << '\n';
    }
    try{
        math_class.removeLastStudent();
        math_class.printRollCall();
    }catch(const std::exception& e){
        std::cerr << "Oops! Something went wrong: " << e.what() << '\n';
    }

}