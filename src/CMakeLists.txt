target_sources(sdk PUBLIC
            spacetraders-sdk.cpp)

target_include_directories(sdk PUBLIC 
            ${CMAKE_SOURCE_DIR}/include
            ${CMAKE_SOURCE_DIR}/include/api
            ${CMAKE_SOURCE_DIR}/include/models)

target_link_libraries(sdk PRIVATE
    restclient-cpp
    nlohmann_json::nlohmann_json
)

add_executable(${PROJECT_NAME} 
                main.cpp)


