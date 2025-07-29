#include<stdio.h>

struct Edge{
    int source;
    int destination;
    int weight;
};

void sortEdges(struct Edge edges[],int E){

    for(int i = 0; i < E; i++){
        
        struct Edge key = edges[i];

        int j = i-1;
        while(j>=0 && edges[j].weight > key.weight){
            edges[j+1] = edges[j];
            j--;
        }
        edges[j+1] = key;
    }
}

int find(int i,int parent[]){
    if(parent[i] == i){
        return i;
    }
    return find(parent[i],parent);
}

void unions(int src,int dest,int parent[]){
    parent[find(dest,parent)] = find(src,parent);
}

void main(){
    int E = 5,totalweight = 0;
    int parent [E];
    struct Edge edges[] = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    sortEdges(edges,E);

    for(int i = 0; i < E; i++){
        parent[i] = i;
    }

    for(int i = 0; i < E; i++){
        int src = edges[i].source;
        int dest = edges[i].destination;
        int weight = edges[i].weight;

        if(find(src,parent) != find(dest,parent)){
            unions(src,dest,parent);
            totalweight += weight;
        }
    }

    printf("Total weight : %d",totalweight);
}