set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

add_executable(cpppid_test
	cpppid_test.cpp

	controller_derivative_test.cpp
	controller_integral_test.cpp
	controller_proportional_test.cpp

	composer_adder_test.cpp
)

target_compile_features(cpppid_test
	PRIVATE
		cxx_std_14
)

if (NOT MSVC)
        target_compile_options(cpppid_test
                PRIVATE
                        -Wall -Wextra -Werror -ansi -pedantic
        )
endif()

find_package(gtest REQUIRED)

target_link_libraries(cpppid_test
	PRIVATE
		gtest::gtest
		cpppid
)

add_test(tests cpppid_test)