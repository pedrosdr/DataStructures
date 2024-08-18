#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "headers/print.h"

template <typename T>
bool contains(std::vector<T>& v, T x)
{
    bool res = false;
    if(std::find(v.begin(), v.end(), x) != v.end()) {
        res = true;
    }
    return res;
}

float min(std::vector<float>& v)
{
    float minimum = v.at(0);
    for(int i = 1; i < v.size(); i++)
    {
        if(v.at(i) < minimum)
            minimum = v.at(i);
    }
    return minimum;
}

class Edge
{
    private:
        // fields
        int destinationId;
        float weight;

    public:
        // constructors
        Edge() : destinationId(-1), weight(0.0f) {}
        Edge(int destinationId, float weight): destinationId(destinationId), weight(weight) {}

        // destructors
        ~Edge() {}

        // properties
        int    getDestinationId()           {return destinationId;}
        void   setDestinationId(int value)  {destinationId = value;}

        float  getWeight()                  {return weight;}
        void   setWeight(float value)       {weight = value;}

        // methods
        void display()
        {
            std::cout << "(" << destinationId << ", " << weight << ")";
        }
};

class Vertex
{
    private:
        // fields
        int id;
        std::string name;
        std::list<Edge*>* edges;

    public:
        // constructors
        Vertex() : id(-1), name(""), edges(new std::list<Edge*>()) {}
        Vertex(int id, std::string name) : id(id), name(name), edges(new std::list<Edge*>()) {}
        Vertex(int id, std::string name, std::list<Edge*>* edges) : id(id), name(name), edges(edges) {}

        // destructors
        ~Vertex() {}

        // properties
        int                getId()                            {return id;}
        void               setId(int value)                   {id = value;}

        std::string        getName()                          {return name;}
        void               setName(std::string value)         {name = value;}

        std::list<Edge*>*  getEdges()                         {return edges;}
        void               setEdges(std::list<Edge*>* value)  {edges = value;}

        // methods
        void display()
        {
            std::cout << "(" << id << ": " << name << ") <= [";

            for(Edge* edge : *edges)
            {
                edge->display();
                std::cout << ", ";
            }

            std::cout << "]";
        }

};

class Graph
{
    private:
        // fields
        std::vector<Vertex*>* vertices;

        // methods
        float getClosestDistance(int from, int to, float previousDistance, std::vector<int> checkedVertices)
        {
            if(from == to)
                return previousDistance;
            
            checkedVertices.push_back(from);
            Vertex* temp = vertices->at(from);

            std::vector<float> distances = std::vector<float>();
            for(Edge* edge : *temp->getEdges())
            {
                if(contains(checkedVertices, edge->getDestinationId()))
                    continue;
                
                float actualDist = previousDistance + edge->getWeight();
                float dist = getClosestDistance(edge->getDestinationId(), to, actualDist, checkedVertices);
                if(dist >= 0.0f)
                    distances.push_back(dist);
            }
            if(distances.empty())
                return -1.0f;
            
            return min(distances);
        }

    public:
        // constructors
        Graph() : vertices(new std::vector<Vertex*>()) {}
        Graph(std::vector<Vertex*>* vertices) : vertices(vertices) {}

        // destructors
        ~Graph()
        {
            vertices->clear();
            delete vertices;
        }

        // properties
        std::vector<Vertex*>*  getVertices()                             {return vertices;}
        void                   setVertices(std::vector<Vertex*>* value)  {vertices = value;}

        // methods
        float getClosestDistance(int from, int to)
        {
            std::vector<int> vect = std::vector<int>();
            return getClosestDistance(from, to, 0.0f, vect);
        }

        void display()
        {
            std::cout << "----------------------------------------\n";
            std::cout << "---------         Graph        ---------\n";
            std::cout << "----------------------------------------\n";

            if(!vertices->empty())
            {
                for(Vertex* vertex : *vertices)
                {
                    vertex->display();
                    std::cout << "\n";
                }
            }
            else
                std::cout << "---------         Empty        ---------\n";

            std::cout << "----------------------------------------\n";
        }
        
};

int main(int argc, char* argv[])
{
    Vertex* v;
    std::list<Edge*>* lst;
    std::vector<Vertex*>* vect = new std::vector<Vertex*>(); 

    v = new Vertex(0, "Sao Paulo");
    lst = new std::list<Edge*>();
    lst->push_back(new Edge(1, 585.0f));
    lst->push_back(new Edge(2, 446.0f));
    lst->push_back(new Edge(4, 984.0f));
    v->setEdges(lst);
    vect->push_back(v);

    v = new Vertex(1, "Belo Horizonte");
    lst = new std::list<Edge*>();
    lst->push_back(new Edge(0, 585.0f));
    lst->push_back(new Edge(2, 442.0f));
    lst->push_back(new Edge(3, 515.0f));
    lst->push_back(new Edge(4, 1262.0f));
    v->setEdges(lst);
    vect->push_back(v);

    v = new Vertex(2, "Rio de Janeiro");
    lst = new std::list<Edge*>();
    lst->push_back(new Edge(0, 446.0f));
    lst->push_back(new Edge(1, 442.0f));
    lst->push_back(new Edge(3, 518.0f));
    v->setEdges(lst);
    vect->push_back(v);

    v = new Vertex(3, "Vitoria");
    lst = new std::list<Edge*>();
    lst->push_back(new Edge(1, 515.0f));
    lst->push_back(new Edge(2, 518.0f));
    v->setEdges(lst);
    vect->push_back(v);

    v = new Vertex(4, "Campo Grande");
    lst = new std::list<Edge*>();
    lst->push_back(new Edge(0, 984.0f));
    lst->push_back(new Edge(1, 1262.0f));
    v->setEdges(lst);
    vect->push_back(v);

    Graph g = Graph(vect);
    g.display();

    print(g.getClosestDistance(4, 2));

    return 0;
}