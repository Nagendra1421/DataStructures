/**
* Author- Nagendra Singh
* Date- 24/07/2018
*/
#pragma once
#include<set>
namespace GraphData{
    template<class Type>
    class Graph{
        private:
        static const int MAXIMUM=20;
        bool adjacencyMatrix [MAXIMUM][MAXIMUM];
        Type labels[MAXIMUM];
        int manyVertices;
        public:
        Graph();
        ~Graph();
        void addVertex(const Type& value);
        void addEdge(int source,int target);
        void removeEdge(int source,int target);
        Type& operator [] (int vertex);
        Type operator [](int vertex) const;
        int size();
        bool isEdge(int source,int target) const;
        std::set<int> neighbors(int vertex) const;

    };
}