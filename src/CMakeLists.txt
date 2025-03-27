target_include_directories(sdk PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_sources(sdk
              PUBLIC
              authentication.cpp
              connection.cpp)

add_subdirectory(api)
add_subdirectory(models)


target_link_libraries(sdk PRIVATE
    restclient-cpp
    nlohmann_json::nlohmann_json
)

# add_library(sdk
#             authentication.cpp)

# include_directories(sdk PUBLIC 
#             ${CMAKE_SOURCE_DIR}/include)

# # target_link_libraries(sdk PRIVATE
# #   restclient-cpp
# #   nlohmann_json::nlohmann_json
# # )

add_executable(${PROJECT_NAME} 
                main.cpp)