CMAKE_MINIMUM_REQUIRED ( VERSION 3.1 )

SET ( CMAKE_CXX_STANDARD 11 )

PROJECT ( HYPER-OS )

FILE ( GLOB_RECURSE src_list "user/*.cpp" "src/*.cpp" "test/*.cpp" "dev/*.cpp" )

SET ( prog_name hos )

SET ( CMAKE_INSTALL_PREFIX )

SET ( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
ADD_EXECUTABLE ( ${prog_name} ${src_list} )

target_link_libraries( ${prog_name} pthread )

if (WIN32)
  if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -O2")
  endif(CMAKE_COMPILER_IS_GNUCXX)
else ()
  if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -O2 -fsanitize=undefined ${CMAKE_CXX_FLAGS}")
  endif(CMAKE_COMPILER_IS_GNUCXX)
endif ()
