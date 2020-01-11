#include "simulation.h"
#include "print.h"

#include <stdio.h>

using namespace std;

void generate_vectors(float alpha, int rep, Graph& graph, string outName)
{
  // cout << "Things are okay" << endl;
  int n = graph.n;
  // int *ary = new int[sizeX*sizeY];
  float *vectors =  new float[n*n];
  cout << "Created array" << endl;
  for (int i = 0; i < n; i++) {
    // cout << "Line 12" << endl;
    vector<int> seeds;
    seeds.push_back(i); //Add ith node of graph, whose id should just be i
    // cout << "Line 15" << endl;
    simulation(seeds, alpha, rep, graph);
    // // cout << graph.prob[1] << endl; //prob[i] is the probability of i at this point
    for (int j = 0; j < n; j++) {
      // cout << graph.prob[j] << endl;
      vectors[j*n + i] = graph.prob[j];
      // vectors[j][i] = graph.prob[j]; //THIS IS THE PROBLEMATIC LINE
    }
  }
  // now write vectors to file
  // writeVectors(outName, rep, graph.n, vectors);
  writeVectors(outName, rep, graph.n, (float *)vectors);

}

void generate_large_vectors(float alpha, int rep, Graph& graph, string outName)
{
  // Write out information access vectors for a large dataset
  cout << "In large vector generator" << endl;
  int n = graph.n;

  ofstream outMin (outName);
  for (int i = 0; i < n; i++) {
    cout << "seed is " << to_string(i) << endl;
    vector<int> seeds;
    seeds.push_back(i); //Add ith node of graph, whose id should just be i
    simulation(seeds, alpha, rep, graph);
    //write probabilities to file
    for (int j = 0; j < n; j++) {
      outMin << graph.prob[j]/rep << ",";
    }
    outMin << endl;
  }
  outMin.close();
}
