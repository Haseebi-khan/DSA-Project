#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Edge
{
public:
    int destinationId;
    int weight;
    Edge(int id = -1, int w = 0) : destinationId(id), weight(w) {}
    void setEdge(int id, int w)
    {
        destinationId = id;
        weight = w;
    }
};

class Vertex
{
public:
    int vertexId;
    string vertexName;
    list<Edge> edgesList;

    Vertex(int id = -1, string name = "") : vertexId(id), vertexName(name) {}
    void setVertex(int id = -1, string name = "")
    {
        vertexId = id;
        vertexName = name;
    }
    void printEdges()
    {
        cout << "[";
        for (auto it = edgesList.begin(); it != edgesList.end(); it++)
        {
            cout << it->destinationId << "(" << it->weight << ")->";
        }
        cout << "]";
    }
};

class Graph
{
public:
    vector<Vertex> vertices;

    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex temp = vertices.at(i);
            cout << temp.vertexName << "(" << temp.vertexId << ") --> ";
            temp.printEdges();
            cout << "\n";
        }
        cout << "\n";
    }

    bool checkVertexExist(int id)
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).vertexId == id)
            {
                return true;
            }
        }
        return false;
    }

    bool checkEdgesConnectionExist(int fromVertex, int toVertex)
    {
        // Check only in the source vertex's edge list
        for (const auto &edge : vertices.at(getVertexIndex(fromVertex)).edgesList)
        {
            if (edge.destinationId == toVertex)
            {
                return true;
            }
        }
        return false;
    }

    // Helper function: returns index in vector for a given vertex id.
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

    void addEdgesById(int fromVertex, int toVertex, int w)
    {
        if (checkVertexExist(fromVertex) && checkVertexExist(toVertex))
        {
            // Directed: only add edge from 'fromVertex' to 'toVertex'
            int idx = getVertexIndex(fromVertex);
            if (idx == -1)
            {
                cout << "Source vertex not found.\n";
                return;
            }
            if (!checkEdgesConnectionExist(fromVertex, toVertex))
            {
                Edge newEdge(toVertex, w);
                vertices.at(idx).edgesList.push_back(newEdge);
                cout << "Edge added from " << fromVertex << " to " << toVertex << ".\n";
            }
            else
            {
                cout << "Edge already exists.\n";
            }
        }
        else
        {
            cout << "Invalid vertex id(s) entered.\n";
        }
    }

    void UpdateEdge(int fromVertex, int toVertex, int newWeight)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return;
        }
        bool found = false;
        for (auto it = vertices.at(idx).edgesList.begin(); it != vertices.at(idx).edgesList.end(); it++)
        {
            if (it->destinationId == toVertex)
            {
                it->weight = newWeight;
                found = true;
                break;
            }
        }
        if (found)
            cout << "Edge updated.\n";
        else
            cout << "Edge does not exist.\n";
    }

    void deleteEdgesById(int fromVertex, int toVertex)
    {
        int idx = getVertexIndex(fromVertex);
        if (idx == -1)
        {
            cout << "Source vertex not found.\n";
            return;
        }
        bool found = false;
        for (auto it = vertices.at(idx).edgesList.begin(); it != vertices.at(idx).edgesList.end(); it++)
        {
            if (it->destinationId == toVertex)
            {
                vertices.at(idx).edgesList.erase(it);
                found = true;
                break;
            }
        }
        if (found)
            cout << "Edge deleted.\n";
        else
            cout << "Edge does not exist.\n";
    }

    void deleteVertexById(int vertexId)
    {
        int Vertexindex = getVertexIndex(vertexId);
        if (Vertexindex == -1)
        {
            cout << "Vertex not found.\n";
            return;
        }

        // Remove all edges from other vertices that point to this vertex.
        for (int i = 0; i < vertices.size(); i++)
        {
            // Use iterator to safely remove while iterating.
            for (auto it = vertices.at(i).edgesList.begin(); it != vertices.at(i).edgesList.end();)
            {
                if (it->destinationId == vertexId)
                    it = vertices.at(i).edgesList.erase(it);
                else
                    ++it;
            }
        }

        // Erase the vertex from the vector.
        vertices.erase(vertices.begin() + Vertexindex);
        cout << "Vertex deleted.\n";
    }

    void UpdateVertex(int VertexId)
    {
        string newVertexName;
        cout << "Enter the new vertex name: ";
        cin >> newVertexName;
        int idx = getVertexIndex(VertexId);
        if (idx != -1)
        {
            vertices.at(idx).vertexName = newVertexName;
            cout << "Vertex updated.\n";
        }
        else
        {
            cout << "Vertex not found.\n";
        }
    }

    void printAllNeighborById(int vId)
    {
        int idx = getVertexIndex(vId);
        if (idx == -1)
        {
            cout << "Vertex not found.\n";
            return;
        }
        cout << vertices.at(idx).vertexName << "(" << vertices.at(idx).vertexId << ") --> ";
        cout << "[";
        for (const auto &edge : vertices.at(idx).edgesList)
        {
            cout << edge.destinationId << "(" << edge.weight << ") ";
        }
        cout << "]\n";
    }

    bool areNeighbors(int vertexId1, int vertexId2)
    {
        int idx = getVertexIndex(vertexId1);
        if (idx == -1)
            return false;
        for (const auto &edge : vertices.at(idx).edgesList)
        {
            if (edge.destinationId == vertexId2)
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g;
    Vertex v;
    string name;
    int id1, id2, option, w;
    do
    {
        cout << "\nSelect Option number. Enter 0 to exit.\n";
        cout << "1. Add Vertex\n";
        cout << "2. Update Vertex\n";
        cout << "3. Delete Vertex\n";
        cout << "4. Add Edge (Directed)\n";
        cout << "5. Update Edge\n";
        cout << "6. Delete Edge\n";
        cout << "7. Check if 2 Vertices are Neighbors\n";
        cout << "8. Print All Neighbors of a Vertex\n";
        cout << "9. Print Graph\n";
        cout << "10. Clear Screen\n";
        cout << "0. Exit Program\n\n";
        cout << "What operation do you want to perform: ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {

                cout << "Add Vertex Operation\n";
                cout << "Enter Vertex ID: ";
                cin >> id1;
                cout << "Enter Vertex Name: ";
                cin >> name;
                v.setVertex(id1, name);
                g.addVertex(v);
            }
            break;
        case 2:
            cout << "Update Vertex Operation\n";
            cout << "Enter Vertex ID: ";
            cin >> id1;
            g.UpdateVertex(id1);
            break;
        case 3:
            cout << "Delete Vertex Operation\n";
            cout << "Enter Vertex Id: ";
            cin >> id1;
            g.deleteVertexById(id1);
            break;
        case 4:
            cout << "Add Edge Operation (Directed)\n";
            cout << "Enter Source Vertex ID: ";
            cin >> id1;
            cout << "Enter Destination Vertex ID: ";
            cin >> id2;
            cout << "Enter Weight of the Edge: ";
            cin >> w;
            g.addEdgesById(id1, id2, w);
            break;
        case 5:
            cout << "Update Edge Operation\n";
            cout << "Enter Source Vertex ID: ";
            cin >> id1;
            cout << "Enter Destination Vertex ID: ";
            cin >> id2;
            cout << "Enter New Weight: ";
            cin >> w;
            g.UpdateEdge(id1, id2, w);
            break;
        case 6:
            cout << "Delete Edge Operation\n";
            cout << "Enter Source Vertex ID: ";
            cin >> id1;
            cout << "Enter Destination Vertex ID: ";
            cin >> id2;
            g.deleteEdgesById(id1, id2);
            break;
        case 7:
            cout << "Check if 2 Vertices are Neighbors\n";
            cout << "Enter First Vertex Id: ";
            cin >> id1;
            cout << "Enter Second Vertex Id: ";
            cin >> id2;
            if (g.areNeighbors(id1, id2))
                cout << "Yes, Vertex " << id2 << " is a neighbor of Vertex " << id1 << ".\n";
            else
                cout << "No, Vertex " << id2 << " is not a neighbor of Vertex " << id1 << ".\n";
            break;
        case 8:
            cout << "Print All Neighbors of a Vertex\n";
            cout << "Enter Vertex Id: ";
            cin >> id1;
            g.printAllNeighborById(id1);
            break;
        case 9:
            cout << "Print Graph Operation\n";
            g.printGraph();
            break;
        case 10:
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
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
