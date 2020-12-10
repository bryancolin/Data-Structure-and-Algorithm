#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <cstddef>
#include <string>
#include <utility>
#include <algorithm>
#include <limits>
#include <optional>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <climits>

#define INFINITY 9999

#include "directed_graph.h"

using namespace std;

/*
 * Computes the shortest distance from u to v in graph g.
 * The shortest path corresponds to a sequence of vertices starting from u and ends at v,
 * which has the smallest total weight of edges among all possible paths from u to v.
 */

template <typename T>
T min_distance(T distance[], bool visited[], directed_graph<T> g)
{
  int min = INT_MAX, min_index;                      // Initialize min value
  
  for(unsigned i=0; i<g.num_vertices(); i++)         // Iterate the neighbour
  {
    if(!visited[i] && distance[i] <= min)            // If not visited & distance is smaller than Infinity
    {
      min = distance[i];                             // min equals to the distance
      min_index = i;                                 // min index equals to i
    }
  }

  return min_index;                                  // Return the index
}

template <typename T>
void dijkstra_algorithm(T distance[], int parent[], bool visited[], directed_graph<T> g)
{
  int size = g.num_vertices();
  for(unsigned count = 0; count < size - 1; count++) // Iterate through every vertex
  {
    int a = min_distance(distance, visited, g);      // Find the distance 
    visited[a] = true;                               // Make it visited

    for(unsigned b = 0; b < size; b++)               // Iterate through every neighbour 
    {
      T edge_weight = g.adjacent_matrix(a,b);

      if(!visited[b] && edge_weight!=0 && distance[b] > distance[a] + edge_weight)
      {
        parent[b] = a;                               // Add the vertex as parent
        distance[b] = distance[a] + edge_weight;     // Add the distance of the vertex
      }
    }
  }
}

template <typename T>
void get_path(int v, int parent[], vector<vertex<T>> &ordered, directed_graph<T> g)
{
  for (unsigned i = 0; i < g.num_vertices(); i++)    // Iterate through the neighbour
  {
    if (i == v)                                      // If found the destination (v)
    {          
      do                                             // Loop till parent is equal -1
      {
        ordered.push_back(g.get_vertex(v));          // Push it to the vector
        v = parent[v];                               // Get the parent
      } while (parent[v] != -1);

      ordered.push_back(g.get_vertex(v));            // Push the source to the vector
    }
  }
}

template <typename T>
vector<vertex<T>> shortest_path(directed_graph<T> g, int u_id, int v_id) {

  // Create a vector to store all the path of vertex
  vector<vertex<T>> ordered;
  int size = g.num_vertices();
  int u = g.get_index(u_id);
  int v = g.get_index(v_id);

  // Create every vertex distance infinity and unvisited
  T distance[size];
  bool visited[size];
  for (unsigned i = 0; i < size; i++)
  {
    distance[i] = INT_MAX;
    visited[i] = false;
  }

  // Create a parent array to store the vertex
  int parent[size];

  // Make the u_id (source) vertex 0
  distance[u] = 0;
  parent[u] = -1;

  // Use Dijkstra Algorithm to find the shortest path/ minimum distance
  dijkstra_algorithm(distance, parent, visited, g);

  // Get all of the path and push it to the vector
  get_path(v, parent, ordered, g);

  // Reverse the ordered of vector
  reverse(ordered.begin(), ordered.end());

  // Return all the path from source to destination in vector
  return ordered;
}

/*
 * Computes the strongly connected components of the graph.
 * A strongly connected component is a subset of the vertices
 * such that for every pair u, v of vertices in the subset,
 * v is reachable from u and u is reachable from v.
 */

template <typename T>
void fill_stack(int u_id, bool visited[], stack<vertex<T>> &unprocessed, directed_graph<T>& g) 
{
  visited[u_id] = true;                           // Make vertex visited                      
                                             
  for(unsigned i=0; i<g.num_vertices(); i++)      // Iterate the neighbour if not visited                        
  {
    if(!visited[i] && g.adjacent_matrix(u_id,i)!=0)                                                              
    {
      fill_stack(i, visited, unprocessed, g);                           
    }
  }
                                          
  unprocessed.push(g.get_vertex(u_id));           // Push visited vertex to the stack                       
}

template <typename T>
void recursive_dfs(vertex<T> v, bool visited[], vector<vertex<T>> &component, directed_graph<T> g) 
{
  visited[v.id] = true;                           // Make vertex visited   
  component.push_back(v);                         // Push visited vertex to the component                                            
                                                                                        
  for(auto i: g.get_vertices())                   // Iterate the neighbour if not visited                        
  {
    if(!visited[i.id] && g.adjacent_matrix(g.get_index(v.id),g.get_index(i.id))!=0)                                               
    {
      recursive_dfs(i, visited, component, g);                         
    }
  }
}

template <typename T>
vector<vector<vertex<T>>> strongly_connected_components(directed_graph<T> g) {

  // Create a vector to store all strongly connected components
  vector<vector<vertex<T>>> all_sccs; 
  stack<vertex<T>> unprocessed;
  int size = g.num_vertices();

  // Mark every vertex unvisited
  bool visited[size];
  g.visited(size);

  // 1.Fill every unvisited vertex 
  for(unsigned i=0; i<size; i++)
  {
    if(!visited[i])
    {
      fill_stack(i, visited, unprocessed, g);
    }
  }

  // 2.Reverse the graph
  directed_graph<T> reversedGraph = g.reverse_graph();

  // 2.1Mark every vertex unvisited for reverse graph
  for(unsigned i=0; i<size; i++)
  {
    visited[i] = false;
  }

  // 3.Push the component from the Stack into the Vector of SCCS using Kosaraju's Algorithm
  while(!unprocessed.empty())
  {
    vertex<T> current = unprocessed.top();
    unprocessed.pop();

    if(!visited[current.id])
    {
        vector<vertex<T>> component;
        recursive_dfs(current, visited, component, reversedGraph);
        all_sccs.push_back(component);
    }
  }

  // Return All Strongly Connected Components
  return all_sccs;
}

/*
 * Computes a topological ordering of the vertices.
 * For every vertex u in the order, and any of its
 * neighbours v, v appears later in the order than u.
 * You will be given a DAG as the argument.
 */

template <typename T>
void topological_Sort_Util(int u_id, bool visited[], vector<vertex<T>>& order, directed_graph<T> g) 
{ 
  visited[u_id] = true;                             // Make u_id visited         

  for(unsigned i=0; i<g.num_vertices(); i++)        // Iterate the matrix if the neighbour is not visited                        
    if(!visited[i] && g.adjacent_matrix(u_id,i)!=0)                                                                                       
         topological_Sort_Util(i, visited, order, g);           

  order.push_back(g.get_vertex(u_id));              // Push it to the Vector                                            
} 

template <typename T>
vector<vertex<T>> topological_sort(directed_graph<T> g) 
{
  // Create vector to store all the vertex
  vector<vertex<T>> ordered; 
  stack<vertex<T>> unprocessed;
  int size = g.num_vertices();
  
  // Make every vertex unvisited
  bool visited[size]; 
  g.visited(size);

  // Iterate through the vertex list
  for(unsigned i = 0; i < size; i++) 
  {
    if(!visited[i])  
    {
      fill_stack(i, visited, unprocessed, g); 
    }
  }

  // Store the vertex from the stack to vector 
  while(!unprocessed.empty())
  {
    vertex<T> current = unprocessed.top();
    ordered.push_back(current);
    unprocessed.pop();
  } 

  // Return the vector 
  return ordered;
}

/*
 * Computes the lowest cost-per-person for delivery over the graph.
 * u is the source vertex, which send deliveries to all other vertices.
 * vertices denote cities; vertex weights denote cities' population;
 * edge weights denote the fixed delivery cost between cities, which is irrelevant to 
 * the amount of goods being delivered. 
 */

template <typename T>
void depth_first_search(int v, bool visited[], vector<T>& ordered, directed_graph<T>& g) 
{ 
  visited[v] = true;                              // Make u_id visited
  ordered.push_back(v);                           // Push it to the vector

  for(unsigned i=0; i<g.num_vertices(); i++)      // Iterate through the neighbour
  {
    if(!visited[i] && g.adjacent_matrix(v,i)!=0)  // Check if adjacent/edge weight between vertices                                                            
    {
      depth_first_search(i, visited, ordered, g);                           
    }
  }
} 

template <typename T>
T low_cost_delivery(directed_graph<T> g, int u_id) 
{
  int size = g.num_vertices();
  int u = g.get_index(u_id);

  // Create every vertex distance infinity and unvisited
  T distance[size];
  bool visited[size];
  for(unsigned i=0; i<size; i++)
  {
    distance[i] = INT_MAX;
    visited[i] = false;
  }

  // Create a parent array to store the vertex
  int parent[size];

  // Create the source distance 0 and the parent -1
  distance[u] = 0;
  parent[u] = -1;

  // Use Dijsktra Algorithm to find the shortest path/ minimum distance
  dijkstra_algorithm(distance, parent, visited, g);

  // Make every vertex unvisited again
  for(unsigned i=0; i<size; i++)
  {
    visited[i] = false;
  }
  
  // Create a vector to store all path from source using DFS
  vector<T> ordered;
  depth_first_search(u, visited, ordered, g);

  // Calculate the total edge_weight and the total vertex weight by iterating from source vertex
  T total_edge_weight = 0, total_vertex_weight = 0;
  for(auto i: ordered)
  {
    if(i!=u)
    {
      total_edge_weight += g.adjacent_matrix(parent[i],i);
      total_vertex_weight += g.get_vertex(i).weight;
    }
  }

  // Check if one node only or no edge
  if(total_edge_weight==0) { return 0; }

  // Calculate the low cost
  T low_cost = total_edge_weight/total_vertex_weight;
  
  return low_cost;

}
