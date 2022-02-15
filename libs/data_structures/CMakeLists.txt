add_library(data_structures
        matrix/matrix.c
        vector/vector.c
        )

target_link_libraries( data_structures algorithms)