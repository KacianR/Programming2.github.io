#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int x;
    for (int i = 0; i < 10; i++){
    	x = rand()% 8 * 4 + 1;
    	printf("%d, ", x); 
	}    
    
	return 0;        
}