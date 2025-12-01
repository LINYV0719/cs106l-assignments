/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * This file contains utility functions that you may find useful while
 * implementing the assignment. You don't need to modify anything here,
 * but feel free to look around.
 */

/**
 * Forward declarations of some important methods. Don't worry about these!
 * (unless you really want to).
 */
bool operator==(const Course& lhs, const Course& rhs);
std::ostream& operator<<(std::ostream& os, const Course& course);

/**
 * Splits a string by a delimiter and returns a vector of the split strings.
 * 通过分割符把传入的文本分割成string类型的结果，这里是按delim分割
 * token是指分割后的每个子字符串
 * @param s     The string to split.
 * @param delim The delimiter to split by.
 * @returns     A vector of the split strings.
 */
std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> return_vec;
  std::stringstream ss(s);
  std::string token;
  while (std::getline(ss, token, delim)) {
    return_vec.push_back(token);
  }
  return return_vec;
}

/**
 * Deletes a Course from a vector of courses.
 * 从课程向量中删除指定的课程，elem指删除的课程，iterator是之后要学到的，这里暂时不去理解意思
 * @param v    The vector of courses.
 * @param elem The course to delete.
 *
 * We will learn more about what's going on in this function in Weeks 3 and 5!
 */
void delete_elem_from_vector(std::vector<Course>& v, const Course& elem) {
  std::vector<Course>::iterator it = std::find(v.begin(), v.end(), elem);
  v.erase(it);
}

/**
 * Prints a vector of courses (for debugging purposes)!
 * 打印课程向量（用于调试）
 * @param vector_of_courses The vector of courses to print.
 */
void print_courses(const std::vector<Course>& vector_of_courses) {
  for (const Course& course : vector_of_courses) {
    std::cout << course << std::endl;
  }
}

/* ========================================================================= *
 * Don't worry about anything beyond this point.                             *
 * (unless you are really curious and want to!)                              *
 * ========================================================================= */

bool operator==(const Course& lhs, const Course& rhs) {
  return lhs.title == rhs.title && lhs.number_of_units == rhs.number_of_units &&
         lhs.quarter == rhs.quarter;
}

std::ostream& operator<<(std::ostream& os, const Course& course) {
  os << course.title << ", " << course.number_of_units << ", " << course.quarter;
  return os;
}

template <typename T>
concept is_valid_course = requires(T t) {
  { T{"Standard C++ Programming", "1", "2023-2024 Winter"} };
  std::is_same_v<T, Course>;
};

int
run_autograder()
{
  auto run_program = [](std::string program,
                        std::initializer_list<std::string> args,
                        bool silent = false) {
    std::stringstream ss;

    ss << program;
    for (const auto& arg : args) {
      ss << ' ' << arg;
    }

    if (silent) {
#ifdef _WIN32
      ss << " >nul 2>&1";
#else
      ss << " >/dev/null 2>&1";
#endif
    }

    std::cout.flush();
    return system(ss.str().c_str());
  };

  std::string python;
  for (const auto& option :
       { "python", "python3", "/usr/bin/python3", "/usr/bin/python" }) {
    if (run_program(option, { "--version" }, true) == 0) {
      python = option;
      break;
    }
  }

  if (python.empty()) {
    std::cerr
      << "Python was not found on your system. Please install Python and "
                 "try again."
              << "\n";
    std::exit(1);
  }

  return run_program(python, { "autograder/autograder.py" });
}