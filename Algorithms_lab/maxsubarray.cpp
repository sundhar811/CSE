#include <iostream.h>
#include <limits.h>
#include <conio.h>
#include <stdlib.h>

int maxsub(int a[], int size, int *start, int *end){
	int curr_max=0, prev_max=INT_MIN, startp=0;
	*start=0, *end=0;

	for(int i=0; i<size; i++){
		curr_max+=a[i];

		if(prev_max<curr_max){
			prev_max=curr_max;
			*start=startp;
			*end=i;
		}

		else if(curr_max < 0){
			startp=i+1;
			curr_max=0;
		}
	}

	return prev_max;
}

int main(){
	int *a, n, max, start=0, end=0;
	clrscr();
	cout<<"Enter the number of elements: ";
	cin>>n;
	a=(int *)calloc(n, sizeof(int));
	cout<<"Enter the elements: \n";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	max=maxsub(a, n, &start, &end);
	cout<<"Maximum  contiguous sum is "<<max<<endl;
	cout<<"Index from: "<<start<<"to: "<<end<<endl;
	free(a);
	getch();
	return 0;
}