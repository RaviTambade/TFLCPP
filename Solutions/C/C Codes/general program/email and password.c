#include <stadio.h>

int login (string email,string passworld)
{
   int status=false; 

if( email=="sarthkadam@gmail.com" && passworld == "code"){
    status =true;
}else{
    status=false;
}
return status;
}
int main(){
string email = "0";
string password ="0";
printf(" welcome to transflower");
printf(" enter email");
scanf("%s",email);
printf("enter your passworld");
scanf("%s",passworld);
 int validuser=login(email,password);
if (validuser==true){
   printf("welcome to transflower");
}else{
    printf("invalid user");
}
return 0;
}