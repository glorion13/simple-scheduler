# simple-scheduler

This is a simple example of a dependency graph, using the Thread Building Blocks (TBB) library.

The aim is to run a series of tasks as quickly as possible, threading where applicable, while maintaining their dependencies.

If we had:

```
Task A  -> Task B
Task C
```

We expect:

```
Thread  1: Task A followed by Task B
Thread 2: Task C
```

## Why TBB?

TBB already provides the functionality we need in its Flow Graph. Moreover, TBB is a relatively lightweight library that is commonly used for other threading tasks, so it would be likely we use it in other parts of the code, e.g. for its `parallel_for`.

## Build and install

This example uses CMake. From the root directory:

```
cmake -H. -Bbuild
cmake --build build -j8
./bin/simplescheduler
```

There is also a Dockerfile to set up the required C++ environment and build the project:

```
docker build --rm -f "Dockerfile" -t glorion13/simplescheduler:latest "."
docker run --rm -it glorion13/simplescheduler:latest
```

