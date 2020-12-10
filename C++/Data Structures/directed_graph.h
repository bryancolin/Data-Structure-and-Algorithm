#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

// include more libraries here if you need to

using namespace std; // the standard namespace are here just in case.

/*
	the vertex class
*/
template <typename T>
class vertex {

public:
	int id;
	T weight;
	//struct vertex *left;
    //struct vertex *right;
	vertex(int x, T y) : id(x), weight(y) 
	{
		//this->left = NULL;
        //this->right = NULL;
	}

	// add more functions here if you need to
};

/*
	the graph class
*/
template <typename T>
class directed_graph {

private:

	vector<vector<T> > adj_matrix; // Matrix
	//vector<vector<T> > adj_list; // List
	vector<vertex<T>> vertex_list; // Vertex List
	size_t number_of_vertices; // Number of vertices
	size_t number_of_edges; // Number of edges

public:

	directed_graph(); //A constructor for directed_graph. The graph should start empty.
	~directed_graph(); //A destructor. Depending on how you do things, this may not be necessary.

	void print(); // Print Matrix
	void matrix(const int&); // Create Matrix
	void convert(); // Convert matrix to list 

	int get_index(const int&) const; //Method to get the integer index value of the vertices
	bool contains(const int&) const; //Returns true if the graph contains the given vertex_id, false otherwise.
	bool adjacent(const int&, const int&) const; //Returns true if the first vertex is adjacent to the second, false otherwise.

	void add_vertex(const vertex<T>&); //Adds the passed in vertex to the graph (with no edges).
	void add_edge(const int&, const int&, const T&); //Adds a weighted edge from the first vertex to the second.

	void remove_vertex(const int&); //Removes the given vertex. Should also clear any incident edges.
	void remove_edge(const int&, const int&); //Removes the edge between the two vertices, if it exists.

	size_t in_degree(const int&) const; //Returns number of edges coming in to a vertex.
	size_t out_degree(const int&) const; //Returns the number of edges leaving a vertex.
	size_t degree(const int&) const; //Returns the degree of the vertex (both in edges and out edges).

	size_t num_vertices() const; //Returns the total number of vertices in the graph.
	size_t num_edges() const; //Returns the total number of edges in the graph.

	vector<vertex<T>> get_vertices(); //Returns a vector containing all the vertices.
	vector<vertex<T>> get_neighbours(const int&); //Returns a vector containing all the vertices reachable from the given vertex. The vertex is not considered a neighbour of itself.
	vector<vertex<T>> get_second_order_neighbours(const int&); // Returns a vector containing all the second_order_neighbours (i.e., neighbours of neighbours) of the given vertex.
															  // A vector cannot be considered a second_order_neighbour of itself.
	bool reachable(const int&, const int&) ; //Returns true if the second vertex is reachable from the first (can you follow a path of out-edges to get from the first to the second?). Returns false otherwise.
	bool isCyclic(const int&, bool[], bool[]) const;
	bool contain_cycles() const; // Return true if the graph contains cycles (there is a path from any vertices directly/indirectly to itself), false otherwise.

	vector<vertex<T>> depth_first(const int&); //Returns the vertices of the graph in the order they are visited in by a depth-first traversal starting at the given vertex.
	vector<vertex<T>> breadth_first(const int&); //Returns the vertices of the graph in the order they are visisted in by a breadth-first traversal starting at the given vertex.

	directed_graph<T> out_tree(const int&); //Returns a spanning tree of the graph starting at the given vertex using the out-edges. This means every vertex in the tree is reachable from the root.

	vector<vertex<T>> pre_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of a pre-order traversal of the minimum spanning tree starting at the given vertex.
	void in_order_tranversal_helper(int, vector<vector<T> > , bool[], vector<vertex<T>>&);
	bool child(const int&); 
	vector<vertex<T>> in_order_traversal(const int&, directed_graph<T>&); // returns the vertices in the visiting order of an in-order traversal of the minimum spanning tree starting at the given vertex.
	vector<vertex<T>> post_order_traversal(const int&, directed_graph<T>&); // returns the vertices in ther visitig order of a post-order traversal of the minimum spanning tree starting at the given vertex.

	vector<vertex<T>> significance_sorting(); // Return a vector containing a sorted list of the vertices in descending order of their significance.

};

// Define all your methods down here (or move them up into the header, but be careful you don't double up). If you want to move this into another file, you can, but you should #include the file here.
// Although these are just the same names copied from above, you may find a few more clues in the full method headers.
// Note also that C++ is sensitive to the order you declare and define things in - you have to have it available before you use it.

template <typename T>
directed_graph<T>::directed_graph() 
{
	number_of_vertices = 0; // Set number of vertex to zero
	number_of_edges = 0; // Set number of edges to zero
	matrix(20); // Create Matrix
}

template <typename T>
directed_graph<T>::~directed_graph() {}

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
void directed_graph<T>::convert() 
{ 
	vector<vector<T> > adj_list(adj_matrix.size());
    for (int i = 0; i < adj_matrix.size(); i++) 
    { 
        for (int j = 0; j < adj_matrix.size(); j++) 
        { 
            if (adj_matrix[i][j] != 0) 
            { 
                adj_list[i].push_back(j); 
            } 
        } 
    } 

	for (int i = 0; i < adj_list.size(); i++) 
    { 
        cout << i; 
        for(int j = 0; j < adj_list[i].size(); j++) 
        { 
            if(j == adj_list[i].size() - 1) 
            { 
                cout << " -> " << adj_list[i][j] << endl; 
                break; 
            } 
            else
                cout << " -> " << adj_list[i][j]; 
        } 
    } 
} 

template <typename T> 
int directed_graph<T>::get_index(const int &u_id) const 
{
    for (unsigned i=0;i<vertex_list.size(); i++) 
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
void directed_graph<T>::remove_vertex(const int& u_id) 
{
	int index = get_index(u_id);
	if(contains(u_id))
	{
		for(int i=0; i<vertex_list.size(); i++) // Remove Incident Edge
		{
			remove_edge(index,i);
			remove_edge(i,index);
		}
		vertex_list.erase(vertex_list.begin() + index); // Find and Delete vertex from the vector
		number_of_vertices--; // Decrease number of vertex	
	}
}

template <typename T>
void directed_graph<T>::remove_edge(const int& u_id, const int& v_id) 
{
	int u = get_index(u_id);
	int v = get_index(v_id);
	if(adj_matrix[u][v]!=0)
	{
		adj_matrix[u][v] = 0; // Make the edge ZERO
		number_of_edges--; // Decrease the number of edge
	}
}

template <typename T>
size_t directed_graph<T>::in_degree(const int& u_id) const 
{ 
	size_t degree = 0;
	for(unsigned i=0; i<adj_matrix.size(); i++) // Iterate to matrix size
	{
		if(u_id>=0 && adj_matrix[i][get_index(u_id)]!=0) 
		{
			++degree;
		}	
	}
	return degree; 	
}

template <typename T>
size_t directed_graph<T>::out_degree(const int& u_id) const 
{ 
	size_t degree = 0;
	for(unsigned i=0; i<adj_matrix.size(); i++) // Iterate to matrix size
	{
		if(u_id>=0 && adj_matrix[get_index(u_id)][i]!=0)
		{
			++degree;
		}	
	}
	return degree; 	
}

template <typename T>
size_t directed_graph<T>::degree(const int& u_id) const { return out_degree(u_id) + in_degree(u_id); }

template <typename T>
size_t directed_graph<T>::num_vertices() const { return number_of_vertices; }

template <typename T>
size_t directed_graph<T>::num_edges() const { return number_of_edges; }

template <typename T>
vector<vertex<T>> directed_graph<T>::get_vertices() { return vertex_list; }

template <typename T>
vector<vertex<T>> directed_graph<T>::get_neighbours(const int& u_id) 
{
	vector<vertex<T>> neighbour;
	int u = get_index(u_id);
	for(unsigned i=0; i<number_of_vertices; i++) // Iterate the matrix to check if there is neighbour of u_id
	{
		if(adj_matrix[u][i]!=0 && u!=i)  // if there is neighbour
		{
			neighbour.push_back(vertex_list[i]); // then push it to the vector
		}
	} 
	
	return neighbour; 
}

template <typename T>
vector<vertex<T>> directed_graph<T>::get_second_order_neighbours(const int& u_id) 
{ 
	//vector<vertex<T>> neighbour = get_neighbours(get_index(u_id)); 
	vector<vertex<T>> secondNeighbour; //Create a vector which stores the second neighbours of a vertex
	vector<bool> visited(number_of_vertices);//visited nodes

	for (unsigned i = 0; i < number_of_vertices; i++)
	{
    	visited[i] = false;
	}
	
    for (unsigned i = 0; i < number_of_vertices; i++) // Iterate the matrix to check first neigbour
	{
        if (adj_matrix[get_index(u_id)][i]!=0) // if there is first neighbour
		{ // check for neighbour
    		for (unsigned j = 0; j < number_of_vertices; j++) // Iterate the matrix to check for second neighbour
		 	{
                if ((adj_matrix[i][j])!=0 && !(visited[j]) && get_index(u_id)!=j)  // if adjacent, not visited and not adjacent to itself
				{
					secondNeighbour.push_back(vertex_list[get_index(j)]);
                	visited[j]=true;
            	}
	       	}
     	}
	}

	return secondNeighbour;
}

template <typename T>
bool directed_graph<T>::reachable(const int& u_id, const int& v_id)  
{ 
	directed_graph<T> reachable_tree = out_tree(u_id); // Create a spanning tree
	return (reachable_tree.contains(v_id)?true:false); //If the spanning tree contains vertex 'v', return true otherwise return false.
}

template <typename T>
bool directed_graph<T>::isCyclic(const int& i, bool visited[], bool onStack[]) const
{
	if(!visited[i])
	{
		visited[i] = true;
		onStack[i] = true;

		for(unsigned j=0 ; j<vertex_list.size(); j++)
			if(adj_matrix[i][j]!=0)
				if(!visited[j] && isCyclic(j, visited, onStack))
					return true;
				else if(onStack[j])
					return true;
	}
	onStack[i] = false;
	return false;
}

template <typename T>
bool directed_graph<T>::contain_cycles() const 
{
	bool visited[number_of_vertices];
	bool onStack[number_of_vertices];

	for(unsigned i=0; i<vertex_list.size(); i++)
	{
		visited[i] = false;
		onStack[i] = false;
	}

	for(unsigned i=0; i<vertex_list.size(); i++)
		if(isCyclic(i, visited, onStack))
			return true;
		
	return false;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::depth_first(const int& u_id) 
{ 
	bool visited[number_of_vertices]; // create every vertex unvisited

    for(unsigned i=0; i<number_of_vertices; i++)
    {
        visited[i] = false;
    }

    stack<vertex<T>> unprocessed; // create a stack
    unprocessed.push(vertex_list[get_index(u_id)]); // push the first vertex to the stack

    vector<vertex<T>> ordered; // create vector to store the visited vertex

    while(!unprocessed.empty())
    {
        vertex<T> current = unprocessed.top(); // make the current top of the stack
        unprocessed.pop(); // then pop it

        if(!visited[get_index(current.id)])
        {
            visited[get_index(current.id)] = true; // make the current vertex visited
            ordered.push_back(current); // and push it to vector 

            for(unsigned i=number_of_vertices; i!=0; i--)
            {
                if(adj_matrix[get_index(current.id)][i-1]!=0) // go to the neigbour 
                {
                    unprocessed.push(vertex_list[i-1]); // push it to the stack
                }
            }
        }
    }
	
    return ordered; // return the vector of every visited vertex	
}

template <typename T>
vector<vertex<T>> directed_graph<T>::breadth_first(const int& u_id) 
{
	bool visited[number_of_vertices]; // create every vertex unvisited

    for(unsigned i=0; i<number_of_vertices; i++) 
    {
        visited[i] = false;
    }

    queue<vertex<T>> unprocessed; 
    unprocessed.push(vertex_list[get_index(u_id)]); // push the first vertex to the queue 

    vector<vertex<T>> ordered; // create vector to store the visited vertex

    while(!unprocessed.empty())
    {
        vertex<T> current = unprocessed.front(); // make the current become front vertex
        unprocessed.pop(); // then pop it

        if(!visited[get_index(current.id)])
        {
            visited[get_index(current.id)] = true; // make it visited 
            ordered.push_back(current); // then push it to the vector 

            for(unsigned i=0; i<number_of_vertices; i++)
            {
                if(adj_matrix[get_index(current.id)][i]!=0) // go to the next neighbour 
                {
                    unprocessed.push(vertex_list[i]); // push it to queue
                }
            }
        }
    }
	
    return ordered; // return the vector of every visited vertex 
}

template <typename T>
directed_graph<T> directed_graph<T>::out_tree(const int& u_id) 
{ 
	directed_graph<T> tree;
	bool visited[number_of_vertices];

	for(unsigned i=0; i<number_of_vertices; i++)
	{
		visited[i] = false;
	}

	int u = get_index(u_id);
	queue<pair< vertex<T>, vertex<T> >> unprocessed; // create a queue
	unprocessed.push({vertex_list[u], vertex_list[u]}); // push the first queue

	while(!unprocessed.empty())
	{
		pair<vertex<T>,vertex<T>> n = unprocessed.front(); // make the n the front 
		unprocessed.pop(); // then pop it

		if(!visited[get_index(n.first.id)]) 
		{
			visited[get_index(n.first.id)] = true; // make the first vertex visited
			tree.add_vertex(n.first); // add the first visited vertex 
			tree.add_edge(n.second.id, n.first.id, 1); // add edge between the second and the first edge
			
			for(unsigned i=0; i<number_of_vertices; i++)
			{
				if(adj_matrix[get_index(n.first.id)][i]!=0 && !visited[i])
				{
					unprocessed.push({vertex_list[i],n.first}); // push to the queue
				} 
			}
		}
	}

	return tree;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::pre_order_traversal(const int& u_id, directed_graph<T>& mst) 
{ 
	bool visited[number_of_vertices]; // make every vertex visited false
	for(unsigned i=0; i<number_of_vertices; i++)
	{
		visited[i] = false;
	}

	int u = get_index(u_id);
	stack<vertex<T>> unprocessed; // create a stack
    unprocessed.push(vertex_list[get_index(u_id)]); // push the first vertex to the stack
	vector<vertex<T> > ordered; // create a vector to store all of the visited vertex

	while (!unprocessed.empty())
    {
        vertex<T> current = unprocessed.top(); // make the current top
		unprocessed.pop(); // then pop it
        if(!visited[get_index(current.id)])
        {
            visited[get_index(current.id)] = true; // make it visited 
            ordered.push_back(current); // then push it to the vector 

            for(unsigned i=number_of_vertices; i!=0; i--)
            {
                if(adj_matrix[get_index(current.id)][i-1]!=0) // go to the neigbour 
                {
                    unprocessed.push(vertex_list[i-1]); // push it to the stack
                }
            }
        }
    }
	return ordered;
}


template <typename T>
bool directed_graph<T>::child(const int& u_id) 
{
	for(unsigned i=0; i<number_of_vertices; i++)
	{
		if(adj_matrix[u_id][i]!=0 && u_id!=i)
		{
			return true;
		}
	} 
	return false;
}

template <typename T>
void directed_graph<T>::in_order_tranversal_helper(int u_id, vector<vector<T>> adj_matrix, bool visited[], vector<vertex<T>>& ordered_vector)
{
	if(!child(u_id)) // if no child means it is the leaves 
	{
		if(!visited[u_id])
		{
			ordered_vector.push_back(vertex_list[u_id]); //push the child in
			visited[u_id] = true; // make it visited
		}
	}
	for(unsigned i =0; i<number_of_vertices; i++) // start iterate from root
	{
		if(adj_matrix[u_id][i]) // if adjacent/ edge between vertices
		{
			if(!visited[i]) // make it visited
			{
				in_order_tranversal_helper(i, adj_matrix, visited, ordered_vector); // recurse again from parent to child ( or till no child left)

				if(!visited[u_id])
				{
					ordered_vector.push_back(vertex_list[u_id]);
					visited[u_id] = true;
				}
			}
		}
	}
}

template <typename T>
vector<vertex<T>> directed_graph<T>::in_order_traversal(const int& u_id, directed_graph<T>& mst) 
{ 
	bool visited[number_of_vertices];
	for(unsigned i=0; i<number_of_vertices; i++)
	{
		visited[i] = false;
	}
	vector<vertex<T>> ordered; // create a vector

	in_order_tranversal_helper(get_index(u_id), adj_matrix, visited, ordered);
	
    return ordered; // return the vector of every visited vertex
}

template <typename T>
vector<vertex<T>> directed_graph<T>::post_order_traversal(const int& u_id, directed_graph<T>& mst) 
{ 
	bool visited[number_of_vertices];
	for(unsigned i=0; i<number_of_vertices; i++)
	{
		visited[i] = false;
	}

	stack<vertex<T>> stack1; // create stack 1
    stack1.push(vertex_list[get_index(u_id)]); // push the first vertex to the stack
	//stack<vertex<T>> stack2; // create stack 2
	vector<vertex<T>> ordered; // to store the stack2 vertex to vector

	while (!stack1.empty())
    {
        vertex<T> current = stack1.top(); // make the top stack 1,current node
		stack1.pop(); // then pop it
		//stack2.push_back(current);
		ordered.push_back(current); // put it the current node on vector
        if(!visited[get_index(current.id)])
        {
            visited[get_index(current.id)] = true; // make it visited 
            for(unsigned i=0; i<number_of_vertices; i++)
            {
                if(adj_matrix[get_index(current.id)][i]!=0) // go to the next neighbour 
                {
                    stack1.push(vertex_list[i]); // push it to the stack 1
                }
            }
        }
    }

	reverse(ordered.begin(), ordered.end()); // reversed the ordered vector
/*
	while(!stack2.empty())
	{
    	vertex<T> w = stack2.top(); // the top of the stack2
    	ordered.push_back(w); // and push it to vector
    	stack2.pop(); // the pop it till empty
	}*/
	
	return ordered;
}

template <typename T>
vector<vertex<T>> directed_graph<T>::significance_sorting() 
{ 	
	vector<vertex<T>> v = vertex_list;

	sort(v.begin(), v.end(), [](vertex<T>& lhs, vertex<T>& rhs) { // SORTING USING LAMBDA EXPRESSION
      return lhs.weight > rhs.weight;
  	});

	//T n = sizeof(u)/sizeof(u[0]); 

	//qsort(u.begin(), u.end()); 
	/*
	for (auto S = u.begin(); S != u.end(); S++)
  	{
    	cout << S->id << " " << S->weight << endl;
  	}
	*/
	return v; 
}

#endif