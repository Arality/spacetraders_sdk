add_library(main_lib
            log.cpp)

add_executable(${PROJECT_NAME} 
                main.cpp)

target_link_libraries(${PROJECT_NAME} main_lib)