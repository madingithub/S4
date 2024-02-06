#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front=-1,rear=-1;

//Graph represented as an adjacency matrix
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

int enqueue(int vertex){
    if(rear==MAX_VERTICES-1){
        printf("Queue is full.Cannot enqueue.\m");
        return; 
    }
    if (front==-1)
    front=0;
    rear++;
    queue[rear]=vertex;
}
int dequeue(){
    if (front==-1){
        printf("Queue is Empty.Cannot Dequeue.\n");
        return-1;
    }
    int vertex=queue[front];
    front++;
    if (front>rear)
    front=rear=-1;
    return vertex;
}
void bfs(int startVertex){
    enqueue(startVertex);
    visited[startVertex]=1;
    while(front!=-1){
        int currentVertex=dequeue();
        printf("%d",currentVertex);

        for(int i=0;i<numVertices;i++){
            if(graph[currentVertex][i]==1&&!visited[i]){
                enqueue(i);
                visited[i]=1;
            }
        }
    }
}

void dfs(int vertex){
    printf("%d",vertex);
    visited[vertex]=1;

    for(int i=0;i<numVertices;i++){
        if(graph[vertex][i]==1&&!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    printf("Enter the number of Vertices in the Graph:");
    scanf("%d",&numVertices);

    printf("Enter the adjacency Matrix:\n");
    for(int i=0;i<numVertices;i++){
    for(int j=0;j<numVertices;j++){
        scanf("%d",&graph[i][j]);
    }
    }
    printf("BFS Travel:");
    bfs(0);

    //Reset Visited array for DFS traversal
    for (int i=0;i<numVertices;i++){
        visited[i]=0;
        

    }
    printf("\nDFS Travesal:");
    dfs(0);
    printf("\n");

    return 0;
    }