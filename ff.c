#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define col 128 
#define rows 100
/*NOTE : This code works perfectly if CFG dont have epsilon back tracking
it will give acurrate result of first and follows of given test runs in the files.
this code is completely  written by us no internet used so we can not see the other logics 
we have implemeted our own logic.Logic is explained in Project Report 

*/
void fill_array(char *c);//funtion to fill array with null character 
char temp[100];//temporrary array 
char * find_first(char,char,char const* );//function to find first of non terminal using recursion 
char * find_follow(FILE *fp);//function to find first of non terminal using recursion
void display_follow();//display follow 
void display_first();//display first
char first_arr2[rows][col];//2d array for storing list of first of non terminals 
char ch;//temporary character 
char first_arr[100];//store list of first of non terminal temporarly
char follow_arr[rows][col];//2d array for storing list of follow of non terminals 
int linecount=0;//total lines in file
char arr[50];//array of non terminals  

int main(int argc, char *argv[])
{
	
	char non_terminal;
	char first_non_terminal;
	char temp2[10];
	int i=0;
	//check for the input arguments
	if(argc != 2)
	{
	printf("Must have an input file name in the arguments\n");
	exit(0);
	}
	//read file
	FILE *fp=fopen(argv[1],"r");
	printf("Given grammer :\n\n");
	//printing lines on screen
	while(fgets(temp, 100, fp) != NULL) {
	printf("%s",temp);

	}
	fseek(fp, 0, SEEK_SET);
	printf("\n");
	//follow starting calls 
	while(fgets(temp, 100, fp) != NULL) {
	if (temp[0]>=65 && temp[0]<=90){
		
		non_terminal=temp[0];
	
		 while ((ch=temp[i]) != '\n')
        {	
			if(ch!='>'&&ch!='|'){i++;continue;}
			
            if(ch=='>' && temp[i+1]>=65 && temp[i+1]<=90){
				first_non_terminal=temp[i+1];
		
				find_first(non_terminal,first_non_terminal,argv[1]);
				
				}
			else if(ch=='>'&& temp[i+1]<65||temp[i+1]>90){
				temp2[0]=temp[i+1];
				strcat(first_arr,temp2);
				strcat(first_arr," ");
				}
			else {
				if(ch=='|' && temp[i+1]>=65 && temp[i+1]<=90){
			
				first_non_terminal=temp[i+1];
				find_first(non_terminal,first_non_terminal,argv[1]);
				
				}
				else if(ch=='|'&& temp[i+1]!='^'){
					
					if(temp[i+1]<65 || temp[i+1]>90)
				
					{temp2[0]=temp[i+1];
					strcat(first_arr,temp2);
					strcat(first_arr," ");
					}
					
			
					
				}
			}	
            i++;
            
        }
        
	
       i=0;
       strcat(first_arr2[non_terminal],first_arr);
	   arr[linecount]=non_terminal;
       linecount++;
       fill_array(first_arr);
		
		
}//first found and stored in array
 
	
}
	display_first();
	fseek(fp, 0, SEEK_SET);
	
	find_follow(fp);
	printf("\n");
	display_follow();
	
       
	return 0;
}

char *find_first(char non_terminal,char first_non_terminal,char const*filename ){
	
	char c1=non_terminal;
	char c2=first_non_terminal;
	char temp3[100];
	char temp4[10];
	char ch;
	int i=0;
	FILE *fp1=fopen(filename,"r");
	while(fgets(temp3, 100, fp1) != NULL){
		
		if(temp3[0]==c2){
			
			while ((ch=temp3[i]) != '\n')//'|'
        {	
			if(ch!='>'&&ch!='|'){i++;continue;}
			
            if(ch=='>' && temp3[i+1]>=65 && temp3[i+1]<=90){
				c2=temp3[i+1];//F
				//recursively call find_first to find funtion
				find_first(temp3[0],c2,filename); 
				}
				
			else if(ch=='>'&& temp3[i+1]<65||temp3[i+1]>90){
				temp4[0]=temp3[i+1];//t
				strcat(first_arr,temp4);//t
				strcat(first_arr," ");//t 
				}
				
			else {
				if(ch=='|' && temp3[i+1]>=65 && temp3[i+1]<=90){
			
				c2=temp3[i+1];
				find_first(temp3[0],c2,filename);
				
				}
			else if(ch=='|'&& temp3[i+1]<65 || temp3[i+1]>90){
				
				temp4[0]=temp3[i+1];
					strcat(first_arr,temp4);
					strcat(first_arr," ");			
			}
		}
		
		i++;
		
		
		
		}

	}

}
fclose(fp1);


}


char * find_follow(FILE *fp){
	char temp[100];
	int count = 1;
	char str[100];
	fill_array(str);
	int index=0;
	int epsilon=0;
	char ch_array[10];
	char cpy[100];
	char *p;
	for(int i=0;i<linecount;i++){
	if(i==0)strcat(follow_arr[arr[i]],"$ ");
	//~ printf("%c\n",arr[i]);	
	while(fgets(temp, 100, fp) != NULL) {
	
	
	while(temp[count]!= '\0'){

		if (arr[i]==temp[count]){

			if (temp[count+1]>=65 && temp[count+1]<=90){

				if((p=strstr(first_arr2[temp[count+1]],"^"))){
					strcpy(cpy,first_arr2[temp[count+1]]);
					index=p-first_arr2[temp[count+1]];
					cpy[index]='\0';
					if((strstr(str,cpy))){
						count++;
						continue;
						
						}	
					strcat(str,cpy);
					epsilon=1;
					
					}
					
				else{
					
					if(strstr(str,first_arr2[temp[count+1]])){
											
						count++;
						continue;
						
						}
					
										
					strcat(str,first_arr2[temp[count+1]]);}	
						
						
						}
							
				
				
				
			else if((temp[count+1]!='\n' && temp[count+1]!='|')&&(temp[count+1]<65||temp[count+1]>90)){
				
				ch_array[0]=temp[count+1];
				strcat(str,ch_array);
				strcat(str," ");
				
				
				}
				

			else if (temp[count+1]=='\n'||temp[count+1]=='|' ){
				
				if(i==0){
					
				if(strstr(follow_arr[temp[0]],"$")){
						
						count++;
						continue;
						
						}
				
					}
				else if(strstr(str,follow_arr[temp[0]])){
					
						count++;
						continue;
						
						}	
				
				else {
					
			
				strcat(str,follow_arr[temp[0]]);
			}
				
					}
				
			
			}
		else if (epsilon==1 && temp[count+1]>=65 && temp[count+1]<=90){
			
			if((p=strstr(first_arr2[temp[count+1]],"^"))){
					
					strcpy(cpy,first_arr2[temp[count+1]]);
					index=p-first_arr2[temp[count+1]];
					cpy[index]='\0';	
					
					strcat(str,cpy);
					
	
					}
			else{strcat(str,first_arr2[temp[count+1]]); }
		
		
		}
		else if (epsilon==1 && temp[count+1]=='\n'){
				epsilon=0;
				
				strcat(str,follow_arr[temp[0]]);
				
					}
					
					
		count++;
		
		}
		 
		count=1;
		
		
		
	}
	
	
	
	strcat(follow_arr[arr[i]],str);
	
	fill_array(str);
	
	fseek(fp, 0, SEEK_SET);

	
	
	
	
	
}
	

	
	}


void display_first(){
	printf("line number %d\n",linecount);
	
	for(int i=0;i<linecount;i++){
		
		printf("\nfirst of %c : %s\n",arr[i],first_arr2[arr[i]]);
       
		
		}
	
	
}
void display_follow(){
	
	
	for(int i=0;i<linecount;i++){
	
		printf("follow of %c : %s\n\n",arr[i],follow_arr[arr[i]]);

		}
	
	
}




void fill_array(char * c){
	for(int i=0;i<sizeof(c);i++)
	c[i]='\0';
	
	}
