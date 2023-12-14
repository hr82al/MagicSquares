cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Подключение библиотеки wxWidgets
# Request the required wxWidgets libs
find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)

# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})

file(GLOB SRC_FILES
    "*.h"
    "*.cpp"
    "MagicSquaresCalc/*.h"
    "MagicSquaresCalc/*.cpp"
)


# Define the build target for the executable
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SRC_FILES})
# Link required libraries to the executable
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


#Подлключение библиотеки boost
#include_directories("C:/progs/libs/boost_1_75_0")
find_package(Boost 1.75.0)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

 