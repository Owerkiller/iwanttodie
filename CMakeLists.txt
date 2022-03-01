cmake_minimum_required(VERSION 3.20)
project(_course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c string/tasks/removeNonLetters.h string/tasks/allTasks.h)

add_library (str string/string_.h string/string_.c
        string/tasks/removeNonLetters.h
        #string/tasks/digitToStartTransform.h
        #string/tasks/reverseWords.h
        )




target_link_libraries(project str)