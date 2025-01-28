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
    list<Edge> edges;

    Vertex(int id = -1, string name = "") : vertexId(id), vertexName(name) {}
    void setVertex(int id = -1, string name = "")
    {
        vertexId = id;
        vertexName = name;
    }
    void printEdges()
    {
        cout << "[";
        for (auto it = edges.begin(); it != edges.end(); it++)
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

    void addVertex(Vertex newVertex)
    {
        if (!checkVertexExist(newVertex.vertexId))
        {
            vertices.push_back(newVertex);
        }
        else
        {
            cout << "Vertex Already Exist.\n";
        }
    }

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

    bool checkEgdesConnectionExist(int id1, int id2)
    {
        Vertex v = vertices.at(id1);
        for (auto it = v.edges.begin(); it != v.edges.end(); it++)
        {
            if (it->destinationId == id2)
            {
                return true;
            }
        }
        return false;
    }


    void addEdgesById(int id1, int id2, int w)
    {
        bool checkVextex1Exist = checkVertexExist(id1);
        bool checkVextex2Exist = checkVertexExist(id2);
        if (checkVextex1Exist && checkVextex2Exist)
        {
            bool checkEgdesExist = checkEgdesConnectionExist(id1, id2);
            if (!checkEgdesExist)
            {
                bool one = false;
                bool two = false;
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).vertexId == id1)
                    {
                        Edge newEdge(id2, w);
                        vertices.at(i).edges.push_back(newEdge);
                        one = true;
                    }
                    else if (vertices.at(i).vertexId == id2)
                    {
                        Edge newEdge(id1, w);
                        vertices.at(i).edges.push_back(newEdge);
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

    void UpdateEdge(int id1, int id2, int newWeight)
    {
        bool check = checkEgdesConnectionExist(id1, id2);

        if (check)
        {
            for (auto i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).vertexId == id1)
                {
                    for (auto it = vertices.at(i).edges.begin(); it != vertices.at(i).edges.end(); it++)
                    {
                        if (it->destinationId == id2)
                        {
                            it->weight = newWeight;
                            break;
                        }
                    }
                }
                else if (vertices.at(i).vertexId == id2)
                {
                    for (auto it = vertices.at(i).edges.begin(); it != vertices.at(i).edges.end(); it++)
                    {
                        if (it->destinationId == id1)
                        {
                            it->weight = newWeight;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            cout << "Edges not exist b/w Vertices.\n";
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