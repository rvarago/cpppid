.PHONY: all test compile gen dep mk

all: compile

test: all
	cd build && ctest .

compile: gen
	cd build && cmake --build .

gen: dep
	cd build && cmake ..

dep: mk
	cd build && conan install ..

mk:
	-mkdir build
