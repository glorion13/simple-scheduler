#include <tbb/flow_graph.h>
#include <vector>
#include <cstdio>
#include <functional>

namespace scheduler {

template <typename T> struct Task {
  std::function<T> m_func;

  Task(std::function<T> func) : m_func(func) {}
  void operator()(tbb::flow::continue_msg) const { m_func(); }
};

class Graph {

  using GraphT = tbb::flow::graph;
  using NodeT = tbb::flow::continue_node<tbb::flow::continue_msg>;

public:
  Graph() : m_root_node(m_graph, [](...) {}) {}

  void set_dependency(NodeT &node_a, NodeT &node_b) {
    tbb::flow::make_edge(node_a, node_b);
  }

  NodeT create_node(const std::function<void()> func) {
    NodeT new_node(m_graph, Task<void()>(func));
    make_edge(m_root_node, new_node);
    return new_node;
  }

  void run() {
    m_root_node.try_put(tbb::flow::continue_msg());
    m_graph.wait_for_all();
  }

  GraphT m_graph;
  NodeT m_root_node;
};

} // namespace scheduler
