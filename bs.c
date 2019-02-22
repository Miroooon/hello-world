#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define N2 100
#define MAX_SORT 100


void countingSort(int n, int Ar[]){
    int SortedAr[MAX_SORT] = { 0 };
    int c = 0;
    int i;
    int j;
    
    for(int i = 0;  i < n-1; i++){
        SortedAr[Ar[i]] += 1;
	//printf("%d ", SortedAr[Ar[i]]);
    }

    
    for(i = 0; i < MAX_SORT-1; i++){
	for(j = 0; j < SortedAr[i]; j++){
	    if(SortedAr[i] != 0){
		Ar[c] = i;
	        c++;
	    }    
	}
    }
}

void binSearch(int Ar[]){
    int k;
    printf("Search : "); 
    scanf("%d", &k);
    int i = 0; 
    int r = 19;
    int search = -1; 
    while (i <= r) 
    {
        int mid = (i + r) / 2; 
        if (k == Ar[mid]) {  
            search = mid;     
            break;            
        }
        if (k < Ar[mid])     
            r = mid - 1;  
        else               
          i = mid + 1;   
    }
    if (search == -1)     
        printf("not found\n");
    else          
        printf("%d. k= %d. ", Ar[search], search);
    
    
}

int main(){
    

    int Ar[N];
    for (int i = 0; i < N-1; i++) {
	Ar[i] = 0 + rand() % N2-1;
        //Ar[i] = i;
        //printf("%d\n", Ar[i]);    
    }

    countingSort(N, Ar);

    for (int i = 0; i < N-1; i++) {
	printf("%d\n", Ar[i]);    
    }

    binSearch(Ar);

    //srand();
    return 0;
}




