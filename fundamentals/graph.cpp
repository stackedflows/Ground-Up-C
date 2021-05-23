#include <iostream>
#include <vector>

using namespace std;

class vertex {
private:
	int data;
	bool visited = false;
	vector<int> neibours;
public:
	vertex(int _data, vector<int> _neibours) {
		data = _data;
		visited = _visited;
		neibours = _neibours;
	}
	int get_data() {
		return data;
	}
	bool get_visited() {
		return visited;
	}
	void set_visited() {
		visited = true;
	}
	vector<int> get_neibours() {
		return neibours;
	}
};

class graph {
private:
	vector<vertex> verticies;
public:
	void add(vertex v) {
		verticies.push_back(v);
	}
};

int main() {
	graph g;
	vertex v0(0, false, { 1 });
	g.add(v0);
	vertex v1(1, false, { 0, 5, 4 });
	g.add(v1);
	vertex v2(2, false, { 1,3,7,6 });
	g.add(v2);
	vertex v3(3, false, { 2,8 });
	g.add(v3);
	vertex v4(4, false, { 1 });
	g.add(v4);
	vertex v5(5, false, { 1 });
	g.add(v5);
	vertex v6(6, false, { 2 });
	g.add(v6);
	vertex v7(7, false, { 2 });
	g.add(v7);
	return 0;
}
