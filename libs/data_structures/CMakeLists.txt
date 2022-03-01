add_library(data_structures
        matrix/matrix.c
        vector/vector.c
        matrix/main.c ../../string/string_.c ../../string/string_.h)

target_link_libraries(data_structures algorithms)