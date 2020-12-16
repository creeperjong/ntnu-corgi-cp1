#include <stdio.h>
#include <stdint.h>

int main(){
	int32_t salary=0;
	int32_t married=0;
	int32_t family=0;
	int32_t income=0;
	int32_t saving=0;
	int32_t tuition=0;
	int32_t children=0;
	int32_t disable=0;
	float tax=0;
	//文本
	printf("Gross salary:");
	scanf("%d",&salary);
	printf("Married(0/1):");
	scanf("%d",&married);
	printf("How many people are there in your family:");
	scanf("%d",&family);
	printf("How many people in your family have income:");
	scanf("%d",&income);
	printf("Special Deduction for Savings and Investment:");
	scanf("%d",&saving);
	printf("Special Deduction for Tuition:");
	scanf("%d",&tuition);
	printf("How many preschool children:");
	scanf("%d",&children);
	printf("How many disable people:");
	scanf("%d",&disable);
	//判斷是否合理
	if(salary<0){
		printf("Error:Gross salary\n");
	}else if(married != 0 && married !=1){
		printf("Error:Married\n");
	}else if((married == 0 && family<1)||(married == 1 && family <2)){
		printf("Error:people in you family\n");
	}else if(income<0 || income>family){
		printf("Error:Income\n");
	}else if(saving<0){
		printf("Error:Deduction for Savings and Investment\n");
	}else if(tuition<0){
		printf("Error:Deduction for Tuition\n");
	}else if(children<0 || children>family){
		printf("Error:Preschool children\n");
	}else if(disable<0 || disable>family){
		printf("Error:Disable\n");
	}else{
		tax = salary;
		//計算免稅額
		tax -= family * 88000;
		//計算標準扣除額
		if(married==0){
			tax -= income * 120000;
		}else{
			tax -= (income - 2)*120000 + 240000;
		}
		//計算特殊扣除額
		tax -= saving + tuition + income * 200000 +children * 120000 + disable * 200000;
		//計算稅率
		if(tax<=540000){
			tax *= 0.05;
		}else if(tax<=1210000){
			tax = tax * 0.12 - 37800;
		}else if(tax<=2420000){
			tax = tax * 0.2 - 134600;
		}else if(tax<=4530000){
			tax = tax * 0.3 - 376600;
		}else{
			tax = tax * 0.4 - 829600;
		}
		if(tax<0){
			printf("Total tax:0\n");
		}else{
			printf("Total tax:%.1f\n",tax);
		}
	}
	return 0;
}
