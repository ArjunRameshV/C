#include<iostream>
using namespace std ;

class c{
private:
	int n ; //the number of computers ;
	int d[10][10] ; //the distance array
	int check[10] ; // to check activity
	int dst[10] ; //to check current distance
	int ans[10][10] ; // the final answer
	int source ;
	int e ; //edge
public:
	void setter()  ;	//to take in the input 
	void mi() ; // the overall ittreation
	void reset() ; //resetting the check marker
	void dj() ; // the algorithm's magic
	int minimum() ; //finding the minimum unmarked node
	void display() ; // the view the final result
} ;

void c::setter(){
	cout<<"Enter the number of computers\n" ;
	cin>>n ;
	cout<<"Enter the distance between respective edges\n" ;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			if(i <j){
				cout<<"Distance between "<<i<<" and "<<j<<" : " ;
				cin>>d[i][j] ;
			} else if(i>j){
				d[i][j] = d[j][i] ;
			}
		}
	}
	e = (n*(n-1))/2 ;
}

void c::mi(){
	for(int i=0 ; i<n ; i++){
		source = i  ;
		reset() ;
		check[source] = 1 ;
		dst[i] = 0 ;
		dj() ;
		for(int i=0 ; i<n ; i++){
			if(i != source){
				ans[source][i] = dst[i] ;
			} else {
				ans[source][source] = 0 ;
			}
		}
	}

}

void c::reset(){
	for(int i=0 ; i<n ; i++){
		check[i] = 0 ;
		dst[i] = 999 ;
	}
}

void c::dj(){
	for(int j=0 ; j<n ; j++){
		int u = minimum() ;
		check[u] = 1 ;
		for(int i=0 ; i<n ; i++){
			if(check[i] == 0 && dst[i] > dst[u] + d[u][i]){
				dst[i] = dst[u] + d[u][i] ;
			}
		}
	}
}

int c::minimum(){
	int v = -1 ;
	int min = 999 ;
	for(int i=0 ; i<n ; i++){
		if(check[i] == 0 && dst[i] !=999 && dst[i]<=min){
			min = dst[i] ;
			v = i ;
		}
	}
	if(v == -1){
		v = source ;
	}

	return v ;
}

void c::display(){
 for(int i=0 ; i<n ; i++){
 	cout<<"Taking the source as "<<(i)<<" :\n" ;
 	for(int j=0 ; j<n ; j++){
 		if(i != j){
 			cout<<"\t The distance to "<<(j)<<" is "<<ans[i][j]<<"\n" ;
 		}
 	}
 }
}

int main(){
	c apple ;
	apple.setter() ;
	apple.mi();
	apple.display() ;
	return 0 ;
}
