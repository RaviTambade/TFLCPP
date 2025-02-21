#include <stdio.h>

// File I/O Operations using text files
//Steps to perform file I/O operations using text files:

//1.include header file
//2.Define file pointer
//3. Open a file
//4. define text data to write
//5. Write data to file 

int  writeFile(const char * fileName){
    FILE * pFile=NULL;
    pFile=fopen(fileName,"w"); //text mode
    if(pFile==NULL){
        printf("file not opened\n");
        return 1;
    }
    fprintf(pFile,"This is transflower learning Pvt Ltd\n");
    fclose(pFile);
}

void readFile(const char * fileName){
    FILE * pFile=NULL;
    pFile=fopen(fileName,"r"); //text mode
    if(pFile==NULL){
        printf("file not opened\n");
        return;
    }
    char buffer[100];
    while(fgets(buffer,100,pFile)!=NULL){
        printf("%s",buffer);
    }
    fclose(pFile);
}

int main(){
    //int result=writeFile();
    const char *fileName="../data/seed.txt";
    readFile(fileName);
    return 1;
}