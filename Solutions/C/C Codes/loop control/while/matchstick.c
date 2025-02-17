#include<stdio.h>
int main(){
    int matchsticks=21, user, computer;
    while (matchsticks>1){
        printf("enter the number of matchstick you want to pick");
        scanf("%d",&user);
        if (user>4){
            printf("you can omly pick 1 to 4 matchsticks");
            continue ;
        }
        matchsticks=matchsticks-user;
        printf("matchsticks left=%d\n",matchsticks);
        computer=5-user;
        printf("computer picks=%d\n",computer);
        matchsticks=matchsticks-computer;
        printf("matchsticks left=%d\n",matchsticks); 
        if (matchsticks==1){
           printf("you lost the game ");
        break;
        }
    }

    
    
    return 0;
}