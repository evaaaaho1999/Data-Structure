#include<iostream>
#define T 500
using namespace std;
int passed[T][T]={0};//�٨S���L��0;���L��1 
//char memory_road[T];//�w�qstack 
char puzzle[T][T];//��puzzle�OT�j�p��matrix 
const int stack_max=30;
//char my_data[stack_max];
class CStack
{
	char my_data[stack_max];
	int top;
	int count;	
	public:
		
		bool isfull()
		{
			if(top==count-1)
				return true;
			else
				return false;
		}
		bool isempty()
		{
			if(top==-1)
				return true;
			else
				return false;
		}
		void push(char data)
		{
			if(isfull())
			{
				return; 
			}
			my_data[++top]=data;
			
		} 
		void pop()
		{
			if(isempty())
			{
				return;
			}
			top--;	
		}
		char Cs_top()
		{
			return my_data[top];
		}
		int size()
		{
			return top+1;
		}
		/*void printStack()
		{
			cout<<"Stack: ";
			for (int i=0;i<top;i++){
				cout<<my_data[i];
			}
			cout<<endl;
		}*/                             //test
		
		
		CStack();
		~CStack(){}
};
CStack::CStack()//�ե� CStack�̪��ܼ� 
{
	top = -1;
	count = stack_max;
}
void printStack(char a[],char b[],int j)
{
	for(int i=0;i<j;i++)
	{
		cout<<a[i];
	}
	cout<<" ";
	for(int i=0;i<j;i++)
	{
		cout<<b[i];
	}
	cout<<endl;
}
int alp(char x)
{
	
	switch(x)
     {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        return 1;
        break;                      //break�y�k�������A�p�G���[�W�|�������H�U���O
        default:                   //default:  �����O�����ŦX�e��case���@����A�h�k���� 
        return 2; 
        
     } 
}
CStack memory_road;
void counting()
{
	int i,j=memory_road.size(),v=0,c=0,vl=0,cl=0;
	char ord[j];
	char adj[j];
	for(i=j-1;i>=0;i--)
	{
		ord[i]=memory_road.Cs_top();
		if(alp(ord[i])==1)
			v++;
		else
			c++;
		memory_road.pop();
	}
	
	for(i=0;i<j;i++)
	{
		memory_road.push(ord[i]);
	}
		
	if(c<3)
		return;	 
	for(i=0;i<j;i++)
	{
		if(alp(ord[i])==1)
		{
			adj[vl]=ord[i];
			vl++;
		}
		else
		{
			adj[v+cl]=ord[i];
			cl++;
		}
	}
	printStack(ord,adj,j);
	
	
}
//r:row,c:col,num:matirx size,step:ttl words 

void cv_rules(int r,int c,int num,int step)
{
	char word;
	word=puzzle[r][c];
	
	
	passed[r][c]=1;
	memory_road.push(word);
	//memory_road.printStack();
	if(step>=5&&alp(word)==2)
	{
		counting();
	}

	
		//memory_road.called();
		//return;
		//step=0;
	
	
	if(alp(word)==2)
	{
		//cout<<"x:"<<r<<"y:"<<c<<endl;
		if((alp(puzzle[r+1][c])==1)&&(r+1<num)&&(passed[r+1][c]==0))
			cv_rules(r+1, c, num, step+1);	
		if((alp(puzzle[r][c+1])==1)&&(c+1<num)&&(passed[r][c+1]==0))
			cv_rules(r, c+1, num, step+1);	
		if((alp(puzzle[r-1][c])==1)&&(r-1>=0)&&(passed[r-1][c]==0))
			cv_rules(r-1, c, num, step+1);	
		if((alp(puzzle[r][c-1])==1)&&(c-1>=0)&&(passed[r][c-1]==0))
			cv_rules( r, c-1, num, step+1);

		//cout<<"pop"<<endl;
		passed[r][c]=0;
		memory_road.pop();
		return;
	}
	
	else
	{
		if((passed[r+1][c]==0)&&(r+1<num))
			cv_rules( r+1, c, num, step+1);		
		if((passed[r][c+1]==0)&&(c+1<num))
			cv_rules( r, c+1, num, step+1);	
		if((passed[r-1][c]==0)&&(r-1>=0))
			cv_rules( r-1, c, num, step+1);
		if((passed[r][c-1]==0)&&(c-1>=0))
			cv_rules(r, c-1, num, step+1);
		passed[r][c]=0;
		//cout<<"pop"<<endl;
		
		memory_road.pop();
		return;
	}
	//cout<<"pop"<<endl;
	passed[r][c]=0;
	memory_road.pop();
	
}



int main()
{
	char word;
	alp(word);//��O�l�������A�����O1�l���O2
	int num;
	
	cin>>num;//�T�w�x�}�j�p 
	
	//�g�Jword puzzle 

	for(int i=0;i<num;i++)
	{
		for(int j=0;j<num;j++)
		{
			cin>>puzzle[i][j];
			passed[i][j]=0;
		}
	}
	
	int row,col;

	for(row=0;row<num;row++)
	{	for(col=0;col<num;col++)
		{
			if(alp(puzzle[row][col])==2)
				cv_rules(row, col, num, 1);
		}
	}	
		
	return 0;
}


