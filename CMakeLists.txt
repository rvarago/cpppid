cmake_minimum_required(VERSION 3.10)

project(cpppid)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME}
	INTERFACE
		include
)

target_compile_features(${PROJECT_NAME}
	INTERFACE
		cxx_std_17
)

enable_testing()
add_subdirectory(test)
