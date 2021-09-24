#include<iostream>
#include <bits/stdc++.h> 
using namespace std;
char wor[27]={0};
int times;
struct node{
	int number;
	char alp;
	struct node* left = NULL;
	struct node* right = NULL;
};
node* rem[27];
void CharWithFreq(string str) 
{ 
    
    int n = str.size(); 
    int freq[27],flag[27];
    int e=0;
    memset(freq, 0, sizeof(freq)); 
    for (int i = 0; i < n; i++)
	{
		freq[str[i] - 'a']++; 
		flag[str[i] - 'a']=1;
	} 
        
    
    for (int i = 0; i < n; i++)
	{ 
        if (flag[str[i] - 'a'] != 0) 
		{ 
            //cout << str[i] << freq[str[i] - 'a'] << " "; 
            if(str[i]!=' ')
            	wor[e++]=str[i];

			flag[str[i] - 'a']=0;	
        } 	
    } 
    times=e;
    for(int i=0;i<times;i++)
    {
    	for(int i=0;i<times-1;i++)
    	{
	    	for(int j=0;j<times-1-i;j++)
	    	{
	    		if (freq[wor[i]-'a']<freq[wor[i+1]-'a'])
	    		{
	    			int temp;
	    			temp=wor[i];
	    			wor[i]=wor[i+1];
	    			wor[i+1]=temp;
				}
			}
    	
		}
	}
    
	for(int i=0;i<times;i++)
    {
    	cout <<wor[i]<<" "<<freq[wor[i] - 'a'] << endl; 
	}

} 

int main()
{
	int lines;
	char word[30];
	cin>>lines>>word;
	string str,str_total;
	for(int i=0;i<=lines;i++)
	{
		getline(cin,str);
		str_total+=str;
	} 
	CharWithFreq(str_total);
	
		
	
	
	
	
	return 0;
}

