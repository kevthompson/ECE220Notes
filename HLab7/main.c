#include "graph.h"
int main(int argc, char *argv[])
{
   readNodeFile("nodes.txt");
   readEdgeFile("edges.txt");
   bellmanford(argv[1], argv[2]);
}
