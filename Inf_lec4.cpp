#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Graph {
	vector<vector<int>> adj; //список смежности графа
	int nv, ne;
};


void readGraph(Graph& G, const string namefile) {
	ifstream in;
	in.open(namefile.c_str());
	in >> G.nv;
	G.ne = 0;
	G.adj.resize(G.nv);
	int temp1, temp2;
	while(!in.eof()) {
		in >> temp1 >> temp2;
		G.adj[temp1].push_back(temp2);
		G.ne++;
	}
	in.close();
}


void printAdjGraph(Graph& G) {
	cout << "Число вершин графа: " << G.nv << endl << " Число рёбер графа: " << G.ne << endl;
	cout << "Список смежности графа: " << endl;
	for (int i = 0; i < G.nv; i++) {
		cout << i << " : ";
		for (int j = 0; j < G.adj[i].size(); j++)
			cout << G.adj[i][j] << " ";
		cout << ";" << endl;
	}

}

void printAdjMatrix(const Graph& G, const string namefile) {
	ofstream out;
	out.open(namefile.c_str());
	int* temp = new int[G.nv];
	for (int i = 0; i < G.nv; i++) {
		for (int j = 0; j < G.nv; j++)
			temp[j] = 0;
		for (int j = 0; j < G.adj[i].size(); j++)
			temp[G.adj[i][j]] = 1;
		for (int j = 0; j < G.nv; j++)
			out << temp[j] << " ";
		out << endl;
	}
	delete[] temp;
	out.close();
}


//DFS----------------------------
void RDFS(list<int> Visit, int CurrentV, Graph& G) {
	Visit.push_back(CurrentV);
	for (int i = 0; i < G.adj[CurrentV].size(); i++) {
		if (find(Visit.begin(), Visit.end(), G.adj[CurrentV][i]) == Visit.end())
			RDFS(Visit, G.adj[CurrentV][i], G);
	}

	for (auto iter = Visit.begin(); iter != Visit.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

void IDFS(list<int>& Visit, int CurrentV, Graph& G) {
	Visit.clear();
	Visit.push_back(CurrentV);
	stack<int> Ver;
	Ver.push(CurrentV);
	while (!Ver.empty()) {
		int i = 0;
		for (i = 0; i < G.adj[CurrentV].size(); i++)
			if(find(Visit.begin(), Visit.end(), G.adj[CurrentV][i]) == Visit.end()) {
			Visit.push_back(G.adj[CurrentV][i]);
			CurrentV = G.adj[CurrentV][i];
			Ver.push(CurrentV);
			break;
		}
		if(i == G.adj[CurrentV].size()) {
			CurrentV = Ver.top();
			Ver.pop();
		}
	}

	for (auto iter = Visit.begin(); iter != Visit.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}


//BFS-----------------------------

void BFS(list<int>& Visit, int CurrentV, Graph& G) {
	queue<int> Ver;
	Visit.clear();
	Visit.push_back(CurrentV);
	Ver.push(CurrentV);
	while (!Ver.empty()) {
		CurrentV = Ver.front();
		Ver.pop();
		for (int i = 0; i < G.adj[CurrentV].size(); i++) {
			if(find(Visit.begin(), Visit.end(), G.adj[CurrentV][i]) == Visit.end()) {
				Visit.push_back(G.adj[CurrentV][i]);
				Ver.push(G.adj[CurrentV][i]);
			}
		}
	}
	for (auto iter = Visit.begin(); iter != Visit.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

//Another algoritms

void SearchConnectivityComponent(vector<vector<int>>& ConnectivityComponent, Graph& G) {
	list<int> Visit, VisitAll;
	Visit.clear();
	VisitAll.clear();
	int CurrentV = 0;
	while (VisitAll.size() != G.nv) {
		IDFS(Visit, CurrentV, G);
		vector<int> temp;
		for (list<int>::iterator it = Visit.begin(); it!= Visit.end(); it++) {
			temp.push_back(*it);
			if(find(VisitAll.begin(), VisitAll.end(), *it) == VisitAll.end())
				VisitAll.push_back(*it);
		}
		ConnectivityComponent.push_back(temp);
		for (vector<int>::iterator it2 = temp.begin(); it2 != temp.end(); it2++) {
			for (vector<int>::iterator it = (ConnectivityComponent.at(distance(temp.begin(), it2))).begin(); it != (ConnectivityComponent.at(distance(temp.begin(), it2)).end()); it++) {
				cout << *it << "  "; //Получаем все числа по по порядку
			}

		}
		Visit.clear();
		while ((find(VisitAll.begin(), VisitAll.end(), CurrentV) != VisitAll.end()) && (CurrentV < G.nv))
			CurrentV++;
	}

	
	
	for (auto iter = Visit.begin(); iter != Visit.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}


int Bipartite(vector<int>& b, Graph& G) {
	int CurrentV = 0;
	int color = 1;
	b.clear();
	b.resize(G.nv);
	for (int i = 0; i < b.size(); i++)
		b[i] = 0;
	b[CurrentV] = color;
	stack<int> Ver;
	
	while (CurrentV < G.nv) {
		Ver.push(CurrentV);
		while (!Ver.empty()) {
			int i = 0;
			for (i = 0; i < G.adj[CurrentV].size(); i++) {
				int temp = G.adj[CurrentV][i];
				if(!b[temp]) {
					color = ((b[CurrentV] == 1) ? 2 : 1);
					b[temp] = color;
					CurrentV = temp;
					Ver.push(CurrentV);
					break;
				}
			}
			if(i == G.adj[CurrentV].size()) {
				CurrentV = Ver.top();
				Ver.pop();
			}
		}
		while ((CurrentV < G.nv) && (b[CurrentV])) {
			CurrentV++;
		}
	}
	for (int i = 0; i < G.nv; i++)
		for (int j = 0; j < G.adj[i].size(); j++)
			if (b[i] == b[G.adj[i][j]]) {
				cout << " Bipartite error" << endl;
				return 0;
			}
	return 1;
}


void TopologySort(list<int>& Visit, stack<int>& newOrder, int CurrentV, Graph& G) {
	Visit.push_back(CurrentV);
	for (int i = 0; i < G.adj[CurrentV].size(); i++) {
		if(find(Visit.begin(), Visit.end(), G.adj[CurrentV][i]) == Visit.end()) {
			TopologySort(Visit, newOrder, G.adj[CurrentV][i], G);
		}
	}
	newOrder.push(CurrentV);

	for (auto iter = Visit.begin(); iter != Visit.end(); iter++) { //вывод 
		cout << *iter << " ";
	}
	cout << endl;

}

void re_numberGraph(stack<int> newOrder, Graph& G) {
	vector<vector<int>> new_adj;
	vector<int> new_number(G.nv);
	int i = 0;
	while (!newOrder.empty()) {
		int temp = newOrder.top();
		cout << temp << endl;
		newOrder.pop();
		new_number[temp] = i;
		i++;
	}
	cout << "***" << endl;
	for (int i = 0; i < G.nv; i++)
		cout << new_number[i] << endl;
	new_adj.resize(G.nv);
	for (i = 0; i < G.nv; i++)
		for (int j = 0; j < G.adj[i].size(); j++)
			new_adj[new_number[i]].push_back(new_number[G.adj[i][j]]);
	G.adj.clear();
	G.adj = new_adj;
}


int main() {
	setlocale(LC_ALL, "Russian");
	Graph G;
	list<int> Visit;
	vector<vector<int>> V; //SearchConnectivityComponent
	vector<int> b; //Bipartite
	stack<int> s; //TopologySort
	string in_file, out_file;
	in_file = "Graph.txt";
	out_file = "matrix.txt";

	readGraph(G, in_file);
	printAdjGraph(G);
	printAdjMatrix(G, out_file);

	cout << "RDFS: " << endl;
	RDFS(Visit, 0, G);
	cout << "RDFS complete." << endl;

	cout << endl;

	cout << "IDFS: " << endl;
	IDFS(Visit, 0, G);
	cout << "IDFS complete." << endl;
	
	cout << endl;

	cout << "BFS: " << endl;
	BFS(Visit, 0, G);
	cout << "BFS complete." << endl;
	
	cout << endl;

	cout << "SearchConnectivityComponent: " << endl;
	SearchConnectivityComponent(V, G);
	cout << "SearchConnectivityComponent - complete." << endl;

	cout << endl;

	cout << "bipartite: " << endl;
	Bipartite(b, G);
	cout << "bipartite complete." << endl;

	cout << endl;

	cout << "TopoligySort: " << endl;
	TopologySort(Visit, s, 0, G);
	cout << "TopologySort - complete." << endl;



	system("pause");
	return 0;
}

