#include <iostream>
#include <vector>

#include "directed_graph.cpp"

int main() 
{
    vertex<int> v1(0,800);
    vertex<int> v2(1,300);
    vertex<int> v3(2,400);
    vertex<int> v4(3,710);
    vertex<int> v5(4,221);
    vertex<int> v6(5,1000);
    vertex<int> v7(6,2000);
    vertex<int> v8(7,3000);

    directed_graph<int> g1;
    
    g1.add_vertex(v1);
    g1.add_vertex(v2);
    g1.add_vertex(v3);
    g1.add_vertex(v4);
    g1.add_vertex(v5);
    //g1.add_vertex(v6);
    //g1.add_vertex(v7);
    //g1.add_vertex(v8);

    int A = v1.id;
    int B = v2.id;
    int C = v3.id;
    int D = v4.id;
    int E = v5.id;
    int F = v6.id;
    int G = v7.id;
    int H = v8.id;

    vector<vertex<int>> vertex_list = g1.get_vertices();
    cout << "all vertices: ";
    for (auto vt= vertex_list.begin(); vt != vertex_list.end(); vt++){
        cout << "(" << vt->id << ", " << vt->weight << ") ";
    }
    cout << endl;

    cout << "all vertices(second version): ";
    for (auto vt1: vertex_list){
        cout << "(" << vt1.id << ", " << vt1.weight << ") ";
    }
    cout << endl;

    g1.add_edge(A,B,600);
    g1.add_edge(A,C,900);
    g1.add_edge(B,E,3000);
    g1.add_edge(C,D,4000);
    g1.add_edge(D,A,1);
    g1.add_edge(D,C,700);
    g1.add_edge(D,E,500);

    g1.print();
    
    vector<vertex<int>> topological = topological_sort(g1);
    cout << "Topological Sorting: " << endl;
    for (auto ts = topological.begin(); ts != topological.end(); ts++)
        cout << "(" << ts->id << ", " << ts->weight << ") ";
    cout << endl;

    vector<vector<vertex<int>>> stronglyConnected = strongly_connected_components(g1);
    cout << "Strongly Connected Components: " << endl;
    for (vector<vertex<int>> a : stronglyConnected) 
        for(auto b : a)
            cout << "(" << b.id << ", " << b.weight << ") ";   
    cout << endl;

    vector<vertex<int>> shortestPath = shortest_path(g1, 2, 4);
    cout << "Shortest Path: " << endl;
    for (auto sp : shortestPath)
        cout << "(" << sp.id << ", " << sp.weight << ") ";
    cout << endl;

    cout << "Low Cost Delivery from " << " :" << low_cost_delivery(g1, 0) << endl;
    cout << "Low Cost Delivery from " << " :" << low_cost_delivery(g1, 1) << endl;
    cout << "Low Cost Delivery from " << " :" << low_cost_delivery(g1, 2) << endl;
    cout << "Low Cost Delivery from " << " :" << low_cost_delivery(g1, 3) << endl;
    cout << "Low Cost Delivery from " << " :" << low_cost_delivery(g1, 4) << endl;

    directed_graph<double> g2;

}



    // cout << "\nReversing a Graph" << endl;
    // directed_graph<int> reverse = g1.reverse_graph();

    // vector<vertex<int>> vertexList = reverse.get_vertices();
    // cout << "All vertices from reverse graph: ";
    // for (auto vt= vertexList.begin(); vt != vertexList.end(); vt++){
    //     cout << "(" << vt->id << ", " << vt->weight << ") ";
    // }
    // cout << endl;

    // cout << "Print a Reverse Graph\n"; 
    // reverse.print();

    // cout << "Number of vertex: " << reverse.num_vertices() << endl;
    