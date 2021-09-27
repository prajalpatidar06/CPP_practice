#include<stdio.h>

int main(){
    float unit;
    float bill = 0;
    int charges[] = {50,100,100,250};
    float factor[] = {0.50,0.75,1.20,1.50};
    scanf("%f", &unit);

    for(int i = 0 ; i < 4 ; i++){
        if(unit == 0) break;

        if(i == 3){
            bill += unit*factor[i];
            unit = 0;
            break;
        }

        if(unit > charges[i]){
            bill +=  charges[i]*factor[i];
            unit -= charges[i];
        }else{
            bill += unit*factor[i];
            unit = 0;
        }
    }
  
    printf("bill = %.4f \n",bill);
    return 0;
}