#include <boost/detail/algorithm.hpp>
#include <boost/graph/adjacency_iterator.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/adjacency_list_io.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/adj_list_serialize.hpp>
#include <boost/graph/astar_search.hpp>
#include <boost/graph/bandwidth.hpp>
#include <boost/graph/bc_clustering.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>
#include <boost/graph/betweenness_centrality.hpp>
#include <boost/graph/biconnected_components.hpp>
#include <boost/graph/bipartite.hpp>
#include <boost/graph/boyer_myrvold_planar_test.hpp>
#include <boost/graph/boykov_kolmogorov_max_flow.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/bron_kerbosch_all_cliques.hpp>
#include <boost/graph/buffer_concepts.hpp>
#include <boost/graph/chrobak_payne_drawing.hpp>
#include <boost/graph/circle_layout.hpp>
#include <boost/graph/closeness_centrality.hpp>
#include <boost/graph/clustering_coefficient.hpp>
#include <boost/graph/compressed_sparse_row_graph.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/copy.hpp>
#include <boost/graph/core_numbers.hpp>
#include <boost/graph/create_condensation_graph.hpp>
#include <boost/graph/cuthill_mckee_ordering.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/dag_shortest_paths.hpp>
#include <boost/graph/degree_centrality.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/dijkstra_shortest_paths_no_color_map.hpp>
#include <boost/graph/dimacs.hpp>
#include <boost/graph/directed_graph.hpp>
#include <boost/graph/dll_import_export.hpp>
#include <boost/graph/dominator_tree.hpp>
#include <boost/graph/eccentricity.hpp>
#include <boost/graph/edge_coloring.hpp>
#include <boost/graph/edge_connectivity.hpp>
#include <boost/graph/edge_list.hpp>
#include <boost/graph/edmonds_karp_max_flow.hpp>
#include <boost/graph/erdos_renyi_generator.hpp>
#include <boost/graph/exception.hpp>
#include <boost/graph/exterior_property.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/find_flow_cost.hpp>
#include <boost/graph/floyd_warshall_shortest.hpp>
#include <boost/graph/fruchterman_reingold.hpp>
#include <boost/graph/geodesic_distance.hpp>
#include <boost/graph/graph_archetypes.hpp>
#include <boost/graph/graph_as_tree.hpp>
#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graphml.hpp>
#include <boost/graph/graph_mutability_traits.hpp>
#include <boost/graph/graph_selectors.hpp>
#include <boost/graph/graph_stats.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/grid_graph.hpp>
#include <boost/graph/gursoy_atun_layout.hpp>
#include <boost/graph/hawick_circuits.hpp>
#include <boost/graph/howard_cycle_ratio.hpp>
#include <boost/graph/incremental_components.hpp>
#include <boost/graph/is_kuratowski_subgraph.hpp>
#include <boost/graph/isomorphism.hpp>
#include <boost/graph/is_straight_line_drawing.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <boost/graph/iteration_macros_undef.hpp>
#include <boost/graph/johnson_all_pairs_shortest.hpp>
#include <boost/graph/kamada_kawai_spring_layout.hpp>
#include <boost/graph/king_ordering.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/labeled_graph.hpp>
#include <boost/graph/lookup_edge.hpp>
#include <boost/graph/loop_erased_random_walk.hpp>
#include <boost/graph/make_biconnected_planar.hpp>
#include <boost/graph/make_connected.hpp>
#include <boost/graph/make_maximal_planar.hpp>
#include <boost/graph/matrix_as_graph.hpp>
#include <boost/graph/max_cardinality_matching.hpp>
#include <boost/graph/maximum_adjacency_search.hpp>
#include <boost/graph/maximum_weighted_matching.hpp>
#include <boost/graph/mcgregor_common_subgraphs.hpp>
#include <boost/graph/mesh_graph_generator.hpp>
#include <boost/graph/metis.hpp>
#include <boost/graph/metric_tsp_approx.hpp>
#include <boost/graph/minimum_degree_ordering.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/named_graph.hpp>
#include <boost/graph/neighbor_bfs.hpp>
#include <boost/graph/numeric_values.hpp>
#include <boost/graph/one_bit_color_map.hpp>
#include <boost/graph/overloading.hpp>
#include <boost/graph/page_rank.hpp>
#include <boost/graph/planar_canonical_ordering.hpp>
#include <boost/graph/planar_face_traversal.hpp>
#include <boost/graph/plod_generator.hpp>
#include <boost/graph/point_traits.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>
#include <boost/graph/profile.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/property_iter_range.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/random.hpp>
#include <boost/graph/random_layout.hpp>
#include <boost/graph/random_spanning_tree.hpp>
#include <boost/graph/r_c_shortest_paths.hpp>
#include <boost/graph/read_dimacs.hpp>
#include <boost/graph/relax.hpp>
#include <boost/graph/reverse_graph.hpp>
#include <boost/graph/rmat_graph_generator.hpp>
#include <boost/graph/sequential_vertex_coloring.hpp>
#include <boost/graph/simple_point.hpp>
#include <boost/graph/sloan_ordering.hpp>
#include <boost/graph/smallest_last_ordering.hpp>
#include <boost/graph/small_world_generator.hpp>
#include <boost/graph/ssca_graph_generator.hpp>
#include <boost/graph/st_connected.hpp>
#include <boost/graph/stoer_wagner_min_cut.hpp>
#include <boost/graph/strong_components.hpp>
#include <boost/graph/subgraph.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/tiernan_all_cycles.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/topology.hpp>
#include <boost/graph/transitive_closure.hpp>
#include <boost/graph/transitive_reduction.hpp>
#include <boost/graph/transpose_graph.hpp>
#include <boost/graph/tree_traits.hpp>
#include <boost/graph/two_bit_color_map.hpp>
#include <boost/graph/two_graphs_common_spanning_trees.hpp>
#include <boost/graph/undirected_dfs.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/use_mpi.hpp>
#include <boost/graph/vector_as_graph.hpp>
#include <boost/graph/vertex_and_edge_range.hpp>
#include <boost/graph/vf2_sub_graph_iso.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/wavefront.hpp>
#include <boost/graph/write_dimacs.hpp>
#include <boost/pending/bucket_sorter.hpp>
#include <boost/pending/container_traits.hpp>
#include <boost/pending/disjoint_sets.hpp>
#include <boost/pending/fenced_priority_queue.hpp>
#include <boost/pending/fibonacci_heap.hpp>
#include <boost/pending/indirect_cmp.hpp>
#include <boost/pending/is_heap.hpp>
#include <boost/pending/mutable_heap.hpp>
#include <boost/pending/mutable_queue.hpp>
#include <boost/pending/property.hpp>
#include <boost/pending/property_serialize.hpp>
#include <boost/pending/queue.hpp>
#include <boost/pending/stringtok.hpp>

#include <sstream>

using namespace std;
using namespace boost;

int
main ()
{
  // This code uses the graphviz parser which is one of the few compiled parts
  // of Boost.Graph.
  //

  // Vertex properties.
  //
  typedef property<vertex_name_t, string, property<vertex_color_t, float>>
      vertex_p;

  // Edge properties.
  //
  typedef property<edge_weight_t, double> edge_p;

  // Graph properties.
  //
  typedef property<graph_name_t, string> graph_p;

  // adjacency_list-based type.
  //
  typedef adjacency_list<vecS, vecS, directedS, vertex_p, edge_p, graph_p>
      graph_t;

  // Construct an empty graph and prepare the dynamic_property_maps.
  //
  graph_t graph (0);
  dynamic_properties dp;

  property_map<graph_t, vertex_name_t>::type name (get (vertex_name, graph));
  dp.property ("node_id", name);

  property_map<graph_t, vertex_color_t>::type mass (get (vertex_color, graph));
  dp.property ("mass", mass);

  property_map<graph_t, edge_weight_t>::type weight (get (edge_weight, graph));
  dp.property ("weight", weight);

  // Use ref_property_map to turn a graph property into a property map.
  //
  boost::ref_property_map<graph_t*, string> gname (
      get_property (graph, graph_name));
  dp.property ("name", gname);

  // Sample graph as an istream.
  //
  istringstream gvgraph (
      "digraph { graph [name=\"graphname\"]  a  c e [mass = 6.66] }");

  return read_graphviz (gvgraph, graph, dp, "node_id") ? 0 : 1;
}
