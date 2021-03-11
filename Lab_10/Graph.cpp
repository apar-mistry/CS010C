// A solo lab done by Apar Mistry
#include "Graph.h"
#include <iostream>

Graph::Graph(){}

Graph::Graph(ifstream& ifS){
    int node = 0;
    int edges = 0;
    int weight = 0;
    string title = "", neighborTitle = "";

    ifS>> node;
    ifS>> edges;
    ifS.ignore();
    for(int i = 0; i < node; i++){
        Vertex n;
        string t = "";
        getline(ifS, t);
        n.label = t;
        vertices.push_back(n);
    }

    while(ifS >> title){
        int index = 0;
        int neighborInd = 0;
        ifS>> neighborTitle;
        ifS>> weight;

        for(unsigned i = 0; i < vertices.size(); i++){
            if(title == vertices.at(i).label)
            {
                index = i;
            }
            if(neighborTitle == vertices.at(i).label){
                neighborInd = i;
            }
        }
        
        vertices.at(index).neighbors.push_back(make_pair(neighborInd, weight));
    }
    ifS.close();

}

Graph::~Graph(){
    vertices.clear();
}

void Graph::output_graph(const string &fN)
{
    ofstream outFS(fN.c_str());

    if (!outFS.is_open())
    {
        cout << "Error" << endl;
        return;
    }

    outFS << "digraph G {" << endl;

    for (unsigned i = 0; i < vertices.size(); ++i)
    {
    	// if (vertices.at(i).distance != 50)
        // {
            outFS << vertices.at(i).label << "[label = \"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\"]" << endl;
    	// }

     	if (!vertices.at(i).neighbors.empty())
        {
     	    list<pair<int, int> >::iterator it = vertices.at(i).neighbors.begin();
     		while (it != vertices.at(i).neighbors.end())
            {
     			// if (vertices.at(i).distance != 50)
                // {
     		        outFS << vertices.at(i).label << " -> " << vertices.at(it->first).label << endl;
     			// }

     		    ++it;
     		}
     	}	    
    }

    outFS << "}";
    outFS.close();

    string fNjpg = fN.substr(0, fN.size()-4) + ".jpg";

    string command = "dot -Tpng " + fN + " -o " + fNjpg;
    system(command.c_str());
}


//used bfs pseudo code on the graphs.pdf 
//bfs is a type of traversal that starts at a vertex and then goes to verticies wit distance 1 then 2 and so on
void Graph::bfs()
{
    for (unsigned i = 0; i < vertices.size(); ++i)
    {
        vertices.at(i).color = "WHITE"; //aka means undiscovered
        vertices.at(i).distance = INT_MAX; //default distance from start
        vertices.at(i).prev = 0; //previous vertex
    }

    //now making the beginning be discovered but not fully expanded, AKA GRAY
    vertices.at(0).color = "GRAY"; 
    vertices.at(0).distance = 0;

    queue<Vertex*> queue; //make queue
    queue.push(&vertices.at(0)); //enqueues start vertex aka first into queue
    Vertex* currVertex; //currVertex pointer 

    while (!queue.empty())
    {
        currVertex = queue.front();
        list<pair<int, int> >::iterator it = currVertex->neighbors.begin(); //starting vertex is dequeued and visited

        while (it != currVertex->neighbors.end()) //exploring adjacent verticies
        {
            if (vertices.at(it->first).color == "WHITE") //checking if undiscovered
            {
                vertices.at(it->first).color = "GRAY"; //make em be discovered, but not expanded
                vertices.at(it->first).distance = currVertex->distance + it->second;
                vertices.at(it->first).prev = currVertex;
                queue.push(&vertices.at(it->first)); //undiscovered verticies are enqueued onto queue
            }

            ++it;
        }

        currVertex->color = "BLACK"; //BLACK = discovered and expanded

        queue.pop(); //final pop to make it empty
    }
}
    
