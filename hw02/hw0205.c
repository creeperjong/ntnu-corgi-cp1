#include <stdio.h>
#include <stdint.h>

int32_t a[5];
int32_t suit[5];
int32_t temp1 = 0;
void sort();
int32_t same();
void sort(){
		for(int32_t i=0;i<5;i++){
			for(int32_t j=i+1;j<5;j++){
				if(a[j]<a[i]){
					temp1 = a[i];
					a[i] = a[j];
					a[j] = temp1;
				}
			}
		}
	}
int32_t same(){
	int32_t countsame=0;
	for(int32_t I=0;I<5;I++){
		for(int32_t J=I+1;J<5;J++){
			if(a[I]==a[J]){
				countsame++;	
			}
		}
	}
	return countsame;
}
int main(){
	
	printf("Please enter 5 cards:");
	scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4]);
	for(int32_t check = 0;check<5;check++){
		if(a[check]<1 || a[check]>52){
			printf("Error\n");
			return 0;
		}else if(same()>0){
			printf("Error\n");
			return 0;
		}
	}
	for(int32_t analyze = 0;analyze<5;analyze++){
		suit[analyze] = (a[analyze]-1)/13;
		a[analyze] %= 13;
		if(a[analyze]==0){
			a[analyze] = 13;
		}
	}
	sort();
	if((a[0]+1==a[1] && a[1]+1==a[2] && a[2]+1==a[3] && a[3]+1==a[4])
	|| (a[1]==10 && a[2]==11 && a[3]==12 && a[4]==13 && a[0]==1)){
		if(suit[0]==suit[1] && suit[0]==suit[2] && suit[0]==suit[3] && suit[0]==suit[4]){
			printf("Straight flush\n");
		}else{
			printf("Striaght\n");
		}
	}else if(suit[0]==suit[1] && suit[0]==suit[2] && suit[0]==suit[3] && suit[0]==suit[4]){
		printf("Flush\n");
	}else if(same()==6){
		printf("Four of a kind\n");
	}else if(same()==4){
		printf("Full house\n");
	}else if(same()==3){
		printf("Three of a kind\n");
	}else if(same()==2){
		printf("Two pair\n");
	}else if(same()==1){
		printf("One pair\n");
	}else{
		printf("High card\n");
	}
	return 0;
}
