#include <iostream>
#include <cstdlib>
#include <ctime>

class Graph{
    public:
    Graph(unsigned int n):V(n){}
    void set_weight(unsigned int node1, unsigned int node2, unsigned int weight){
        this->weights[node1][node2] = weight;
    }
    unsigned int get_weight(unsigned int node1, unsigned int node2){
        return this->weights[node1][node2];
    }
    unsigned int get_max_number_of_edges(void){
        return ((this->V)*(this-V - 1)/2);
    }
    void fill_weight_matrix(unsigned int density_percent, unsigned int range){
        unsigned int number_of_edges_allowed = (<static_cast>(float)density_percent / 100.0) * get_max_number_of_edges; 
        unsigned int count_edges = 0;
        for(int i = 0; i < this->V; i++){
            srand(time(NULL));
            this->weights[i][i] = 0;            
            for(int j = i+1; j < this->V; j++){
                if(i == rand()%this->V && j == rand()%this->V){
                    if (count_edges <= number_of_edges_allowed){
                        this->weights[i][j] = this->weights[j][i] = rand()%100;
                        count_edges++;
                    }
                    else{
                        return;
                    }
                }       
            }
        }
    }
    private:
    unsigned int V;                 ///< Number of vertices in the graph
    unsigned int weights[V][V];     ///< Weights matrix
    unsigned float density;         ///< Density of the matrix
}

int main(void){
    unsigned int n = NULL;
    srand(time(NULL));
    cout<<"Enter the number of vertices for the graph"<<endl;
    cin>>n;
    /*! Create a graph object */
    Graph g(n);                         ///< Pass the value of n to create a graph of 'n' vertices
    /*! Assign random weights to the graph */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
        }
    }
}