cmake_minimum_required(VERSION 3.9)
project(tp_rloader)
set(CMAKE_CXX_STANDARD 17)

### Output directory ###
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_OUTPUT_DIR ${ROOT_DIR}/Build/)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIR})

message("${PROJECT_NAME} Output in ${CMAKE_OUTPUT_DIR}")

## Sources
if (WIN32)
	include_directories(
		Windows/
	)
	set(SRC
		Windows/RLoader.cpp
		Windows/Rloader.h
	)

elseif(APPLE OR UNIX)
	include_directories(
		Unix/
	)
	set(SRC
		Unix/RLoader.cpp
		Unix/RLoader.h)
endif()

add_library(${PROJECT_NAME} STATIC ${SRC})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
if (WIN32)
	target_include_directories(${PROJECT_NAME} PUBLIC 
	Windows/ 
	.
	)
elseif (APPLE OR UNIX)
	target_include_directories(${PROJECT_NAME} PUBLIC 
	Unix/
	.
	)
endif()