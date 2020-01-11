// -*- c-basic-offset: 4 -*-

// Simulate the spread of information over network
// Also outputs the results

#ifndef simulation_h
#define simulation_h

// #include <vector> //#include <time.h> //#include "graph.cpp"
// #include "computation.h"
#include <fstream>
#include <math.h>
#include <queue>

using namespace std;

struct simRes {
    int node;
    float minPr;
    float minWeight;
    int minGroup;
    int nodeW;
    float minPrW;
    float minWeightW;
    int minGroupW;
    int rep;
    float avePr;
};

simRes simulation(vector<int>& seeds, float alpha, int rep, Graph &graph) {
    //srand(static_cast<unsigned int>(time(NULL)));
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_real_distribution<> distr(0.0f, 1.0f);

    const int numV = graph.n;
    int k = int(seeds.size());
    for(int i = 0; i < numV; i++)
        graph.prob[i] = 0;
    for(int i = 0; i < k; i++)
        graph.prob[seeds[i]] = rep;

    bool* isOn = new bool [numV];
    vector<int> onNodes;  // Infected nodes this round
    /*int* hitTime = new int [numV]{}; // Hit time of nodes for each round
     int rounds, lastNode;*/

    // Run simulation for each repetitio
    for (int simRound = 0; simRound < rep; simRound++) {
        memset(isOn, 0, numV);
        for (int i = 0; i < k; i++)
            isOn[seeds[i]] = true;

        onNodes = seeds;
        // for (int i = 0; i < k; i++)
        //     onNodes.push_back(seeds[i]);

        /*rounds = 1;
         lastNode = onNodes.back();*/

        // Runs until no new node gets infected
        for (auto node: onNodes) {
            vector<int> next;
            // while (!onNodes.empty()) {
            for (auto id: graph.neighbors[node]) { 
                if (isOn[id])
                    continue;
                if (distr(generator) <= alpha) {
                    isOn[id] = true;
                    graph.prob[id] += 1;
                    next.push_back(id);
                }
            }
            // onNodes.pop();
            swap(onNodes, next);
        }
    }

    int minim = 0;
    for(int v = 0; v < numV; v++)
        if(graph.prob[minim] > graph.prob[v])
            minim = v;

    int minimW = 0;
    for(int v = 0; v < numV; v++)
        if(float(graph.prob[minimW])/pow(graph.weight[minimW],2) > float(graph.prob[v])/pow(graph.weight[v],2))
            minimW = v;

    // In case "Average" is needed
    float ave = 0;
    for(int v = 0; v < numV; v++)
        ave += float(graph.prob[v] / rep);
    ave /= numV;

    float minP = float(graph.prob[minim]) / rep;
    float minW = graph.weight[minim];
    int minG = graph.group[minim];

    float minWP = float(graph.prob[minimW]) / rep;
    float minWW = graph.weight[minimW];
    int minWG = graph.group[minimW];

    simRes result = {minim, minP, minW, minG, minimW, minWP, minWW, minWG, rep, ave};

    delete[] isOn;
    // swap(onNodes, empty);
    /*delete[] hitTime;*/

    return result;
}

#endif /* simulation_h */
