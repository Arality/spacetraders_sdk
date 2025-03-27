add_executable(tests
                test.cpp)
                
target_link_libraries(tests PRIVATE
                    GTest::gtest_main
                    restclient-cpp
                    nlohmann_json::nlohmann_json
                    sdk)


                

include(GoogleTest)
gtest_discover_tests(tests)