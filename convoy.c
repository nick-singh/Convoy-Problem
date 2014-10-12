/*
	
	Problem:	Convoy
	Description: Given lorries, all of equal capacity, to be filled with items of various weight
				 which come off a conveyor belt. Each item must be loaded onto the lorries sequentially 
				 i.e items 1 to N (for some N) go on the first lorry, items N+1, …, M (for some M) go on 
				 the second lorry, and so on. Not all lorries will be loaded to their full capacity, 
				 of course, but it is guaranteed that no single item is too heavy for a lorry. 
	
	Required:	 Find the spare capacity of the convoy as the sum of squares of the unused capacity of each 
				 lorry in the convoy. We want to load the lorries in such a way to minimize the spare capacity 
				 of the convoy.

	Solution:	FT(i) the best way to fill lorry from items i to n, where i starts a new lorry
				Wi = weight of item, c = capacity of lorry, if FT(k) > n, FT(k) = 0
				FT(i) = min [(c - [Wi+...+Wk])^2 + FT(k+1)] for k = 1 to n, where (Wi +... Wk) < c	

				e.g. capacity = 6, no of items 5 {1, 2, 3, 1, 1}

				FT(3) = min{ 
						(c - W3)^2 + FT(4)
						(c - W3 + W4)^2 + FT(5)
						(c - W3 + W4 + W5)^2 + FT(6)
					}
*/


#include <stdio.h>
#include <stdlib.h>

FILE *in;
FILE *out;

int fillLorry(int*, int*, int*, int, int);
int countLorries(int*, int, int);
void printLorries(int*, int, int);

int main()
{
	in = fopen("input.txt","r");
	out = fopen("output.txt","w");

	if(in == NULL || out == NULL){
		printf("error reading files\n");
	}
	int n, c, i;	

	fscanf(in,"%d %d",&c, &n);
	int maxSq = c*c;	

	int *items = (int*) malloc((n+1)*sizeof(int));
	int *sqCap = (int*) malloc((n+1)*sizeof(int));
	int *pos = (int*) malloc((n+1)*sizeof(int));

	
	for(i = 1; i <= n; i++){		
		fscanf(in,"%d",&items[i]);						
	}
	
	fillLorry(items, sqCap, pos, c,n);
	fprintf(out,"%d\n",countLorries(pos,n,1));
	printLorries(pos,n,1);
	fprintf(out, "\n");
	fprintf(out, "%d\n", sqCap[1]);
	
	fclose(in);
	fclose(out);
	return 0;
}


int countLorries(int *pos, int n, int i){
	if(pos[i] != n){
		return 1 + countLorries(pos,n,pos[i]+1);
	}
	return 1;
}

void printLorries(int *pos, int n, int i){
	fprintf(out, "%d ", pos[i] - i + 1);
	if(pos[i] != n){
		printLorries(pos,n,pos[i]+1);
	}	
}

int fillLorry(int *items, int *sqCap, int *pos, int capacity, int n){
	
	int i, j, k, sqcap, min, position, sum;

	for(i = n; i >= 1; i--){ // Wi
		
		min = 999;

		for(k=i; k<=n; k++){ // for k = i to n

			sum = 0;

			for(j = i; j<=k; j++){ // sum of Wk to Wn
				sum += items[j];
			}// end for j	

			sqcap = capacity - sum;
			if(sqcap<0) break;
			
			sqcap = sqcap * sqcap;
			if(k+1 <= n){
				sqcap = sqcap + sqCap[k+1]; // c - Wi...Wk + FT(k+1)
			}// end if
			if(sqcap <= min){ // min c - Wi...Wk + FT(k+1)
				min = sqcap;
				position = k;
			}// end if					

		}// end for k
		sqCap[i] = min;
		pos[i] = position;				
	}// end for n to 1		
}
