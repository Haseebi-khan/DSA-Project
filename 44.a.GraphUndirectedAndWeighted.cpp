#include <iostream>
#include <vector>
#include <list>
// #include <iterator>
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
            cout << temp.vertexName << "(" << temp.vertexId << ")-->";
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

    // bool checkEgdesConnectionExist(int fromVertex, int toVertex)
    // {
    //     Vertex v = vertices.at(fromVertex);
    //     for (auto it = v.edgesList.begin(); it != v.edgesList.end(); it++)
    //     {
    //         if (it->destinationId == toVertex)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    bool checkEgdesConnectionExist(int fromVertex, int toVertex)
    {
        Vertex v = vertices.at(fromVertex);

        for (const auto &edge : v.edgesList)
        {
            if (edge.destinationId == toVertex)
            {
                return true;
            }
        }

        return false;
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
            cout << "Vertex Already Exist.\n";
        }
    }

    void addEdgesById(int fromVertex, int toVertex, int w)
    {
        bool checkVextex1Exist = checkVertexExist(fromVertex);
        bool checkVextex2Exist = checkVertexExist(toVertex);
        if (checkVextex1Exist && checkVextex2Exist)
        {
            bool checkEgdesExist = checkEgdesConnectionExist(fromVertex, toVertex);
            if (!checkEgdesExist)
            {
                bool one = false;
                bool two = false;
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).vertexId == fromVertex)
                    {
                        Edge newEdge(toVertex, w);
                        vertices.at(i).edgesList.push_back(newEdge);
                        one = true;
                    }
                    else if (vertices.at(i).vertexId == toVertex)
                    {
                        Edge newEdge(fromVertex, w);
                        vertices.at(i).edgesList.push_back(newEdge);
                        two = true;
                    }
                }
                if (one && two)
                {
                    cout << "Both Connected.\n";
                }
            }
            else
            {
                cout << "Edges already Exist.\n";
            }
        }
        else
        {
            cout << "Invalid id entered.\n";
        }
    }

    void UpdateEdge(int fromVertex, int toVertex, int newWeight)
    {
        bool check = checkEgdesConnectionExist(fromVertex, toVertex);

        if (check)
        {
            for (auto i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).vertexId == fromVertex)
                {
                    for (auto it = vertices.at(i).edgesList.begin(); it != vertices.at(i).edgesList.end(); it++)
                    {
                        if (it->destinationId == toVertex)
                        {
                            it->weight = newWeight;
                            break;
                        }
                    }
                }
                else if (vertices.at(i).vertexId == toVertex)
                {
                    for (auto it = vertices.at(i).edgesList.begin(); it != vertices.at(i).edgesList.end(); it++)
                    {
                        if (it->destinationId == fromVertex)
                        {
                            it->weight = newWeight;
                            break;
                        }
                    }
                }
            }
            cout << "Edges Connected.\n";
        }
        else
        {
            cout << "Vertices not exist.\n";
        }
    }

    void deleteEdgesById(int fromVertex, int toVertex)
    {
        bool checkEdges = checkEgdesConnectionExist(fromVertex, toVertex);

        if (checkEdges)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).vertexId == fromVertex)
                {
                    for (auto it = vertices.at(i).edgesList.begin(); it != vertices.at(i).edgesList.end(); it++)
                    {
                        if (it->destinationId == toVertex)
                        {
                            vertices.at(i).edgesList.erase(it);
                            break;
                        }
                    }
                }
                else if (vertices.at(i).vertexId == toVertex)
                {
                    for (auto it = vertices.at(i).edgesList.begin(); it != vertices.at(i).edgesList.end(); it++)
                    {
                        if (it->destinationId == toVertex)
                        {
                            vertices.at(i).edgesList.erase(it);
                            break;
                        }
                    }
                }
            }
            cout << "Edges Deleted.\n";
        }
        else
        {
            cout << "Vertices don't have Edges.\n";
        }
    }

    // void deleteVertexById(int vertexId)
    // {
    //     int Vertexindex = 0;
    //     for (int i = 0; i < vertices.size(); i++)
    //     {
    //         if (vertices.at(i).vertexId == vertexId)
    //         {
    //             Vertexindex = i;
    //         }
    //     }

    //     for (auto it = vertices.at(Vertexindex).edgesList.begin(); it != vertices.at(Vertexindex).edgesList.end(); it++)
    //     {
    //         deleteEdgesById(it->destinationId, vertexId);
    //     }

    //     vertices.erase(vertices.begin() + Vertexindex);
    //     cout << "Vertex deleted.\n";
    // }

    void deleteVertexById(int vertexId)
    {
        int Vertexindex = -1;

        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).vertexId == vertexId)
            {
                Vertexindex = i;
                break; // Exit once found
            }
        }

        if (Vertexindex == -1)
        {
            cout << "Vertex not found.\n";
            return;
        }

        // Collect all destination IDs to avoid iterator invalidation
        list<int> destinations;
        for (const auto &edge : vertices[Vertexindex].edgesList)
        {
            destinations.push_back(edge.destinationId);
        }

        // Delete edges to each destination
        for (int destId : destinations)
        {
            deleteEdgesById(vertexId, destId);
        }

        vertices.erase(vertices.begin() + Vertexindex);
        cout << "Vertex deleted.\n";
    }

    void UpdateVertex(int VertexId)
    {
        string newVertexName;
        cout << "Enter The vertex New Name: ";
        cin >> newVertexName;
        bool check = checkVertexExist(VertexId);
        if (check)
        {
            for (int i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).vertexId == VertexId)
                {
                    vertices.at(i).vertexName = newVertexName;
                    break;
                }
            }
        }
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
        cout << "Select Option number. Enter 0 to exit.\n"
             << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Update Vertex" << endl;
        cout << "3. Delete Vertex" << endl;
        cout << "4. Add Edge" << endl;
        cout << "5. Update Edge" << endl;
        cout << "6. Delete Edge" << endl;
        cout << "7. Check if 2 Vertices are Neigbors" << endl;
        cout << "8. Print All Neigbors of a Vertex" << endl;
        cout << "9. Print Graph" << endl;
        cout << "10. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cout << "\n";

        cout << "What operation do you want to perform: ";
        cin >> option;
        cout << "\n";

        switch (option)
        {
        case 1:
            cout << "Add Vertex Operation" << endl;
            cout << "Enter Vertex ID:";
            cin >> id1;
            cout << "Enter Vertex Name:";
            cin >> name;
            v.setVertex(id1, name);
            g.addVertex(v);
            break;

        case 2:
            cout << "Update Vertex Operation" << endl;
            break;

        case 3:
            cout << "Delete Vertex Operation" << endl;
            cout << "Enter Vertex Id: ";
            cin >> id1;
            g.deleteVertexById(id1);
            break;

        case 4:
            cout << "Add Edge Operation" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            cout << "Enter Weight of the Edge: ";
            cin >> w;
            g.addEdgesById(id1, id2, w);
            break;

        case 5:
            cout << "Update Edge Operation" << endl;
            cout << "Enter the Source id1:";
            cin >> id1;
            cout << "Enter the Destination id2:";
            cin >> id2;
            cout << "Enter New Weight:";
            int weight;
            cin >> weight;
            g.UpdateEdge(id1, id2, weight);
            break;

        case 6:
            cout << "Delete Edge Operation" << endl;
            cout << "Enter the Source id1:";
            cin >> id1;
            cout << "Enter the Destination id2:";
            cin >> id2;
            g.deleteEdgesById(id1, id2);
            break;

        case 7:
            cout << "Check if 2 Vertices are Neighbors" << endl;
            break;

        case 8:
            cout << "Print All Neighbors of a Vertex" << endl;
            break;

        case 9:
            cout << "Print Graph Operation" << endl;
            g.printGraph();
            break;

        default:
            cout << "Enter valid Operation." << endl;
        }

    } while (option != 0);

    cout << endl;
    return 0;
}