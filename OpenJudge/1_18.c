#include<stdio.h>

int main(){
    char event,school,gender;
    int point;
    int score[5][2] = {
        {0,0},
        {0,0},
        {0,0},
        {0,0},
        {0,0}
    };
    while(~scanf(" %c %c %c %d",&event,&gender,&school,&point)){
        int sel_school = school - 'A';
        int sel_gender = (gender == 'M') ? 0 : 1;
        score[sel_school][sel_gender] += point; 
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            if(score[i][j]){
                char print_gender = (j==0) ? 'M' : 'F';
                printf("%c %c %d\n",'A' + i, print_gender, score[i][j]);
            }
        }
        if((score[i][0]+score[i][1])!=0){
            printf("%c %d\n",'A' + i, score[i][0]+score[i][1]);
        }
    }
}