#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool check(void);
double value_calculate(int32_t,double,int32_t);

int main(){
	int32_t payment = 0;
	int32_t payment_sum = 0;
	int32_t processing = 0;
	int32_t age = 0;
	int32_t year = 0;
	int32_t time = 1;
	double return_rate = 0;
	double feeoff = 0.0;
	double value = 0.0;
	double fee[5];
	
	bool check(void){
		for(int i=0;i<5;i++){
			if(fee[i]<0 || fee[i]>100){
				return false;
			}
		}
		return true;
	}
	
	double value_calculate(int32_t payment_annual,double portion,int32_t insurance_costs){
		double value_annual = 0;
		value_annual = value + payment_annual * portion - insurance_costs;
		if(time == 1){
			for(int month = 0;month<11;month++){
				value_annual -= processing;
				value_annual *= (100+return_rate/12.0)/100.0;
			}
		}else{
			for(int month = 0;month<12;month++){
				value_annual -= processing;
				value_annual *= (100+return_rate/12.0)/100.0;
			}
		}
		return value_annual; 
	}
	
	printf("SIP Plan\n");
	printf("Annually payment:");
	scanf("%d",&payment);
	printf("Insurance fee in the first five years(0 is assumed afterwards):\n");
	scanf("%lf,%lf,%lf,%lf,%lf",&fee[0],&fee[1],&fee[2],&fee[3],&fee[4]);
	printf("Insurance fee off:");
	scanf("%lf",&feeoff);
	printf("Monthly insurance processing fee:");
	scanf("%d",&processing);
	printf("Age:");
	scanf("%d",&age);
	printf("How many years of payment:");
	scanf("%d",&year);
	printf("Expected annual return on investment rate:");
	scanf("%lf",&return_rate);
	
	if(payment<=0){
		printf("Error:Annually payment\n");
	}else if(!check()){
		printf("Error:Insurance fee\n");
	}else if(feeoff<0 || feeoff>100){
		printf("Error:Insurance fee off\n");
	}else if(processing<0){
		printf("Error:Monthly insurance processing fee\n");
	}else if(age<15 || age>85){
		printf("Error:Age\n");
	}else if(year<1){
		printf("Error:Years of payment\n");
	}else{
		printf("----------------------------------------\n");
		printf("Your Payment and Accound Value Table\n");
		for(time = 1;true;time++){
			if(age>100){
				break;
			}
			if(age<20){
				value = value_calculate(payment,(100-fee[time-1]+feeoff)/100.0,2000);
			}else{
				if(time<=5){
					value = value_calculate(payment,(100-fee[time-1]+feeoff)/100.0,100*(age-20)+2000);
				}else if(time<=year){
					value = value_calculate(payment,1,100*(age-20)+2000);
				}else{
					value = value_calculate(0,1,100*(age-20)+2000);
				}
			}
			if(time<=year){
				payment_sum = payment * time;
			}
			if(value<=0){
				printf("%d:%d,0\n",age,payment_sum);
				break;
			}else{
				printf("%d:%d,%.0lf\n",age,payment_sum,value);
			}
			age++;
		}
	}
	return 0;
}
