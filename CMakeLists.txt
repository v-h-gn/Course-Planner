CMAKE_MINIMUM_REQUIRED(VERSION 2.8)


ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(debug
    CoursePlanner.cpp
)

ADD_EXECUTABLE(main
    main.cpp
)

ADD_EXECUTABLE(unitTests
    test/test.cpp
)

TARGET_LINK_LIBRARIES(unitTests gtest)
TARGET_COMPILE_DEFINITIONS(unitTests PRIVATE gtest_disable_pthreads=ON)
