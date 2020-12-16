#include <stdio.h>
#include <stdint.h>

int32_t P(int32_t);
int32_t last(int32_t,int32_t);
int main(){
	int32_t sy = 0;
	int32_t sm = 0;
	int32_t sd = 0;
	int32_t ey = 0;
	int32_t em = 0;
	int32_t ed = 0;
	int32_t d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int32_t ssum = 0;
	int32_t esum = 0;
	//閏年判斷函數
	int32_t P(int32_t n){
		int32_t p=0;
		if((n%400==0) || (n%4==0 && n%100!=0)){
			p = 1;
		}else{
			p = 0;
		}
		return p;
	}
	//每月天數判斷函數
	int32_t last(int32_t year,int32_t month){
		int32_t day;
		if(P(year)==1 && month==2){
			day = 29;
		}else{
			day = d[month-1];
		}
		return day;
	}
	printf("Date Format:YYYY/MM/DD\n");
	printf("Start Date:");
	scanf("%d/%d/%d",&sy,&sm,&sd);
	printf("End Date:");
	scanf("%d/%d/%d",&ey,&em,&ed);
	if(sy>0 && sm>0 && sm<13 && sd>0 && ey>0 && em>0 && em<13 && ed>0){ //過濾無效數據（年月）
		if(last(sy,sm)>=sd && last(ey,em)>=ed){ //過濾無效數據(日)
			ssum = (sy-1)*365 + (sy-1)/4 - (sy-1)/100 + (sy-1)/400; //以年為單位累加天數
			for(int32_t i1 = 0;i1<sm-1;i1++){
				ssum += d[i1]; 
			}  //以月為單位累加天數
			ssum += sd; //以日為單位累加天數
			if(P(sy)==1 && sm>2){
				ssum++;
			} //若為閏年且有數到二月，則多加一天
			esum = (ey-1)*365 + (ey-1)/4 - (ey-1)/100 + (ey-1)/400;
			for(int32_t i2 = 0;i2<em-1;i2++){
				esum += d[i2];
			}
			esum += ed;
			if(P(ey)==1 && em>2){
				esum++;
			}
			if(esum-ssum>=0){ //過濾無效數據（開始日期晚於結束日期）
				printf("Duration:%d Day(s)\n",esum - ssum);  //總天數相減得間隔天數
			}else{
				printf("Error\n");
			}
		}else{
			printf("Error\n");
		}
	}else{
		printf("Error\n");
	}
	return 0;
}
