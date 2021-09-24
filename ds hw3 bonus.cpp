#include<iostream>
#include<string>
using namespace std;
int c;
class busroute;
class Node
{
	public:
		string data;
		Node *next;
	friend class busroute;//busroute可以使用Node的private 		
};
class busroute
{
	public:
		//struct Node* first;//list的第一個node (head node)
		busroute();
		~busroute();//建構子、解構子  
		Node* CREATE(string str);
		void INSERT(Node *&ptr, string str2);
		Node* DELETE(Node*first,string name);//清除站點 
		void print(Node*first);//印出bus route 
		Node* REVERSE(Node*first);//reverse 函式 
};
busroute::busroute()
{
	Node* first=new Node;
	
	first->next=NULL;//初始化 
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
		delete current;//清空記憶體 
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
Node* busroute::REVERSE(Node*first)
{
	if(first==0||first->next==0)
	{
		return first;
	}
	Node* previous=0;
	Node* current=first;
	Node* preceding =first->next;
	while(preceding!=0)
	{
		current->next=previous;
		previous=current;
		current=preceding;
		preceding=preceding->next;
	}
	current->next=previous;
	first=current;
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
void input()
{
	cin>>c;
	return;
}
int main()
{
	busroute Route;
	input();
	
	string type,src,dst,New,name;
	int a;//紀錄insert類型 
	Node* current;
	Node* prev;
	Node* ptr;
	Node* first;
	//ptr=Route.getfirst();//ptr=first node, ptr->next=Null
	first=Route.CREATE("NTHU");
	ptr=first;
	Route.INSERT(ptr,"TSMC");
	Route.INSERT(ptr,"NTHU");
	int i=0;
	while(i<c)
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
		if(type=="REVERSE")
		{
			first=Route.REVERSE(first);
		}
		i++;
	}	
	Route.print(first);
	
	return 0;
}

