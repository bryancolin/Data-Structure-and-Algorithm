#include "directed_graph.h"
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 

int main() {
	
    vertex<int> v1(0, 800); //A 1
    vertex<int> v2(1, 3000); //B 2
    vertex<int> v3(2, 400); //C 3
    vertex<int> v4(3, 710); //D 4     
    vertex<int> v5(4, 221); //E 5     
    vertex<int> v6(5, 800); //A 1     
    vertex<int> v7(6, 3000); //B 2 
    /*    
    vertex<int> v8(8, 400); //C 3     
    vertex<int> v9(9, 710); //D 4     
    vertex<int> v10(10, 221); //E 5     
    vertex<string> v11(1, "vertex1");     
    vertex<string> v22(2, "vertex2");     
    vertex<string> v33(3, "vertex3");     
    vertex<string> v44(4, "vertex4");*/      
    directed_graph<int> g;      
    int A = v1.id;     
    int B = v2.id;     
    int C = v3.id;     
    int D = v4.id;     
    int E = v5.id; 
    int F = v6.id;
    int G = v7.id;

// Add vertex     
    cout << "Add A" << endl;     
    g.add_vertex(v1);    
    cout << "Add B" << endl;     
    g.add_vertex(v2);     
    cout << "Add C" << endl;    
    g.add_vertex(v3);     
    cout << "Add D" << endl;     
    g.add_vertex(v4);     
    cout << "Add E" << endl;     
    g.add_vertex(v5);     
    cout << "Add F" << endl;     
    g.add_vertex(v6);     
    cout << "Add G" << endl;     
    g.add_vertex(v7);      
    cout << endl;  

//Contain     
    cout << "Contain A: " << g.contains(A) <<endl;     
    cout << "Contain B: " << g.contains(B) <<endl;     
    cout << "Contain C: " << g.contains(C) <<endl;     
    cout << "Contain D: " << g.contains(D) <<endl;     
    cout << "Contain E: " << g.contains(E) <<endl;     
    cout << "Contain J: " << g.contains(10) << endl;    
    cout << endl;  
    
// Add Edge     
    cout << "Add Edge A and B" << endl;     
    g.add_edge(A, B, 6);     
    //g.add_edge(B, A, 6);     
    //g.add_edge(A, D, 1);     
    //g.add_edge(A, E, 1);     
    cout << "Add Edge A and C" << endl;     
    g.add_edge(A, C, 9);     
    //g.add_edge(C, A, 9);     
    cout << "Add Edge B and E" << endl;     
    g.add_edge(B, E, 3);    
    //g.add_edge(B, F, 4);   
    //g.add_edge(B, C, 1);     
    //g.add_edge(E, B, 3);     
    cout << "Add Edge C and D" << endl;     
    //g.add_edge(C, B, 1);     
    g.add_edge(C, D, 4); 
    //g.add_edge(C, G, 4);     
    //g.add_edge(C, E, 1);     
    cout << "Add Edge D and A" << endl;     
    g.add_edge(D, A, 1);     
    //g.add_edge(D, B, 1);     
    cout << "Add Edge D and C" << endl;      
    g.add_edge(D, C, 7);     
    cout << "Add Edge D and E" << endl;     
    g.add_edge(D, E, 5);     
    //g.add_edge(B, D, 10);  

// Remove Vertex      
    //g.remove_vertex(E);     
    //g.remove_vertex(D);     
    //g.remove_vertex(C);     
    //g.remove_vertex(B);     
    //g.remove_vertex(A);    

// Remove Edge    
    /*g.remove_edge(A, B);     
    g.remove_edge(A, C);     
    g.remove_edge(B, E);     
    g.remove_edge(C, D);     
    g.remove_edge(D, A);     
    g.remove_edge(D, C);     
    g.remove_edge(D, E);*/  

// Adjacent      
    cout << g.adjacent(A,B) << endl;
    cout << g.adjacent(A,C) << endl;
    cout << g.adjacent(B,E) << endl;
    cout << g.adjacent(C,D) << endl;
    cout << g.adjacent(D,A) << endl;
    cout << g.adjacent(E,E) << endl;
    cout << g.get_index(A) << endl;

//Check Degree
    cout << "A degree: " << g.degree(A) << endl;
    cout << "B degree: " << g.degree(B) << endl;
    cout << "C degree: " << g.degree(C) << endl;
    cout << "D degree: " << g.degree(D) << endl;
    cout << "E degree: " << g.degree(E) << endl;
    cout << endl;

//Check In Degree
    cout << "A in-degree: " << g.in_degree(A) << endl;
    cout << "B in-degree: " << g.in_degree(B) << endl;
    cout << "C in-degree: " << g.in_degree(C) << endl;
    cout << "D in-degree: " << g.in_degree(D) << endl;
    cout << "E in-degree: " << g.in_degree(E) << endl;
    cout << endl;

//Check Out Degree
    cout << "A out-degree: " << g.out_degree(A) << endl;
    cout << "B out-degree: " << g.out_degree(B) << endl;
    cout << "C out-degree: " << g.out_degree(C) << endl;
    cout << "D out-degree: " << g.out_degree(D) << endl;
    cout << "E out-degree: " << g.out_degree(E) << endl;
    cout << endl;

// Number of Vertex and Edges
    cout << "Number of Vertex and Edges: " << g.num_vertices() << " " << g.num_edges() << endl;


// Get Vertex list
    cout << "Vertex inside the graph" << endl;
    vector<vertex<int> > get = g.get_vertices(); 
    for (vertex<int> v : get)
    {
        cout << v.id << ' ' << v.weight << endl;
    }
    cout << endl;

// Get Neighbour
    cout << "all neighbours of 0: ";
    vector<vertex<int>> neighbour_list = g.get_neighbours(A);
    for (vertex<int> snb : neighbour_list) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;

// Get Second Neighbour
    cout << "all second neighbours of 0: ";
    vector<vertex<int>> neighbour_list1 = g.get_second_order_neighbours(A);
    for (vertex<int> snb : neighbour_list1) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;


//DFS
    vector<vertex<int>> ord = g.depth_first(A);
    cout << "Depth-first order starting at 0:" << endl;
    for (vertex<int> i : ord){
        cout << i.id << ' ';
    }
    cout << endl;

//BFS
    vector<vertex<int>> ord1 = g.breadth_first(A);
    cout << "Breadth-first order starting at 0:" << endl;
    for (vertex<int> i : ord1){
        cout << i.id << ' ';
    }
    cout << endl;

// Print Matrix
    cout << endl;
    g.print();

//Out tree
    cout << endl;
    directed_graph<int> tree = g.out_tree(0);
    tree.print();

// Get Vertex list
    cout << "Vertex inside the graph" << endl;
    vector<vertex<int> > get1 = tree.get_vertices(); 
    for (vertex<int> v : get1)
    {
        cout << v.id << ' ' << v.weight << endl;
    }
    cout << endl;

    cout << tree.adjacent(A,B) << endl;
    cout << tree.adjacent(A,C) << endl;
    cout << tree.adjacent(B,E) << endl;
    cout << tree.adjacent(C,D) << endl;
    cout << tree.adjacent(D,A) << endl;
    cout << tree.adjacent(D,C) << endl;
    cout << tree.adjacent(D,E) << endl;

//Vertex and Edges
    cout << "Number of vertex and edges: " << tree.num_vertices() << " " << tree.num_edges() << endl;

// Pre Order
    directed_graph<int> tree1 = g.out_tree(0);
    vector<vertex<int>> preOrder = tree1.pre_order_traversal(0, tree1);
    cout << "PreOrder size: " << preOrder.size() << endl;
	for (auto itr = preOrder.begin(); itr != preOrder.end(); itr++)
    {
    	cout <<  "vector visited pre-order traversal :  " <<itr->id << " id and " << itr->weight << endl;
	}


// In Order
    directed_graph<int> tree3 = g.out_tree(0);
    vector<vertex<int>> inOrder = tree3.in_order_traversal(0, tree3);
    cout << "in Order size: " << inOrder.size() << endl;
	for (auto itr = inOrder.begin(); itr != inOrder.end(); itr++)
    {
    	cout <<  "vector visited in-order traversal :  " <<itr->id << " id and " << itr->weight << endl;
	}

// Post Order
    directed_graph<int> tree2 = g.out_tree(0);
    vector<vertex<int>> postOrder = tree2.post_order_traversal(0, tree2);
    cout << "PostOrder size: " << postOrder.size() << endl;
	for (auto itr = postOrder.begin(); itr != postOrder.end(); itr++)
    {
    	cout <<  "vector visited post-order traversal :  " <<itr->id << " id and " << itr->weight << endl;
	}

    directed_graph<double> g1;
    directed_graph<double> g2;

    vertex<double> c0(0, 0.25); 
    vertex<double> c1(1, 1.41);
    vertex<double> c2(2, 2.32);
    vertex<double> c3(3, 3.66);
    vertex<double> c4(4, 4.12);

    g1.add_vertex(c0);
    g1.add_vertex(c1);
    g1.add_vertex(c2);
    g1.add_vertex(c3);
    g1.add_vertex(c4);

    g2.add_vertex(c0);
    g2.add_vertex(c1);
    g2.add_vertex(c2);
    g2.add_vertex(c3);
    g2.add_vertex(c4);

    g1.add_edge(0, 2, 10);
    g1.add_edge(0, 3, 20);
    g1.add_edge(2, 0, 30);
    g1.add_edge(2, 4, 40);
    g1.add_edge(4, 0, 50);
    g1.add_edge(3, 4, 60);

    g2.add_edge(0, 2, 10);
    g2.add_edge(1, 0, 20);
    g2.add_edge(2, 1, 30);
    g2.add_edge(3, 2, 40);
    g2.add_edge(3, 4, 50);
    
    cout << "all 2nd-order neighbours of 0: ";
    vector<vertex<double>> second_neighbour_list0 = g1.get_second_order_neighbours(0);
    for (vertex<double> snb : second_neighbour_list0) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;

    cout << "all 2nd-order neighbours of 1: ";
    vector<vertex<double>> second_neighbour_list1 = g1.get_second_order_neighbours(1);
    for (vertex<double> snb : second_neighbour_list1) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;

    cout << "all 2nd-order neighbours of 2: ";
    vector<vertex<double>> second_neighbour_list2 = g1.get_second_order_neighbours(2);
    for (vertex<double> snb : second_neighbour_list2) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;

    cout << "all 2nd-order neighbours of 3: ";
    vector<vertex<double>> second_neighbour_list3 = g1.get_second_order_neighbours(3);
    for (vertex<double> snb : second_neighbour_list3) {
         cout << "(" << snb.id << ", " << snb.weight << ") ";
    }
    cout << endl;

    g.significance_sorting();

    // Contain Cycle
    cout << "Check cycle " << g.contain_cycles() << endl;
    cout << "Check cycle " << tree.contain_cycles() << endl;
}

