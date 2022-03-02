cmake_minimum_required(VERSION 3.20)
project(_course_ C)

set(CMAKE_C_STANDARD 11)

add_executable(project main.c tasks/removeNonLetters.h tasks/allTasks.h tasks/removeAdjacentEqualLetter.h)

add_library (str string_.h string_.c
        tasks/removeNonLetters.h
        tasks
        )




target_link_libraries(project str)