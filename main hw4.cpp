#include<iostream>
#include <queue>
#define t 3
using namespace std;
char game[t][t];
int flag;
void printwin(char game[t][t]);
struct node
{
    int ID, Xpos, Ypos;
    char mark;
    node* parent;
    node* leftchild;
    node* rightchild;
    
};
node* treeroot(int a, int b, int c, char type)
{
    node* root= new node;
    root->ID=a;
    root->Xpos=b;
    root->Ypos=c;
    root->mark=type;
    root->leftchild=NULL;
    root->rightchild=NULL;
    return root;
}
void adding(node* current,int a, int b, int c, char d)
{
    node* new_one = new node;/////su
    new_one->ID=a;
    new_one->Xpos=b;
    new_one->Ypos=c;
    new_one->mark=d;
    new_one->leftchild=NULL;
    new_one->rightchild=NULL;
    new_one->parent=current;
    if(current->leftchild==NULL)
        current->leftchild=new_one;
    else if(current->rightchild==NULL)
        current->rightchild=new_one;
    return;
}
node*findthenode;///su
node* findnode(node* current,int lastone)
{
    
    if(current != NULL){///su
    if(current->ID!=lastone)
    {
        findnode(current->leftchild,lastone);
        findnode(current->rightchild,lastone);
    }
    if(current->ID==lastone)
        findthenode = current;
        return current;
    
}
    return NULL;////su
}

bool win(char game[t][t])
{

    if((game[0][0]=='O'&&game[0][1]=='O'&&game[0][2]=='O')||(game[0][0]=='X'&&game[0][1]=='X'&&game[0][2]=='X'))
    	return true;
    if((game[1][0]=='O'&&game[1][1]=='O'&&game[1][2]=='O')||(game[1][0]=='X'&&game[1][1]=='X'&&game[1][2]=='X'))
    	return true;
    if((game[2][0]=='O'&&game[2][1]=='O'&&game[2][2]=='O')||(game[2][0]=='X'&&game[2][1]=='X'&&game[2][2]=='X'))
    	return true;
    if((game[0][0]=='O'&&game[1][0]=='O'&&game[2][0]=='O')||(game[0][0]=='X'&&game[1][0]=='X'&&game[2][0]=='X'))
    	return true;
	if((game[0][1]=='O'&&game[1][1]=='O'&&game[2][1]=='O')||(game[0][1]=='X'&&game[1][1]=='X'&&game[2][1]=='X'))
    	return true;
    if((game[0][2]=='O'&&game[1][2]=='O'&&game[2][2]=='O')||(game[0][2]=='X'&&game[1][2]=='X'&&game[2][2]=='X'))
    	return true;
    if((game[0][0]=='O'&&game[1][1]=='O'&&game[2][2]=='O')||(game[0][0]=='X'&&game[1][1]=='X'&&game[2][2]=='X'))
		return true;
    if((game[0][2]=='O'&&game[1][1]=='O'&&game[2][0]=='O')||(game[0][2]=='X'&&game[1][1]=='X'&&game[2][0]=='X'))
        return true;
    else
    	return false;
}
void preorder(node*current)
{
    //printwin(game);
    if(current!=NULL)
    {
       
        int x=current->Xpos;
        int y=current->Ypos;
        game[x][y] = current->mark;
        if(win(game)==true)
        {
            flag=1;
            return;
        }
        preorder(current->leftchild);
        preorder(current->rightchild);
        game[x][y] = '_';
    }
    
}
void printwin(char game[t][t])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(game[j][i]=='O'||game[j][i]=='X')
            	cout<<game[j][i];
            else
                cout<<'_';
        }
        cout<<endl;
    }
}
void postorder(node* current)
{
    if(current==NULL)
        return;
    postorder(current->leftchild);
    postorder(current->rightchild);
    cout<<current->Xpos<<" "<<current->Ypos<<" "<<current->mark<<endl;
}

int main()
{
    int times,ID,lastone,Xpos,Ypos;
    char mark;
    
    cin>>times;
    cin>>ID>>lastone>>Xpos>>Ypos>>mark;
    node* root=treeroot(ID,Xpos,Ypos,mark);
    
    for(int i=0;i<(times-1);i++)
    {
        //cout<<"yey"<<endl;
        cin>>ID>>lastone>>Xpos>>Ypos>>mark;
        //cout<<lastone;
        //cout<<"hi"<<endl;
        findnode(root,lastone);//////////
        adding(findthenode,ID,Xpos,Ypos,mark);//////su
        //cout<<new_one->ID;
    }
    //postorder(root);
    preorder(root);
    if(flag==1)
    {
        cout<<"win"<<endl;
        printwin(game);
    }
    else if(flag==0)
    {
        cout<<"tie"<<endl;
        postorder(root);
    }
    return 0;
}
