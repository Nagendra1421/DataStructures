#include "../Headers/Header.h"

using namespace GraphData;

template <class Type>
const int Graph<Type>::MAXIMUM;

template<class Type>
void Graph<Type>::addVertex(const Type& value){
    assert(size()<MAXIMUM);
    int newVertexNumber=manyVertices;
    manyVertices++;
    for(int otherVertexNumber=0;otherVertexNumber<manyVertices;otherVertexNumber++){
        adjacencyMatrix[otherVertexNumber][newVertexNumber]=false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber]=false;
    }
    labels[newVertexNumber]=value;
}

template<class Type>
void Graph<Type> ::addEdge(int source,int target){
    assert(source<size() && target <size());
    adjacencyMatrix[source][target]=true;
}

template<class Type>
bool Graph<Type>::isEdge(int source,int target) const{
    assert(source<size() && target<size());
    bool isAnEdge=false;
    isAnEdge=adjacencyMatrix[source][target];
    return isAnEdge;
}

template<class Type>  // This Require if we need to make some modifications
Type& Graph<Type>::operator[](int vertex){
    assert(vertex<size());
    return labels[vertex];
}
template<class Type>
Type Graph<Type>::operator[](int vertex) const{
    assert(vertex<size());
    return labels[vertex];
}

template<class Type>
std::set<int> Graph<Type>::neighbors(int vertex) const{
    assert(vertex<size());
    std::set<int> vertexNeighbors;
    for(int index=0;index<size();index++){
            if(adjacencyMatrix[vertex][index]){
                vertexNeighbors.insert(index);
            }
    }
    return vertexNeighbors;
}

template<class Type>
void Graph<Type>::removeEdge(int source,int target){
    assert(source<size() && target<size());
    adjacencyMatrix[source][target]=false;
}