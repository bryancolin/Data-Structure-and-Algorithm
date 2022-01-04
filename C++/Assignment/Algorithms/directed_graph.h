#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 
#include <algorithm>
#include <string>
#include <list>
#include <iterator>

using namespace std; // the standard namespace are here just in case.

/*
	the vertex class
*/
template <typename T>
class vertex {

public:
	int id;
	T weight;

	vertex(int x, T y) : id(x), weight(y) {}

	// add more functions here if you need to
};

/*
	the graph class
*/
template <typename T>
class directed_graph {

private:

	unordered_map<int, unordered_map<int, T>> adj_list; // Adjacent list
	unordered_map<int, T> vertex_weights; // Vertex list for map (id , weight)

	vector<vector<T>> adj_matrix; // Adjacent Matrix
	vector<vertex<T>> vertex_list; // Vertex List
	
	size_t number_of_vertices; // Number of vertices
	size_t number_of_edges; // Number of edges
	
public:
	
	directed_graph(); //A constructor for directed_graph. The graph should start empty.
	~directed_graph(); //A destructor. Depending on how you do things, this may not be necessary.

	T adjacent_matrix(int, int); // Public Method of calling adjacent Matrix

	vertex<T> get_vertex(const int&); // Public Method return vertex

	void print(); // Print Matrix
	void print_list(); // Print Adjacent List
	void matrix(const int&); // Create Matrix

	bool visited(const int&); // Make vertex visited

	int get_index(const int&) const; //Method to get the integer index value of the vertices

	bool contains(const int&) const; //Returns true if the graph contains the given vertex_id, false otherwise.
	bool adjacent(const int&, const int&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const vertex<T>&, const vertex<T>&); //Removes the edge between the two vertices, if it exists.

	size_t in_degree(const int&) const; //Returns number of edges coming in to a vertex.
	size_t out_degree(const int&) const; //Returns the number of edges leaving a vertex.
	size_t degree(const int&) const; //Returns the degree of the vertex (both in edges and out edges).

	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const; //Returns the total number of edges in the graph.

	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
															  // A vector cannot be considered a second_order_neighbour of itself.
	bool reachable(const int&, const int&); //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool contain_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	vector<vertex<T>> depth_first(int); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	directed_graph<T> out_tree(const int&); //Returns a tree starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

	vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the tree starting at the given vertex.
	vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the tree starting at the given vertex.

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

	directed_graph<T> reverse_graph(); // Reverse a graph	
};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T>
directed_graph<T>::directed_graph() 
{
	number_of_edges = 0;
	number_of_vertices = 0;
	matrix(20); // Create Matrix
}

template <typename T>
directed_graph<T>::~directed_graph() {}

template <typename T>
T directed_graph<T>::adjacent_matrix(int u_id, int v_id)
{
	// Return adjacent matrix
	return adj_matrix[u_id][v_id]; 
}

template <typename T>
vertex<T> directed_graph<T>::get_vertex(const int& u_id) 
{
	// Return vertex lsit
	return vertex_list[u_id]; 
}

template <typename T>
void directed_graph<T>::print()
{
	for(unsigned i=0; i<number_of_vertices; i++)
   	{
        for(unsigned j=0; j<number_of_vertices; j++)
            cout<< adj_matrix[i][j] << " ";
        cout << "\n";
   	} 
}

template <typename T>
void directed_graph<T>::print_list()
{
	for(int i=0; i<number_of_vertices; i++) 
	{
      cout << i << " ---> ";
      for (auto it : adj_list[i])
	  {
         cout << it.first << " ---> ";
      }
      cout << endl;
   }
}

template <typename T>
void directed_graph<T>::matrix(const int& size)
{
	adj_matrix.resize(size+1); // Create Matrix
	for(unsigned i=0; i<size+1; i++) // Create Row
	{
		adj_matrix[i].resize(size+1);
		for(unsigned j=0; j<size+1; j++) // Create Collumn
		{
			adj_matrix[i][j] = 0;
		}
	}			
}

template <typename T>
bool directed_graph<T>::visited(const int& size)
{
	bool visited[size];
	for(unsigned i=0; i<size; i++)
	{
		visited[i] = false;
	}
	return visited;
}

template <typename T> 
int directed_graph<T>::get_index(const int &u_id) const 
{
    for (unsigned i=0;i<number_of_vertices; i++) 
	{ 
        if (vertex_list[i].id==u_id) //If vertex in the vector is equal to the given vertex,
            return i; //Return the position of the vertex in the vector i.e. index
    }
    return -1; //Default return statement if it doesnt work
}

template <typename T>
bool directed_graph<T>::contains(const int& u_id) const 
{ 
	for(vertex<T> v: vertex_list)
	{
		if(v.id == u_id) // Checks if the vertex exists in the vector
		{
			return true;
		}
	}
	return false;
}

template <typename T>
bool directed_graph<T>::adjacent(const int& u_id, const int& v_id) const 
{ 
	if(adj_matrix[get_index(u_id)][get_index(v_id)]!=0) // if matrix has value and not equals to zero means that it is adjacent
	{
		return true;
	}
	return false;
}

template <typename T>
void directed_graph<T>::add_vertex(const vertex<T>& u) 
{
	if(!contains(u.id))
	{
		vertex_list.push_back(u); // Push vertex to vertex list
		number_of_vertices++; // increase number of vertex
	}
}

template <typename T>
void directed_graph<T>::add_edge(const int& u_id, const int& v_id, const T& weight) 
{
	int u = get_index(u_id);
	int v = get_index(v_id);
	if(adj_matrix[u][v]==0 & weight!=0 && u!=v) // Matrix with value zero, weight not equal to zero and not loop to itself
	{
		adj_matrix[u][v] = weight;
		number_of_edges++; // Increase number of edges
	}
}


template <typename T>
size_t directed_graph<T>::num_vertices() const { return number_of_vertices; }

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() { return vertex_list; }

template <typename T>
directed_graph<T> directed_graph<T>::reverse_graph()
{
	// Create reverse graph
	directed_graph<T> reverse; 

	// Insert every vertex to reverse graph
	for(auto i : vertex_list) {
		reverse.add_vertex(i);
	}

	// Insert every edge value to reverse graph
	for(auto i : vertex_list) 
	{
		for(auto j : vertex_list) 
		{
			int u_id = get_index(i.id);
			int v_id = get_index(j.id);
			if(adj_matrix[u_id][v_id]!=0) 
			{
				reverse.add_edge(j.id, i.id, adj_matrix[u_id][v_id]); 
			}
		}
	}
	return reverse;
}

#endif