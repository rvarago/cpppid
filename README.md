# cpppid
A composable library based on templates to implement control loops in C++17.

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
make env-test
```
