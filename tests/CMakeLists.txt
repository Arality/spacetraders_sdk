add_executable(tests
                test.cpp)
                
target_link_libraries(tests 
                    main_lib
                    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)