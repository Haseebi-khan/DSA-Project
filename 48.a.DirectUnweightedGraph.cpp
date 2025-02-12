#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Edge
{
public:
    int destinationId;
    Edge(int id = -1) : destinationId(id) {}
};

class Vertex
{
public:
    int vertexId;
    char vertexName;
    list<Edge> edgesList;

    Vertex(int id = -1, char name = ' ') : vertexId(id), vertexName(name) {}
    void setVertex(int id = -1, char name = ' ')
    {
        vertexId = id;
        vertexName = name;
    }
    void printEdges() const
    {
        cout << "[";
        for (auto it = edgesList.begin(); it != edgesList.end(); ++it)
        {
            cout << it->destinationId << " -> ";
        }
        cout << "]";
    }
};

class Graph
{
public:
    vector<Vertex> vertices;
    Graph()
    {
        Vertex v;
        char name;
        int id1, id2;
        for (int i = 1; i < 10; i++)
        {

            id1 = i;
            name = 48 + i;
            if (i != 9)
            {
                v.setVertex(id1, name);
            }
            else
            {
                v.setVertex(id1, ' ');
            }
            addVertex(v);
        }

        connectAllEdges();
        printGraph();
    }
    void connectAllEdges()
    {
        // Connect horizontal edges in a 3x3 grid:
        // For every vertex, if it is not at the right boundary (i.e. i % 3 != 0),
        // add an edge to the vertex immediately to its right.
        for (int i = 1; i <= 9; ++i)
        {
            if (i % 3 != 0) // vertices 1,2,4,5,7,8 have a right neighbor
            {
                addEdgesById(i, i + 1);
            }
        }

        // Connect vertical edges:
        // For vertices 1 through 6, add an edge to the vertex directly below
        // (i.e. add 3 to the current vertex id).
        for (int i = 1; i <= 6; ++i)
        {
            addEdgesById(i, i + 3);
        }
    }

    void updateVertex(int vertexId, char newName)
    {
        int idx = getVertexIndex(vertexId);
        if (idx != -1)
        {
            vertices[idx].vertexName = newName;
        }
        else
        {
            cout << "Vertex " << vertexId << " not found.\n";
        }
    }

    bool checkEdgeExist(int fromVertex, int toVertex)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return false;
        }
        for (const auto &edge : vertices[idx].edgesList)
        {
            if (edge.destinationId == toVertex)
                return true;
        }
        return false;
    }

    void printGraph()
    {
        // Iterating over const reference so that vertices aren't modified.
        for (const auto &vertex : vertices)
        {
            cout << vertex.vertexName << "(" << vertex.vertexId << ") --> ";
            vertex.printEdges();
            cout << "\n";
        }
        cout << "\n";
    }

    bool checkVertexExist(int id)
    {
        for (const auto &vertex : vertices)
        {
            if (vertex.vertexId == id)
            {
                return true;
            }
        }
        return false;
    }

    int getVertexIndex(int id)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).vertexId == id)
                return i;
        }
        return -1;
    }

    void addVertex(Vertex newVertex)
    {
        if (!checkVertexExist(newVertex.vertexId))
        {
            vertices.push_back(newVertex);
            cout << "Vertex added.\n";
        }
        else
        {
            cout << "Vertex already exists.\n";
        }
    }

    void addEdgesById(int fromVertex, int toVertex)
    {
        if (checkVertexExist(fromVertex) && checkVertexExist(toVertex))
        {
            int idx = getVertexIndex(fromVertex);
            if (idx == -1)
            {
                cout << "Source vertex not found.\n";
                return;
            }
            vertices.at(idx).edgesList.push_back(Edge(toVertex));
            cout << "Edge added from " << fromVertex << " to " << toVertex << ".\n";
        }
        else
        {
            cout << "Invalid vertex id(s) entered.\n";
        }
    }

    void deleteEdgesById(int fromVertex, int toVertex)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return;
        }
        for (auto it = vertices.at(idx).edgesList.begin(); it != vertices.at(idx).edgesList.end(); it++)
        {
            if (it->destinationId == toVertex)
            {
                vertices.at(idx).edgesList.erase(it);
                cout << "Edge deleted.\n";
                return;
            }
        }
        cout << "Edge does not exist.\n";
    }
};

int main()
{
    Graph g;

    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    Vertex v;
    char name;
    int id1, id2, option;
    do
    {
        cout << "\nSelect Option number. Enter 0 to exit.\n";
        cout << "1. Add Vertex\n";
        cout << "2. Delete Vertex\n";
        cout << "3. Add Edge (Directed)\n";
        cout << "4. Delete Edge\n";
        cout << "5. Print Graph\n";
        cout << "0. Exit Program\n\n";
        cout << "What operation do you want to perform: ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 1:
            cout << "Add Vertex Operation\n";
            cout << "Enter Vertex ID: ";
            cin >> id1;
            cout << "Enter Vertex Name: ";
            cin >> name;
            v.setVertex(id1, name);
            g.addVertex(v);
            break;
        case 2:
            cout << "Delete Vertex Operation\n";
            cout << "Enter Vertex Id: ";
            cin >> id1;
            g.deleteEdgesById(id1, id1);
            break;
        case 3:
            cout << "Add Edge Operation (Directed)\n";
            cout << "Enter Source Vertex ID: ";
            cin >> id1;
            cout << "Enter Destination Vertex ID: ";
            cin >> id2;
            g.addEdgesById(id1, id2);
            break;
        case 4:
            cout << "Delete Edge Operation\n";
            cout << "Enter Source Vertex ID: ";
            cin >> id1;
            cout << "Enter Destination Vertex ID: ";
            cin >> id2;
            g.deleteEdgesById(id1, id2);
            break;
        case 5:
            cout << "Print Graph Operation\n";
            g.printGraph();
            break;
        case 0:
            break;
        default:
            cout << "Enter a valid operation.\n";
        }
    } while (option != 0);
    cout << "\nExiting Program.\n";
    return 0;
}
