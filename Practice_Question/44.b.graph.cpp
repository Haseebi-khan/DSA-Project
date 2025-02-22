#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Edge {
public:
    int destinationId;
    int weight;
    Edge(int destId, int w) : destinationId(destId), weight(w) {}
};

class Vertex {
public:
    int vertexId;
    list<Edge> edgesList;
    Vertex(int id) : vertexId(id) {}
};

class Graph {
public:
    vector<Vertex> vertices;

    void addVertex(int vertexId) {
        vertices.push_back(Vertex(vertexId));
    }

    void addEdge(int srcId, int destId, int weight) {
        for (auto &vertex : vertices) {
            if (vertex.vertexId == srcId) {
                vertex.edgesList.push_back(Edge(destId, weight));
                break;
            }
        }
        for (auto &vertex : vertices) {
            if (vertex.vertexId == destId) {
                vertex.edgesList.push_back(Edge(srcId, weight));
                break;
            }
        }
    }

    void deleteEdgesById(int srcId, int destId) {
        for (auto &vertex : vertices) {
            if (vertex.vertexId == srcId) {
                vertex.edgesList.remove_if([destId](const Edge &edge) { return edge.destinationId == destId; });
                break;
            }
        }
    }

    void deleteVertexById(int vertexId) {
        int Vertexindex = -1;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.at(i).vertexId == vertexId) {
                Vertexindex = i;
                break; // Exit once found
            }
        }

        if (Vertexindex == -1) {
            cout << "Vertex not found.\n";
            return;
        }

        // Collect all destination IDs to avoid iterator invalidation
        list<int> destinations;
        for (const auto &edge : vertices[Vertexindex].edgesList) {
            destinations.push_back(edge.destinationId);
        }

        // Delete edges to each destination
        for (int destId : destinations) {
            deleteEdgesById(vertexId, destId);
        }

        vertices.erase(vertices.begin() + Vertexindex);
        cout << "Vertex deleted.\n";
    }
};

int main() {
    Graph g;

    // Add vertices
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    // Add edges
    g.addEdge(1, 2, 10);
    g.addEdge(2, 3, 20);

    // Display initial graph
    cout << "Initial graph:" << endl;
    for (const auto &vertex : g.vertices) {
        cout << "Vertex " << vertex.vertexId << " has edges to: ";
        for (const auto &edge : vertex.edgesList) {
            cout << edge.destinationId << " ";
        }
        cout << endl;
    }

    // Delete vertex 2
    g.deleteVertexById(2);

    // Display graph after deletion
    cout << "Graph after deleting vertex 2:" << endl;
    for (const auto &vertex : g.vertices) {
        cout << "Vertex " << vertex.vertexId << " has edges to: ";
        for (const auto &edge : vertex.edgesList) {
            cout << edge.destinationId << " ";
        }
        cout << endl;
    }

    return 0;
}