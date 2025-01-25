#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

class Edges
{
public:
    int destinationId;
    int weight;
    Edges(int id = 0, int w = 0) : destinationId(id), weight(w) {}
    void setEdges(int id = 0, int w = 0)
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
    list<Edges> edgesList;
    Vertex(int id = 0, string name = "") : vertexId(id), vertexName(name) {}
    void setVertex(int id = 0, string name = "")
    {
        vertexId = id;
        vertexName = name;
    }
    void printEgdesList()
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
private:
    bool checkVertaxExist(int id)
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

    Vertex getVertexById(int id)
    {
        Vertex temp;
        for (int i = 0; i < vertices.size(); i++)
        {
            temp = vertices.at(i);
            if (temp.vertexId == id)
            {
                return temp;
            }
        }
        return temp;
    }

    bool checkifEdgeExistById(int id1, int id2)
    {
        Vertex vertex = getVertexById(id1);
        list<Edges> edges;
        edges = vertex.edgesList;
        for (auto it = edges.begin(); it != edges.end(); it++)
        {
            if (it->destinationId == id2)
            {
                return true;
                break;
            }
        }
        return false;
    }

public:
    vector<Vertex> vertices;

    void addVertex(Vertex newVertex)
    {
        if (!checkVertaxExist(newVertex.vertexId))
        {
            vertices.push_back(newVertex);
        }
        else
        {
            cout << "Vertex is allready Present.\n";
        }
    }

    void addEdgesById(int id1, int id2, int w)
    {
        bool check1 = checkVertaxExist(id1);
        bool check2 = checkVertaxExist(id2);

        if (check1 && check2) // if (check1 && check2 == true)
        {
            bool check3 = checkifEdgeExistById(id1, id2);
            if (!check3)
            {
                for (int i = 0; i < vertices.size(); i++)
                {
                    if (vertices.at(i).vertexId == id1)
                    {
                        Edges e(id2, w);
                        vertices.at(i).edgesList.push_back(e);
                    }
                    else if (vertices.at(i).vertexId == id2)
                    {
                        Edges e(id1, w);
                        vertices.at(i).edgesList.push_back(e);
                    }
                    cout << "Connection b/w id1 and id2 are successfully add.\n";
                }
            }
            else
            {
                cout << "EDGE already Exist.\n";
            }
        }
        else
        {
            cout << "Invalid ID Entered!.\n";
        }
    }

    void printGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            Vertex temp;
            temp = vertices.at(i);
            cout << temp.vertexName << "(" << temp.vertexId << ")-->";
            temp.printEgdesList();
            cout << "\n";
        }
        cout << "\n";
    }

    void updateVertex();
    void deleteVertex();
    void updateEdges();
    void deleteEdges();
    void searchVertx();
    bool CheckVertxConnections();
};

int main()
{
    Graph graph;
    Vertex vertex;
    string name;
    int option, id, id2, w;

    do
    {
        cout << "Select Option number. Enter 0 to exit." << endl;
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
            cin >> id;
            cout << "Enter Vertex Name:";
            cin >> name;
            vertex.setVertex(id, name);
            graph.addVertex(vertex);

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
            cin >> id;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            cout << "Enter Weight of the Edge: ";
            cin >> w;
            graph.addEdgesById(id, id2, w);

            break;

        case 5:
            cout << "Update Edge Operation" << endl;
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
            graph.printGraph();
            break;

        default:
            cout << "Enter valid Operation." << endl;
        }
    } while (option != 0);

    cout << endl;
    return 0;
}
