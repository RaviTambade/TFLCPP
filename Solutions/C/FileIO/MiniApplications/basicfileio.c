#include <stdio.h>
 
int main(int argc, char** argv) {
    FILE * pFile=NULL;

	//Write content to File
	pFile=fopen("transflower.txt","w");
	if(pFile !=NULL){
		fprintf(pFile, "Welcome to Transflower Learning Pvt. Ltd \n");
		fclose(pFile);
	}
	
	//Read content from File
	char buffer[150];
	pFile=fopen("transflower.txt","r");
	if(pFile !=NULL){
		fgets(buffer, sizeof(buffer),pFile);
 		printf("%s", buffer);
		fclose(pFile);
	}
	return 0;
}
