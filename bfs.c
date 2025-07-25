#include<stdio.h>
int n, mat[20][20], visited[20], queue[20], REAR=-1, FRONT=-1;

void readAdjacencyMatrix(){
printf("Enter no. of vertices");
scanf("%d", &n);
printf("Enter the Adjacency Matrix: \n");
for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
scanf("%d", &mat[i][j]);
}
}
}

void enqueue(int item){
if(REAR==-1 && FRONT==-1){
REAR=0;
FRONT=0;
}
else{
REAR=REAR+1;
}
queue[REAR]=item;
}

int dequeue(){
int item;
if(REAR==FRONT){
item = queue[FRONT];
FRONT=-1;
REAR=-1;
}else{
item = queue[FRONT];
FRONT+= 1;
}
return item;
}

void bfs(int v){
int i;
printf("%d \t", v);
visited[v] = 1;
enqueue(v);
while(FRONT != -1){
v = dequeue();
for(i=1; i<=n; i++){
if(mat[v][i] && !visited[i]){
visited[i]=1;
enqueue(i);
printf("%d \t", i);
}
}
}
}

void main(){
int i;
readAdjacencyMatrix();
bfs(0);
}

