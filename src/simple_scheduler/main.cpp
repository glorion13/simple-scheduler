// Adapted from: https://software.intel.com/en-us/node/506216
#include <cstdio>
#include <ctime>

#include "scheduler/graph.h"

void delay_and_print(const char *text) {
  struct timespec thread_delay;
  thread_delay.tv_sec = 5;
  thread_delay.tv_nsec = 0L;
  nanosleep(&thread_delay, NULL);
  printf("%s\n", text);
}

int main() {
  scheduler::Graph graph;
  auto a = graph.create_node([]() { delay_and_print("A"); });
  auto b = graph.create_node([]() { delay_and_print("B"); });
  auto c = graph.create_node([]() { delay_and_print("C"); });
  auto d = graph.create_node([]() { delay_and_print("D"); });
  auto e = graph.create_node([]() { delay_and_print("E"); });
  graph.set_dependency(a, c);
  graph.set_dependency(b, c);
  graph.set_dependency(a, d);
  graph.run();

  return 0;
}