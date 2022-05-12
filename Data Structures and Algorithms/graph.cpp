#include<iostream>
#define MAX 50
using namespace std;

class Node2
{
    private:
		string place;
		int visited;
		Node2 *next;
    public:
		Node2()
		{
		    place="NULL";
		    visited=0;
		    next=NULL;
		}
		Node2(string landmark)
		{
		    place=landmark;
		    visited=0;
		    next=NULL;
		}
    friend class Node1;
    friend class Graph;
};

class Node1
{
	private:
		string place;
		int visited;
		Node1 *down;
		Node2 *next;
	public:
		Node1()
		{
		    place="NULL";
		    visited=0;
		    down=NULL;
		}
		Node1(string landmark)
		{
		    place=landmark;
		    visited=0;
		    down=NULL;
		}
    friend class Node2;
    friend class Graph;
};

class Graph
{
    private:
        Node1 *header;
    public:
		Graph()
		{
		    header= new Node1();
		    cout<<"***Graph of PICT***";
		}
		void get_info()
		{
		    string place,neighbour;
		    int choice,control;
		    do
		    {
		        cout<<"\nEnter a place (vertex): ";
		        cin>>place;
		        Node1 *temp1= new Node1(place);
		        insert1(temp1);
		        do
		        {
		            cout<<"\nEnter neighbour of "<<temp1->place<<" : ";
		            cin>>neighbour;
		            Node2 *temp2 = new Node2(neighbour);
		            insert2(temp1,temp2);
		            cout<<"Enter '1' to continue and '0' to stop (neighbor).";
		            cin>>control;
		        } while (control!=0);
		        
		        cout<<"Enter 1 to continue and 0 to stop (vertex).";
		        cin>>choice;
		    } while (choice!=0);
		    
		}
		void insert1(Node1 *temp1)
		{
		    if(header->place=="NULL")
		    {
		        header=temp1;
		        cout<<"Header updated"<<endl;
		    }
		    else
		    {
		        Node1 *temp=header;
		        while(temp->down != NULL)
		        {
		            temp=temp->down;
		        }
		        cout<<"Vertex inserted below"<<temp->place<<endl;
		        temp->down=temp1;
		    }
		}
		void insert2(Node1* p1,Node2* p2)
		{
		    if(p1->next==NULL)
		    {
			    cout<<"Edge added after"<<p1->place<<endl;
		        p1->next=p2;
		    }
		    else
		    {
		        Node2 *t=p1->next;
		        while(t->next!=NULL)
		        {
		            t=t->next;
		        }
		        cout<<"Edge added after"<<t->place<<endl;
		        t->next=p2;
		    }
		}
		void display()
		{
		    Node1 *dptr=header;
		    while(dptr!=NULL)
		    {
		        cout<<dptr->place<<"->";
		        Node2 *right=dptr->next;
		        while(right!=NULL)
		        {
		            cout<<right->place<<"->";
		            right=right->next;
		        }
		        dptr=dptr->down;
		        cout<<"\n"<<endl;
		    }
		}
};

int main()
{
    Graph G;
    G.get_info();
    G.display();
    return 0;
}
