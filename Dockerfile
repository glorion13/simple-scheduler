FROM glorion13/cppdev-env:latest

COPY . /usr/src/simple_scheduler
WORKDIR /usr/src/simple_scheduler

RUN /usr/include/cmake/bin/cmake -H. -Bbuild
RUN /usr/include/cmake/bin/cmake --build build -j8

CMD ["./bin/simplescheduler"]

LABEL Name=simplescheduler Version=0.0.1
