#include<iostream>
using namespace std;
class Queue {

	int *q;
	int front;
	int rear;
	int size;
public:
	Queue(int n) {

		q = new int[n];
		size = n;
		front = -1;
		rear = -1;
	}
	void enqueue(int val) {

		if(rear >= size) {

			rear = -1;
			return;
		}
		else if(front == -1 && rear == -1) {

			front = 0;
			rear = 0;
			q[rear] = val;
		}
		else {

			rear++;
			q[rear] = val;
		}
	}

	int dequeue() {

		if(front >= size) {

			front = -1;
			return -1;
		}
		else {

			int ret = q[front];
			front++;
			return ret;
		}
	}

	bool Empty() {

		if((front == -1 && rear == -1)||(front>rear))
			return true;
		else
			return false;
	}
};

class Stack {

	int top;
	int *s;
public:
	Stack(int size) {

		top = -1;
		s = new int[size];
	}

	void push(int val) {

		s[++top] = val;
	}

	int pop() {

		if(top == -1)
			//exit(0);
			return -1;
		else {
			int temp = s[top];
			top--;
			return temp;
		}
	}

	bool Empty() {

		if(top == -1)
			return true;
		else
			return false;
	}
};

class Graph {

	int vertices;
	int **adjency;
public:

	Graph() {

		cout<<"Enter number of vertices\n";
		cin>>vertices;
	}
	void creategraph() {

		adjency = new int*[vertices];
		for(int i=0;i<vertices;i++)
			adjency[i] = new int[vertices];
		for(int i=0;i<vertices;i++) {

			for(int j=0;j<vertices;j++) {

				if(i == j)
					adjency[i][j] = 0;
				else {
					cout<<"Enter adjencies for vertices "<<i<<" and "<<j<<endl;
					cin>>adjency[i][j];
				}
			}
		}
	}

	void printAdj() {

		for(int i=0;i<vertices;i++) {

			for(int j=0;j<vertices;j++) {

				cout<<adjency[i][j]<<"\t";
			}
			cout<<endl;
		}
	}

	void insertedge() {

		int f_vertex,l_vertex;
		cout<<"Enter first vertex\n";
		cin>>f_vertex;
		cout<<"Enter last vertex\n";
		cin>>l_vertex;
		adjency[f_vertex][l_vertex]++;
		adjency[l_vertex][f_vertex]++;
	}

	void deleteedge() {

		int f_vertex,l_vertex;
		cout<<"Enter first vertex\n";
		cin>>f_vertex;
		cout<<"Enter last vertex\n";
		cin>>l_vertex;
		if(adjency[f_vertex][l_vertex] > 0) {

			adjency[f_vertex][l_vertex]--;
			adjency[l_vertex][f_vertex]--;
		}
		else {

			adjency[f_vertex][l_vertex] = 0;
			adjency[l_vertex][f_vertex] = 0;
		}
	}

	void BFS() {

		int start;
		cout<<"Enter starting vertex\n";
		cin>>start;
		bool visited[vertices];
		for(int i = 0; i < vertices; i++)
			visited[i] = false;
		Queue q(vertices);
		visited[start] = true;
		q.enqueue(start);
		cout<<"BFS for given graph:-\n";
		int i = 0;
		int j = 0;
		int n;
		while(!q.Empty())
		{
			n = q.dequeue();
			j = 0;
			cout<<n<<" ";
			while(j<vertices) {

				if(adjency[n][j] == 1 && visited[j] == false) {

					visited[j] = true;
					q.enqueue(j);
				}
				j++;
			}
			i++;
		}
		cout<<endl;
	}

	void DFS() {

		int start;
		cout<<"Enter starting vertex\n";
		cin>>start;
		bool visited[vertices];
		for(int i = 0; i < vertices; i++)
			visited[i] = false;
		Stack S(vertices);
		visited[start] = true;
		int n;
		int i = 0;
		int j = 0;
		S.push(start);
		cout<<"DFS for given graph:-\n";
		while(!S.Empty())
		{
			n = S.pop();
			j = 0;
			cout<<n<<" ";
			while(j<vertices) {

				if(adjency[n][j] == 1 && visited[j] == false) {

					visited[j] = true;
					S.push(j);
				}
				j++;
			}
			i++;
		}
		cout<<endl;
	}
};

int main() {

	Graph g;
	g.creategraph();
	g.printAdj();
	g.BFS();
	g.DFS();
}
