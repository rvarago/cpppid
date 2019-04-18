PROFILE=x86_64

.PHONY: all env-x86_64 env-x86_64-test env-x86_64-run test compile gen dep mk clean

all: compile

env-x86_64:
	docker build -t cpppid_$@:0.1 -f Dockerfile_$@ .

env-x86_64-test: env-x86_64
	docker run --rm -t cpppid_$^:0.1 make test

env-x86_64-run: env-x86_64
	docker run -it --rm cpppid_$^:0.1

test: all
	cd build && ctest .

compile: gen
	cd build && cmake --build .

gen: dep
	cd build && cmake ..

dep: mk
	cd build && conan install .. --build=missing -pr ../profiles/${PROFILE}

mk:
	-mkdir build

clean:
	rm -rf build
