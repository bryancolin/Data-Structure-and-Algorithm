#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MyStruct
{
  int key;
  string data;
  MyStruct(int key, string data)
  {
    this->key = key;
    this->data = data;
  }
};

struct Vertex
{
  int id;
  int weight;
  Vertex(int x, int y) : id(x), weight(y)
  {
  }
};

int main()
{
  vector<MyStruct> vec;
  vec.push_back(MyStruct(4, "test"));
  vec.push_back(MyStruct(2, "is"));
  vec.push_back(MyStruct(3, "a"));
  vec.push_back(MyStruct(1, "this"));

  // Using lambda expressions in C++11
  sort(vec.begin(), vec.end(), [](const MyStruct &lhs, const MyStruct &rhs) {
    return lhs.key < rhs.key;
  });
  
  for (auto it = vec.begin(); it != vec.end(); it++)
  {
    cout << it->data << endl;
  }

  Vertex v1(1, 800);  //A 1
  Vertex v2(0, 3000); //B 2
  Vertex v3(2, 5000); //C 3
  Vertex v4(3, 710);  //D 4
  Vertex v5(4, 221);  //E 5

  vector<Vertex> v;
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  v.push_back(v5);

  // Using lambda expressions in C++11
  sort(v.begin(), v.end(), [](const Vertex &lhs, const Vertex &rhs) {
    return lhs.id < rhs.id;
  });

  for (auto it = v.begin(); it != v.end(); it++)
  {
    cout << it->id << " " << it->weight << endl;
  }
}