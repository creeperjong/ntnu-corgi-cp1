#include <stdio.h>
#include <stdint.h>

int main(){
	char garbage;
	float x11 = 0;
	float y11 = 0;
	float x12 = 0;
	float y12 = 0;
	float x21 = 0;
	float y21 = 0;
	float x22 = 0;
	float y22 = 0;
	float a1 = 0;
	float b1 = 0;
	float a2 = 0;
	float b2 = 0;
	float xans = 0;
	float yans = 0;
	printf("Please enter the first line:");
	scanf("(%f,%f),(%f,%f)",&x11,&y11,&x12,&y12);
	scanf("%c",&garbage);
	printf("Please enter the second line:");
	scanf("(%f,%f),(%f,%f)",&x21,&y21,&x22,&y22);
	if((x11-x12)==0 && (x21-x22)!=0){
		xans = x11;
		a2 = (y21-y22)/(x21-x22);
		b2 = y21-a2*x21;
		yans = a2*xans + b2;
		printf("Intersection:(%.2f,%.2f)\n",xans,yans);
	}else if((x11-x12)!=0 && (x21-x22)==0){	
		xans = x21;
		a1 = (y11-y12)/(x11-x12);
		b1 = y11-a1*x11;
		yans = a1*xans + b1;
		printf("Intersection:(%.2f,%.2f)\n",xans,yans);
	}else{
		a1 = (y11-y12)/(x11-x12);
		b1 = y11-a1*x11;
		a2 = (y21-y22)/(x21-x22);
		b2 = y21-a2*x21;
		if(a1==a2){
			if(b1==b2){
				printf("The number of the intersections is infinity\n");
			}else{
				printf("The intersection doesn't exist\n");
			}
		}else{
			xans = (b1-b2)/(a2-a1);
			yans = a1*xans+b1;
			printf("Intersection:(%.2f,%.2f)\n",xans,yans);
		}
	}
	return 0;
}
