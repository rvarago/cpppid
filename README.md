# cpppid

A composable library based on templates to implement control loops in C++17.

[![Build Status](https://travis-ci.org/rvarago/cpppid.svg?branch=master)](https://travis-ci.org/rvarago/cpppid)

## Description

By composing basic control functions, for instance:
* Proportional
* Integral
* Derivative

With a suitable composer, for instance:
* Adder

You can obtain complex controllers, in particular, the classic PID controller as something like this:

```cpp
cpppid::composers::adder {
  cpppid::controllers::proportional,
  cpppid::controllers::integral,
  cpppid::controllers::derivatite 
}
```

## Build

The _Makefile_ wraps the commands to download dependencies (Conan), generate the build configuration, build, run the unit tests, and clear the build folder.

* Compile (currently, it also compiles the unit tests):

```
make
```

It assumes that the default profile (*profiles/x86_64*) applies to your build, if not, then you can specify your profile by appending _PROFILE=_.

* Run the unit tests:

```
make test
```

* Clear the _build_ folder:

```
make clean
```

## Run tests inside a Docker container

Optionally, it's possible to run the tests for cpppid inside a Docker container by running:

```
make env-x86_64 # create docker image for x86_64
make env-x86_64-run # logs in the container
make test
```

Or:

```
make env-x86_64-test # the same as: make env-x86_64 env-x86_64-run make test
```

Or you can build and test for armv7 by simply changing the mentions to *x86_64* to *armv7* in the command above.
