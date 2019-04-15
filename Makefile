.PHONY: all env env-test env-run test compile gen dep mk clean

all: compile

env:
	docker build -t cpppid:0.1 .

env-test: env
	docker run --rm -t cpppid:0.1 make test

env-run: env
	docker run -it --rm cpppid:0.1

test: all
	cd build && ctest .

compile: gen
	cd build && cmake --build .

gen: dep
	cd build && cmake ..

dep: mk
	cd build && conan install .. -pr ../profile_x86_64

mk:
	-mkdir build

clean:
	rm -rf build
