#include<iostream>
#include<string>
using namespace std;
class busroute;
class Node
{
	public:
		string data;
		Node *next;
	friend class busroute;//busroute�i�H�ϥ�Node��private 		
};
class busroute
{
	public:
		//struct Node* first;//list���Ĥ@��node (head node)
		busroute();
		~busroute();//�غc�l�B�Ѻc�l  
		Node* CREATE(string str);
		void INSERT(Node *&ptr, string str2);
		Node* DELETE(Node*first,string name);//�M�����I 
		void print(Node*first);//�L�Xbus route 
};
busroute::busroute()
{
	Node* first=new Node;
	
	first->next=NULL;//��l�� 
}
busroute::~busroute()
{
	Node* current=new Node;
	//Node* prev=new Node;
	Node* first= new Node;
	Node* clear=new Node;
	if(first->next==NULL)
	{
		delete first;
		delete current;
		//delete prev;
	}
	else
	{
		current=first;
		while(current!=NULL)
		{
			clear=current;
			current=current->next;
			delete clear;
		}
		delete current;//�M�ŰO���� 
		//delete prev;
	}
} 

void busroute::print(Node* first)
{
	Node* current;
	current=first;
	for(current=first;current!=NULL;current=current->next)
	{
		if(current->next!=NULL&&((current->data)!=((current->next)->data)))
		{
			cout<<current->data<<"->";
		}
		else if(current->next!=NULL&&((current->data)==((current->next)->data)))
		{
			current=current->next;
			cout<<current->data<<"->";
		}
		else if(current->next==NULL)
		{
			cout<<current->data<<endl;
		}
	}
}
void busroute::INSERT(Node *&ptr, string str1)
{
	Node*added=new Node;
	added->data=str1;
	added->next=ptr->next;
	ptr->next=added;
	ptr=ptr->next;
} 
Node* busroute::CREATE(string str)
{
	Node* first=new Node;
	first->data=str;
	first->next=NULL;
	return first;
}

Node* busroute::DELETE(Node*first,string str4)
{
	if(first==NULL)
	{
		return NULL;
	}
	else
	{
		Node*prev=first;
		Node* current = first; 
		while(current!=NULL)
		{
			if(current->data==str4)
			{
				Node* clear=current;
				prev->next=current->next;
				current=current->next;		
				delete clear;
			}
			else
			{
				prev=current;
				current=current->next;
			}
		}
	}

	return first;
}
int main()
{
	busroute Route;
	int c;//����for�j��]������
	cin>>c;
	string type,src,dst,New,name;
	int a;//����insert���� 
	Node* current;
	Node* prev;
	Node* ptr;
	Node* first;
	//ptr=Route.getfirst();//ptr=first node, ptr->next=Null
	first=Route.CREATE("NTHU");
	ptr=first;
	Route.INSERT(ptr,"TSMC");
	Route.INSERT(ptr,"NTHU");
	
	for(int i=0; i<c; i++)
	{
		cin>>type;
		if(type=="INSERT")
		{	
			cin>>src>>dst>>New>>a;
			
			if(a==1)
			{
				current=first;
				while(current->next!=NULL)
				{	
					if(current->data==src&&current->next->data==dst)
					{
						Route.INSERT(current,New);
						//Route.print(first);
					}
					else
					{
						current=current->next;
					}
				}
			}
			
			if(a==2)
			{
				current=first;
				while(current->next!=NULL)
				{	
					if(current->data==src&&current->next->data==dst)
					{
						Route.INSERT(current,New);
						//Route.print(first);
					}
					else
					{
						current=current->next;
					}
				}
				prev=first;
				while(prev->next!=NULL)
				{
					if(prev->data==dst&&prev->next->data==src)
					{
						Route.INSERT(prev,New);
					}
					else
					{
						prev=prev->next;
					}
				}
			}	
		}
		if(type=="DELETE")
		{
			cin>>name;
			Route.DELETE(first,name);
		}
	}	
	Route.print(first);
	
	return 0;
}

