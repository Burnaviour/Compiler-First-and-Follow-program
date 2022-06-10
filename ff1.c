#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LSIZ 128 
#define RSIZ 10 
#define col 128 
#define rows 100 

void fill_array(char *c);
char ch;
void get_non_terminal(FILE *);
void update_first();
char line[RSIZ][LSIZ];
char first_arr[rows][col];
char arr_index[20];//index of T
void display_first();
char arr[256];
void get_lines(FILE *);
int total;
int main(int argc, char *argv[])
{
	int i=0;
	char non_terminal;
	char temp[100];
	char first_non_terminal;

	FILE *fp=fopen(argv[1],"r");
	//~ get_non_terminal(fp);
	get_lines(fp);
	//~ while (arr[i]!='\0'){
		//~ printf("%c\n", arr[i]);
		//~ i++;
	//~ }
	display_first();
	update_first();
	display_first();
	return 0;
}

void get_non_terminal(FILE *fp){
	int i=0;
	char temp1[100];
	
	while(fgets(temp1, 100,fp) != NULL) {
		
		arr[i]=*(temp1);
		
		i++;
		
	}
	arr[i]='\0';
	fseek(fp, 0, SEEK_SET);
	
	}
	
void get_lines(FILE *fp){
	
	int i=0;
	int j=0;
	
	int k=0;
	char ch;
	int m=0;
	
	
	while(fgets(line[j], LSIZ, fp)) 
	{	
		
        line[j][strlen(line[j]) - 1] = '\0';
      
        
        j++;
    }
	total = j;
	printf("%d\n",total);
	
	//~ printf("\n The content of the file are: \n");    
    for(i = 0; i < total; i++)
    {
		
		while((ch=line[i][k])!='\0'){
			//~ printf("%d %d\n",i,k);
			printf("%c\n",ch);
			
			if(ch!='>'&&ch!='|'){k++;continue;}
			
            if(ch=='>' && line[i][k+1]>=65 && line[i][k+1]<=90){
				first_arr[line[i][0]][m]=line[i][k+1];
				//arr['E'][1]
				printf("1array %c\n",line[i][0]);
				printf("added %c\n",first_arr[line[i][0]][m]);
				m++;//T
				first_arr[line[i][0]][m]=' ';
				m++;
				
				
				}
			else if(ch=='>'&& (line[i][k+1]<65||line[i][k+1]>90)){
				
				
				first_arr[line[i][0]][m]=line[i][k+1];
				printf("2array %c\n",line[i][0]);
				printf("added %c\n",first_arr[line[i][0]][m]);
				m++; 
				first_arr[line[i][0]][m]=' ';
				m++;
				}
			else {
				if(ch=='|' && line[i][k+1]>=65 && line[i][k+1]<=90){
			
				first_arr[line[i][0]][m]=line[i][k+1];
				printf("3array %c\n",line[i][0]);
				printf("added %c\n",first_arr[line[i][0]][m]);
				m++;
				first_arr[line[i][0]][m]=' ';
				m++;
				}
				else if(ch=='|' &&(line[i][k+1]<65||line[i][k+1]>90)){
				
				first_arr[line[i][0]][m]=line[i][k+1];
				printf("4array %c\n",line[i][0]);
				printf("added %c\n",first_arr[line[i][0]][m]);
				m++;
				first_arr[line[i][0]][m]=' ';
				m++;			
			}
				
			}
				
			k++;
			
			
			}
			m=0;
			k=0;
			printf("------------------\n");
        
    }
    printf("\n");
	
	
	
	}


void update_first(){
	int i=0;
	char temp[100];
	int lineNo = 0;
	char temp2[10];
	
	
	
	for(int j = 0; j < total; j++)
   {
		char *p;
	   fill_array(temp);
	   char c =line[j][0];//E  T  F
	   	while((isupper(first_arr[c][i])))//t
	{		
			 
			c = first_arr[c][i];//F
			int l=1;
			while(first_arr[c][l]!='\0'){
				if( first_arr[c][l]<65||first_arr[c][l]>90){
					temp2[0]=first_arr[c][l];
				strcat(temp,temp2);
				l++;
				}
				
				}
			

	}
	int x=line[j][0];
	
	
	//~ index2=strlen(first_arr[x]);
	
	if(first_arr[x][i]>=65 && first_arr[x][i]<=90){
	p=first_arr[x]+1;
	
	strcat(temp,p);
	strcat(temp,first_arr[c]);
	fill_array(first_arr[x]);
	strcat(first_arr[x],temp);
	
	
	}
	
	

	   
	
	}
	
	
	
	
	
	}





void display_first(){
	
	
	 
	for(int i = 0; i < total; i++)
   {
	   
	   printf("\nFirst of %c are : %s\n",line[i][0],first_arr[line[i][0]]);
	
	}
	
	
	
	}
void fill_array(char * c){
	for(int i=0;i<sizeof(c);i++)
	c[i]='\0';
	
	}
