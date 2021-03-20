#include <iostream> 
#include <fstream> 
#include <string.h>

  
using namespace std; 
  

int main() 
{ 
    fstream file,fout; 
	char g[10][100], word[100];
	int pr[100],flag=0,i=0,k=0,l=0,z=0,b=0,j=0,n,s,t[100],p=0,q=0; 
    file.open("input.txt", ios::in |ios::app);
    file>>word;
    j= int(word[0]);
    n= j-48;

	while (file>>word)		 // reading from file
	{
	    b=strlen(word);
		for(i=0;i<b;i++)
		{
		    if(isdigit(word[i])) 
	            flag=1;
	        else
	        	{
	        		flag=0;  break;
				}
		}
		if(flag==1)
		{
			for (int i = 0; i < b; i++) 		//string to integer conversion
			{
				j=int(word[i]);
                z =((z*10) + (j - 48));
            }
			pr[l]=z; 
			l++;
			z=0;
		}
		else
		{
			for(i=0;word[i]!=':';i++)
			{
				g[k][i]=word[i];
			} 
			k++;	
		}      
    } 
    for(i=0;i<l;i++) 		//creating alternate array foe manipulation
		{	t[i]=pr[i];   }
	
	
	for(i=0; i<l;i++)		//sorting of the alternate array to determine minimal set
    {
        s=t[i];
        for(j=i+1;j<l;j++)
        {
            if(t[j]<s)
            { 
			    s=t[j];
				p=t[i];
                t[i] = t[j];
                t[j]=p;
            }
        }
    }
    

    
    p=0;  q=n-1;
    s=t[q]-t[p];
	for(i=1;i<l-(n-1);i++)		 //determining of  the minimal set
	{
		j=(t[i+(n-1)]-t[i]);
		if(j<s)
		{
			s=j;
			p=i;
			q=i+(n-1);
		}
	}
	
	fout.open("output.txt", ios::out | ios::trunc);		//writing to file
	fout<<"The goodies selected for distribution are: \n";	
   for(i=p;i<=q;i++)
   {
   		for(j=0;j<l;j++)
   		{
   			if(t[i]==pr[j])
   			{
				fout<<"\n"<<g[j]<<": "<<pr[j];
			}	
		}		
   }
   fout<<"\n \nAnd the difference between the chosen goodie with highest price and the lowest price is "<<s;
   fout.close(); 
   file.close();
   return 0; 
} 

