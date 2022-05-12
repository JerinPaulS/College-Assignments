#include <stdio.h>
#include <iostream>
// #include <stack>
// #include <queue>

using namespace std;

class Stack
{
    int top,size,*arr;
    public:
    Stack()
    {
        size=10;
        top=0;
        arr=new int[size];
    }
    Stack(int size)
    {
        this->size=size;
        top=0;
        arr=new int[size];
    }
    void push(int);
    int pop();
    bool empty();
    friend class ListGraph;
};

void Stack::push(int data)
{
    if(top==size)
    {
        cout<<"\nStack Overflow";
    }
    else
    {
        arr[++top]=data;
    }
    return;
}

int Stack::pop()
{
    if(top==0)
    {
        cout<<"\nStack Underflow";
        return 0;
    }
    else
    {
        return arr[top--];
    }
}

bool Stack::empty()
{
    if(top==0)
        return true;
    else
        return false;
}

class Queue
{
    int front,rare,size,*arr;
    public:
    Queue()
    {
        front=1;
        rare=0;
        size=10;
        arr=new int[size];
    }
    Queue(int size)
    {
        front=1;
        rare=0;
        this->size=size;
        arr=new int[size];
    }
    void enqueue(int);
    int dequeue();
    bool empty();
    friend class ListGraph;
};

void Queue::enqueue(int data)
{
    if(rare==size)
        cout<<"\nQueue if FULL!";
    else
    {
        arr[++rare]=data;
    }
}

int Queue::dequeue()
{
    if(rare<front)
        cout<<"\nQueue is EMPTY!";
    else
    {
        return arr[front++];
    }
}

bool Queue::empty()
{
    if(rare<front)
        return true;
    else
        return false;
}

class Vertex
{
    int v;
    Vertex *next;

public:
    Vertex()
    {
        v = 0;
        next = NULL;
    }
    Vertex(int d)
    {
        v = d;
        next = NULL;
    }
    friend class ListGraph;
    // friend class Stack;
};

class ListGraph
{
    Vertex **listOfVertices;
    int noOfVertices, *visited;

public:
    ListGraph()
    {
        noOfVertices = 0;
        listOfVertices = new Vertex *[noOfVertices];
        for (int i = 1; i <= noOfVertices; i++)
        {
            listOfVertices[i] = NULL;
        }
    }
    ListGraph(int v)
    {
        noOfVertices = v;
        listOfVertices = new Vertex *[noOfVertices];
        for (int i = 1; i <= noOfVertices; i++)
        {
            listOfVertices[i] = NULL;
        }
    }
    void visit();
    void create();
    void DFS(int);
    void BFS(int);
    void display();
};

void ListGraph::visit()
{
    visited=new int[noOfVertices];
    for (int i = 1; i <= noOfVertices; i++)
    {
        visited[i]=0;
    }
}

void ListGraph::create()
{
    int s, d;
    Vertex *dest;
    cout << "\nEnter the two vertices to form link between them.";
    for (int i = 1; i <= noOfVertices; i++)
    {
        cout<<"\nEnter first vertex aka Source : ";
        cin >> s;
        cout << "\nEnter second vertex aka Destination: ";
        cin >> d;
        dest = new Vertex(d);
        if (listOfVertices[s] == NULL)
        {
            listOfVertices[s] = dest;
        }
        else
        {
            Vertex *temp = listOfVertices[s];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = dest;
        }
    }
}

void ListGraph::DFS(int source)
{
    Stack s(15);
    int v;
    Vertex *temp;
    visit();
    visited[source]=1;
    s.push(source);
    cout<<"\nDFS:";
    while(!s.empty())
    {
        v=s.pop();
        cout<<"\t"<<v;
        temp=listOfVertices[source];
        while(temp!=NULL)
        {
            if(visited[temp->v]!=1)
            {
                s.push(temp->v);
                visited[temp->v]=1;
            }
            temp=temp->next;
        }
    }
}

void ListGraph::BFS(int source)
{
    Queue q(15);
    int v;
    Vertex *temp;
    visit();
    visited[source]=1;
    q.enqueue(source);
    cout<<"\nBFS:";
    while (!q.empty())
    {
        v=q.dequeue();
        cout<<"\t"<<v;
        temp=listOfVertices[source];
        while(temp!=NULL)
        {
            if(visited[temp->v]!=1)
            {
                q.enqueue(temp->v);
                visited[temp->v]=1;
            }
            temp=temp->next;
        }
    }

}

void ListGraph::display()
{
    Vertex *temp;
    int count=1;
    do
    {
        temp = listOfVertices[count];
        cout << "\n"
             << count
             << ": ";
        while (temp != NULL)
        {
            cout << temp->v << "->";
            temp = temp->next;
        }
        cout<<"NULL";
        count++;
    }while(count<=noOfVertices);

    cout<<"\nQueue:";
    int d;
    Queue q;
    while(!q.empty())
    {
        d=q.dequeue();
        cout<<d<<" ";
    }
    return;
}

int main()
{
    int ch;
    char repeat;
    bool yn=true;
    int pass,s;
    cout << "Enter number of vertices: ";
    cin >> pass;
    ListGraph lg(pass);
    while (yn == true)
    {
        cout << "\n1. Create"
                "\n2. DFS"
                "\n3. BFS"
                "\n4. Display"
                "\n5. Exit"
                "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            lg.create();
            break;

        case 2:
            cout << "\nEnter the source vertex for DFS: ";
            cin >> s;
            lg.DFS(s);
            break;

        case 3:
            cout << "\nEnter the source vertex for BFS: ";
            cin >> s;
            lg.BFS(s);
            break;

        case 4:
            lg.display();
            break;

        case 5:
            return 0;

        default:
            break;
        }
        cout << "\nDo you want to continue (y/n or 1/0) ? : ";
        cin >> repeat;
        if(repeat=='n'||repeat=='N'||repeat=='0')
            yn=false;
    }
    return 0;
}
