#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class vertex {
private:
	int id;
	vector<int> neibs;
	int nneibs;
public:
	bool discovered;
	vertex(int _id, vector<int> _neibs, int _nneibs) {
		id = _id;
		neibs = _neibs;
		nneibs = _nneibs;
		discovered = false;
	}
	int get_id() {
		return id;
	}
	vector<int> get_neibs() {
		return neibs;
	}
	int get_nneibs() {
		return nneibs;
	}
};

class graph {
private:
	int count = 0;
public:
	vector<vertex*> vertices;
	void add(int id, vector<int> neibs, int nneibs) {
		vertex* v = new vertex(id, neibs, nneibs);
		vertices.push_back(v);
		count++;
	}
	int get_count() {
		return count;
	}
};

void dfs(graph g, vertex * v) {
	cout << v->get_id() << ' ';
	v->discovered = true;
	int nneibs = v->get_nneibs();
	vector<int> neibs = v->get_neibs();
	for (int i = 0; i < nneibs; i++) {
		int curr = neibs[i];
		vertex* cv = g.vertices[curr];
		if (cv->discovered == false) {
			return dfs(g, cv);
		}
	}
}

void bfs(graph g, vertex* root){
	queue<vertex*> q;
	root->discovered = true;
	q.push(root);
	while (q.size() > 0) {
		vertex* v = q.front();
		cout << v->get_id() << ' ';
		q.pop();
		vector<int> neibs = v->get_neibs();
		for (int i = 0; i < v->get_nneibs(); i++) {
			vertex* k = g.vertices[neibs[i]];
			if (k->discovered == false) {
				k->discovered = true;
				q.push(k);
			}
		}
	}
	cout << endl;
}

int main() {
	graph g;
	g.add(0, { 1, 2 }, 2);
	g.add(1, { 0, 3, 4 }, 3);
	g.add(2, { 1, 5, 6 }, 3);
	g.add(3, { 1 }, 1);
	g.add(4, { 1, 7 }, 1);
	g.add(5, { 2 }, 1);
	g.add(6, { 2 }, 1);
	g.add(7, { 4 }, 1);

	/*
	 	for (int i = 0; i < g.get_count(); i++) {
			if (g.vertices[i]->discovered == false) {
				dfs(g, g.vertices[i]);
			}
		}
	*/

	bfs(g, g.vertices[0]);

	return 0;
}
