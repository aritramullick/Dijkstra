#include <iostream>
#include <vector>
#include<string>
#include <list>
#include <algorithm>

using namespace std;

int n;
int **adjMat;
vector <int> vertices;    

struct path 
{
    int distance;
    string path;
};

struct node
{
    int vertexNum;
    vector <node*> next;
};

bool contains(int a, vector<int> arr)
{
    for (int i = 0; i< arr.size() ; i++)
    {
        if (arr[i]==a)
            return true;
    }
    return false;
}
void deleteElem(vector<int> &a, int val)
{
    for (int i = 0; i<a.size(); i++)
        if (a[i]==val)
        {
            for (int j = i; j<a.size()-1; j++)
            {
                a[j]=a[j+1];
            }
            a.pop_back();
        }
}
void lowestDistanceWithIndex(vector <int> arr, int &i, int &lowestDistance)
{
    i=-1;
    int min=100;
    for (int j = 0; j<n; j++)
    {
        if (arr[j]<min && contains(j,vertices))
        {
            min=arr[j];
            i=j;
        }
        else
        {
            continue;
        }
        
    }
    lowestDistance=min;
}
//can represent a weighted graph with adjacent matrix made up with a 2D array/vector of integers


vector<int> findShortestRoute(int a, int b) //where a is the starting vertex on the matrix, b is the ending vertex
{
    vector <int> distances; //the values keep a track of the distances (L(v))          
    distances.resize(n);
    vertices.resize(n);
    for (int i = 0; i<n ; i++)
    {
        vertices[i]=i;
    }
    
    // path p;
    // if (a==b)
    // {
    //     p.distance=0;
    //     p.path="N/A";
    //     return distances;
    // }
    for (int i = 0; i<n; i++)
    {
        distances[i]=100;
    }
    distances[a]=0; //setting distance to only the beginning vertex to be 0
    
    while (contains(b,vertices))
    {
        int vertexNum, lowestDistance;
        lowestDistanceWithIndex(distances, vertexNum, lowestDistance);
        cout<<endl<<"This is the smallest distance vertex for this iteration: "<<vertexNum<<endl;
        deleteElem(vertices, vertexNum);
        int *adjacentArray = adjMat[vertexNum];
        cout<<"The vertices are : ";
          for (int x= 0 ; x<vertices.size() ; x++)
        {
            cout<<vertices[x]<<" ";
        }
        cout<<"\nThe elements of the adjacent array are: ";
         for (int x= 0 ; x<n ; x++)
        {
            cout<<adjacentArray[x]<<" ";
        }
        
        for (int x= 0 ; x<n ; x++)
        {
            if (contains(x,vertices))
                distances[x]=min(distances[x], distances[vertexNum]+adjacentArray[x]);
        }
        cout<<"\nDistance is: ";
         for (int x= 0 ; x<n ; x++)
        {
            cout<<distances[x]<<" ";
        }
    }
    return distances;
}


int main()
{
   //cin>>n;
   n=4;
   adjMat= new int* [n];
//    for (int i = 0; i<n; i++)
//    {
//        adjMat[i]=new int [n];
//    }
   int temp1[]= {0,10,5,1};
   int temp2[]={10,0,10,1};
   int temp3[]={5,10,0,2};
   int temp4[]={1,1,2,0};
   
   adjMat[0]=temp1;
   adjMat[1]=temp2;
   adjMat[2]=temp3;
   adjMat[3]=temp4;
   cout<<"The Adjacency Matrix is of the form : \n";
    for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++)
        cout<<adjMat[i][j]<<" ";
    cout<<endl;
   }
   vector <int> distances = findShortestRoute(0,3);
    cout<<"\n///////////////\nThe Shortest Distances are:\n";
   for (int i = 0; i< n ; i++)
        cout<<distances[i]<<" ";
    
    // for (int i = 0; i<n; i++)
    // {
    //     delete [] adjMat[i];
    // }
    cout<<endl;
    delete [] adjMat;
       
    return 0; 
        
  
   
}