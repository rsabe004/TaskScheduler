CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(schedule
	main.cpp
	src/Display.cpp
	src/List.cpp
	src/Menu.cpp
	src/Remove.cpp
	src/Scheduler.cpp
	src/Task.cpp
)

ADD_EXECUTABLE(test
    tests/test.cpp
    src/List.cpp
    src/Task.cpp
    src/Scheduler.cpp
    src/Display.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

