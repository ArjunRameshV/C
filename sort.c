#include<stdio.h>
#include<stdlib.h> 

int b=0 , ins=0 , sel=0 ;  
void bubble(int a[] , int n) ; 
void swap(int x , int y) ; 
void insert(int a[] , int n) ; 
void selection(int a[] , int n) ; 

void main() {
	int array_b[5] , array_s[5]  , array_i[5] ;  
	int n = 0 ; 
	srand(time(0)) ; 
	for(int i=10 ; i<=50 ; i=i+10){
		b = 0 ; 
		ins = 0 ; 
		sel = 0 ;
		 
		n = i ;      
		int a[n] ;                        
		for(int t=0 ; t<n ; t++){         //assigning the values to the arrays.
			a[t] = rand() % 300 ; 
		}
		if(i<21){	
			printf("Random values are generated for the array. The values for the array with %d elements are : \n",i) ; 
			for(int j=0 ; j<n ; j++ ){
				printf("%d ",a[j]) ; 
			}
			printf("\n \n") ; 
		} 
		
		//sorting using bubble sort 
		printf("Bubble sort : \n") ; 
		bubble(a,n) ; 
		for(int j=0 ; j<n ; j++){
			printf("%d ",a[j]) ; 
		}
		printf("\n \n") ; 
		
		//sorting using insertion sort 
		printf("Insertion sort: \n") ; 
		insert(a,n) ; 
		for(int j=0 ; j<n ; j++){
			printf("%d ",a[j]) ; 
		}
		printf("\n \n") ; 
		
		//sorting using selection sort 
		printf("Selection sort : \n") ; 
		selection(a,n) ; 
		for(int j=0 ; j<n ; j++){
			printf("%d ",a[j]) ; 
		}
		printf("\n \n") ; 
		
		//printf("%d %d %d \n" , b,ins,sel) ; 
		
		array_b[i/10] = b ; 
		array_i[i/10] = ins ; 
		array_s[i/10] = sel ; 
	}
	
	int sum=0 ;  
	float avg_b = 0 , avg_i = 0 , avg_s = 0 ; 
	
	for(int i=0 ; i<5 ; i++){
		sum = sum + 10*(i+1)*array_b[i] ; 
	}
	
	avg_b = sum / 150 ; 
	sum= 0 ;  
	
	for(int i=0 ; i<5 ; i++){
		sum = sum + 10*(i+1)*array_i[i] ; 
	}
	
	avg_i = sum / 150 ; 
	sum= 0 ;  
	
	for(int i=0 ; i<5 ; i++){
		sum = sum + 10*(i+1)*array_s[i] ; 
	}
	
	avg_s = sum / 150 ; 
	sum= 0 ;  
	
	printf("%f %f %f \n",avg_b, avg_i, avg_s) ; 
}

void swap(int x , int y){
	int z=x ; 
	x = y ; 
	y = z ; 
} 

int max (int a[] , int i) {
	int ans = 0 ; 
	for(int j=0 ; j<=i ; j++){
		sel++ ; 
		if(a[j] > ans){
			
			ans = j ; 
		}
	}
	return ans ; 
}

void bubble(int a[] , int n) {
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n-1 ; j++){
			b++ ; 
			if(a[j] > a[j+1]){
				
				//swap (a[j] , a[j+1]) ;
				int z=a[j] ; 
				a[j] = a[j+1] ; 
				a[j+1] = z ; 
			}
		}
	}
}

void insert(int a[] , int n){
	for(int i=1 ; i<n ; i++){
		for(int j=i ; j>0 ; j--){
			ins++ ; 
			if(a[j] < a[j-1]){
				
				//swap(a[j],a[j-1]) ;
				int z=a[j] ; 
				a[j] = a[j-1] ; 
				a[j-1] = z ; 
				   
			} else {
				break ; 
			}
		}
	}
}
 
void selection(int a[] , int n){
	for(int i=1 ; i<n ; i++){
		int m = max(a,n-i) ;
		swap(a[m],a[n-i]); 	 
		
	}
} 
