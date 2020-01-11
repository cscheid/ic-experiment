// -*- c-basic-offset: 4 -*-

// Network Data Structure

#include <iostream>
#include <random>
#include <vector>

using namespace std;

// // Adjacency List Node
// struct AdjListNode {
//     int id;
//     struct AdjListNode* next;
// };

// // Adjacency List
// struct AdjList {
//     struct AdjListNode *head;
// };

// Class Graph
class Graph {
public:
    int n;
    vector<int> degree, in_degree;
    vector<int> prob, group;
    vector<float> weight;

    vector<vector<int> > neighbors;

    Graph() {}
    Graph(const Graph &other):
            n(other.n),
            degree(other.degree),
            in_degree(other.degree),
            prob(other.prob),
            group(other.group),
            weight(other.weight),
            neighbors(other.neighbors)
    {
    }
    
    explicit Graph(int n):
            n(n),
            degree(n, 0),
            in_degree(n, 0),
            prob(n, 0),
            group(n, 1),
            weight(n, 1.0f),
            neighbors(n)
    {}
        // this->n = n;
        // degree = new int [n];
        // in_degree = new int [n];
        // prob = new int [n];
        // weight = new float [n];
        // group = new int [n];
        // thresh = new int [n];
        // neighbors = new AdjList [n];
        // for (int i = 0; i < n; ++i) {
        //     degree[i] = in_degree[i] = prob[i] = 0;
        //     weight[i] = 1;
        //     group[i] = 1;
        //     //thresh[i] = 1;
        //
    
    // void setRand() {
    //     //srand(static_cast<unsigned int>(time(NULL)));
    //     random_device rand_dev;
    //     mt19937 generator(rand_dev());
    //     uniform_int_distribution<int> distrW(0, INT_MAX);
    //     uniform_int_distribution<int> distrG(0, 1);
    //     for (int i = 0; i < n; ++i) {
    //         weight[i] = (float) distrW(generator)/INT_MAX;
    //         group[i] = distrG(generator);
    //         uniform_int_distribution<int> distrT(0, in_degree[i]);
    //         //thresh[i] = (int) distrT(generator); // Thresh = 0 or d_i?
    //     }
    // }
    
    void addEdge(int src, int dest, bool dir) {
        degree[src]++;
        in_degree[dest]++;
        neighbors[src].push_back(dest);

        if (dir) { return; }
        degree[dest]++;
        neighbors[dest].push_back(src);
    }
    
    void printGraph() {
        for (int v = 0; v < n; ++v) {
            cout << "Vertex " << v << ":";
            for (auto it: neighbors[v]) {
                cout << " " << it;
            }
            cout << endl;
            // AdjListNode* iter = neighbors[v].head;
            // cout << "Vertex " << v << ":";
            // while (iter) {
            //     cout << " " << iter->id;
            //     iter = iter->next;
            // }
            // cout << endl;
        }
    }
};
