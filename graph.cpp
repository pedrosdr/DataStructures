#include <iostream>
#include <vector>
#include <list>
#include "headers/print.h"

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
            std::cout << "<- " << weight << " -> " << "(" << destinationId << ")";
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
        Vertex(int id, std::string name) : id(id), name(name), edges(new std::list<Edge*>()) {};

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
            std::cout << "(" << id << ": " << name << ") ";

            for(Edge* edge : *edges)
            {
                edge->display();
            }
        }

};

class Graph
{
    private:
        // fields
        std::vector<Vertex*>* vertices;

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
    Edge* e = new Edge(1, 20.4f);

    std::list<Edge*>* lst = new std::list<Edge*>();
    lst->push_back(e); 

    Vertex* v = new Vertex(0, "v1");
    v->setEdges(lst);

    std::vector<Vertex*>* vect = new std::vector<Vertex*>();
    vect->push_back(v);

    Graph g = Graph(vect);
    g.display();
    return 0;
}