# CMakeList.txt : CMake project for PA210,
# project specific logic here.
#

# Add source to this project's executable.
add_executable (PA210 "List.h" "ArrayList.h" "LinkedList.h" "Data.h" "Player.h" "Stack.h" "main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PA210 PROPERTY CXX_STANDARD 20)
endif()

