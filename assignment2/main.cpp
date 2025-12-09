/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Aziel Le"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream ifs(filename);
  if(!ifs.is_open()){
    exit;
  }
  std::set<std::string> students;
  std::string newline;
  while(std::getline(ifs,newline)){
     students.insert(newline);
  }
  return students;
}

bool find_initials_matches(std::string kYourName,std::string name){
    std::stringstream myname(kYourName);
    std::string my_first_name;
    std::string my_second_name;
    std::stringstream othername(name);
    std::string first_name;
    std::string second_name;
    myname>>my_first_name>>my_second_name;
    othername>>first_name>>second_name;
    bool first_judge = (my_first_name.at(0)==first_name.at(0));
    bool second_judge = (my_second_name.at(0)==second_name.at(0));
    if(first_judge&&second_judge){
      return 1;
    }
    else{
      return 0;
    }
  }

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> match_names;
  for(const auto& student:students){
     if(find_initials_matches(name,student)){
       const std::string* student_refference = &student;
       match_names.push(student_refference);
     }
  }
  return match_names;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  std::string match_name;
  if(matches.empty()){
    printf("NO MATCHES FOUND.");
    exit;
  }
  else{
    int extract_number = matches.size()-2;
    for (int i = 0; i < extract_number; i++)
    {
      matches.pop();
    }
    match_name = *matches.front();
  }
  return match_name;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
