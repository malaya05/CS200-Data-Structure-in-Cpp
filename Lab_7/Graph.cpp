/*
	Mendoza, Moises
	Alaya, Jason
	jawad Almashash Swed

	CS A200
	November 17, 2017

	Lab 7
*/
#include "Graph.h"

// Definition overloaded insertion operator
ostream& operator<<(ostream& out, const Graph& obj)
{
	if (obj.numOfVertices > 0)
	{
		out << " ";
		for (int i = 0; i < obj.numOfVertices; ++i)
			out << " " << obj.vertices[i];
		out << endl;
		for (int i = 0; i < obj.numOfVertices; ++i)
		{
			out << obj.vertices[i];
			for (int j = 0; j < obj.numOfVertices; j++)
				out << " " << obj.matrix[i][j];
			out << endl;
		}
	}
	else
		out << "Graph is empty." << endl;
	return out;
}

// Default constructor
Graph::Graph()
{
	maxVertices = MAX_VERTICES;
	numOfVertices = 0;
	vertices = new char[maxVertices];
	matrix = new int*[maxVertices];

	for (int i = 0; i < maxVertices; ++i)
		matrix[i] = new int[maxVertices]();
}

// Overloaded constructor
Graph::Graph(int vert)
{
	maxVertices = vert;
	numOfVertices = 0;
	vertices = new char[maxVertices];
	matrix = new int*[maxVertices];

	for (int i = 0; i < maxVertices; ++i)
		matrix[i] = new int[maxVertices]();
}

// Definition function createGraph
void Graph::createGraph(const string& fileName)
{
	ifstream infile;

	infile.open(fileName);

	if (!infile)
	{
		cerr << "Cannot open the input file." << endl;
		system("Pause");
		exit(0);
	}

	infile >> numOfVertices;

	// FOR loop to populate the array of characters.
	// Your code here...
	for (int i = 0; i < numOfVertices; ++i)
		infile >> vertices[i];

	// FOR loop to populate the 2-dimensional array.
	// Your code here...
	for (int i = 0; i < numOfVertices; ++i)
		for (int j = 0; j < numOfVertices; ++j)
			infile >> matrix[i][j];

	infile.close();
}

// Declaration function getNumOfVertices
int Graph::getNumOfVertices() const
{
	return numOfVertices;
}

// Definition function clearGraph
void Graph::clearGraph()
{
	for (int i = 0; i < numOfVertices; ++i)
	{
		delete[] matrix[i];
		matrix[i] = new int[maxVertices]();
	}
}

// Destructor
Graph::~Graph()
{
	delete[] vertices;
	for (int i = 0; i < maxVertices; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

// bfsSequence
void Graph::bfsSequence(vector<char>& v) const
{
	vector<int> visited(numOfVertices, 0);
	queue<int> q;
	q.push(0);
	int count = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		v[count++] = vertices[curr];
		visited.at(curr) = 2;
		for (int i = 0; i < numOfVertices; i++)
		{
			if (matrix[i][curr] == 1 && visited.at(i) == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}

	cout << "BFS: ";
}

// dfsSequence
void Graph::dfsSequence(vector<char>& v) const
{
	vector<int> visited(numOfVertices, 0);
	stack<int> s;
	s.push(0);
	visited[0] = 1;
	int count = 0;

	while (!s.empty())
	{
		int curr = s.top();
		for (int i = 0; i < numOfVertices; i++)
		{
			if (matrix[i][curr] == 1 && visited.at(i) == 0)
			{
				s.push(i);
				visited[i] = 1;
				curr = i;
				i = -1;
			}
		}
		v[count++] = vertices[curr];
		visited.at(curr) = 2;
		s.pop();
	}

	cout << "DFS: ";
}