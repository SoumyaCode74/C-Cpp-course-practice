#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <ctime>

double probability(){
    // srand(time(NULL));
    return rand()/RAND_MAX;
}

class Graph{
    public:
    int **weights;             ///< Weights matrix    
    Graph(unsigned int n):V(n){
        this->weights = new int*[V];
        for(int i = 0; i < V; i++){
            weights[i] = new int[V];
        }
    }
    void set_weight(unsigned int node1, unsigned int node2, unsigned int weight){
        this->weights[node1][node2] = weight;
    }
    unsigned int get_weight(unsigned int node1, unsigned int node2){
        return this->weights[node1][node2];
    }
    unsigned int get_number_of_vertices(){
        return V;
    }
    unsigned int get_max_number_of_edges(void){
        return ((this->V)*(this->V - 1)/2);
    }
    void fill_weight_matrix(unsigned int density_percent, unsigned int range){
        this->density = (static_cast<double>(density_percent) / 100.0);
        unsigned int number_of_edges_allowed =  (this->density) * (get_max_number_of_edges());
        unsigned int count_edges = 0;
        int edge_value = 0;
        for(int i = 0; i < this->V; i++){
            srand(time(NULL));
            this->weights[i][i] = 0;            
            for(int j = i+1; j < this->V; j++){
                if(probability() < this->density){
                    if (count_edges <= number_of_edges_allowed){
                        // srand(time(NULL));
                        edge_value = rand()%range;
                        this->weights[i][j] = this->weights[j][i] = (edge_value > 1)?edge_value:1;                       
                        count_edges++;
                    }
                    else{
                        return;
                    }
                }       
            }
        }
    }
    void print_graph(){
        for(int i = 0; i < this->V; i++){
            for(int j = 0; j < this->V; j++){
                std::cout<<"Graph("<<i<<","<<j<<") = "<<this->weights[i][j]<<std::endl;
            }
        }
    }
    private:
    unsigned int V;             ///< Number of vertices in the graph
    double density;             ///< Density of the matrix
};

// function to find minimal distance
int shortest_distance(Graph g, int path_length[], bool connected[]){
	double min = DBL_MAX;
	int index;
	for (int v = 0; v < g.get_number_of_vertices(); v++){
		if (path_length[v] <= min && connected[v] == false){
			min = path_length[v];
			index = v;
		}
	}
	return index;
}

// function to calculate average distance
double average_distance(Graph g, int path_length[]){
	int sum = 0;
	for (int d = 0; d < g.get_number_of_vertices(); d++){
		sum += path_length[d];
    }
	double avg = (static_cast<double>(sum))/(g.get_number_of_vertices()-1);
	return avg;
}

// function to find the shortest path
int dijkstra(Graph g, int ref_vertex){
	int path_length[g.get_number_of_vertices()];
	bool connected[g.get_number_of_vertices()];

	for (int i = 0; i < g.get_number_of_vertices(); i++){
		path_length[i] = INT_MAX;
		connected[i] = false;
	}

	// the distance from the reference vertex always zero
	path_length[ref_vertex] = 0;

	// loop through other nodes
	for (int c = 0; c < g.get_number_of_vertices()-1; c++){
		int u = shortest_distance(g, path_length, connected);
		connected[u] = true;

		for (int v = 0; v < g.get_number_of_vertices(); v++){
			if (!connected[v] && g.weights[u][v] && path_length[u] != INT_MAX && path_length[u] + g.weights[u][v] < path_length[v])
				path_length[v] = path_length[u] + g.weights[u][v]; 
		}
	}
	// calculate average path length
	double avg = average_distance(g, path_length);
	return avg;
}

int main(void){
    unsigned int n = 0;
    unsigned int density = 0;
    unsigned int range = 0;
    unsigned int ref_vertex = 0;
    srand(time(NULL));
    std::cout<<"Enter the number of vertices for the graph"<<std::endl;
    std::cin>>n;
    std::cout<<"Enter what can be the maximum weight"<<std::endl;
    std::cin>>range;
    std::cout<<"Enter the reference vertex: "<<std::endl;
    std::cin>>ref_vertex;
    int N = 100;        ///< Monte Carlo simulation for N times
    /*! Perform Monte Carlo simulation for N iterations, for 20% and 40% density and 1 to 100 weight range*/
    int densities[2] = {20, 40};
    double sum_of_average_distances = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= N; j++){
            /*! Create a graph object */
            Graph g(n);                         ///< Pass the value of n to create a graph of 'n' vertices
            /*! Assign random weights to the graph */
            g.fill_weight_matrix(densities[i], range);
            sum_of_average_distances += dijkstra(g, ref_vertex);
        }
        std::cout<<"Average path length for density: "<<densities[i]<<"%, after performing "<<N<<" simulations: "<<( (sum_of_average_distances)/N )<<std::endl;        
    }

    return 0;

}