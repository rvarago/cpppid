ifndef PROFILE
override PROFILE="../profiles/x86_64"
endif

ifndef RUNNER
override RUNNER=
endif

.PHONY: all env-x86_64 env-x86_64-test env-x86_64-run env-armv7 env-armv7-test env-armv7-run test compile gen dep mk clean

all: compile

env-x86_64:
	docker build -t cpppid_$@:0.1 -f Dockerfile_$@ .

env-x86_64-test: env-x86_64
	docker run --rm -t cpppid_$^:0.1 make test

env-x86_64-run: env-x86_64
	docker run -it --rm cpppid_$^:0.1

env-armv7:
	docker build -t cpppid_$@:0.1 -f Dockerfile_$@ .

env-armv7-test: env-armv7
	docker run --rm -t cpppid_$^:0.1 make test

env-armv7-run: env-armv7
	docker run -it --rm cpppid_$^:0.1

test: all
	cd build && ${RUNNER} ./test/cpppid_test

compile: gen
	cd build && cmake --build .

gen: dep
	cd build && cmake ..

dep: mk
	cd build && conan install .. --build=missing -pr ${PROFILE}

mk:
	-mkdir build

clean:
	rm -rf build
