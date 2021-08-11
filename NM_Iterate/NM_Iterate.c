#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 2

int arr[N] = {0};

void printArray(int k);

void iterate(int count[]){
	for(int a = 0; a < N; a++){
		arr[a] = count[a]+1;
	}
	printArray(0);
	count[N-1]++;
	for(int a = N-1; a >= 0; a--){
		if(count[a] == M){
			if(a > 0){
				count[a] = 0;
				count[a-1]++;
			}else{
				return;
			}
		}
	}
	iterate(count);
}

int main(){
	int count[N] = {0};
	iterate(count);
	return 0;
}

void printArray(int k){
	if(k >= N){
		printf("\n");
		return;
	}
	printf("%d ", arr[k]);
	printArray(k+1);
}