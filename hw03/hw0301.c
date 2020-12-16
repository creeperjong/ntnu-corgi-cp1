#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(){
	int32_t width = 0;
	int32_t heigh = 0;
	int32_t nowx = 0;
	int32_t nowy = 0;
	int32_t judgex = 0;
	int32_t judgey = 0;
	int32_t index = 0;
	int32_t dirx[4]={0,1,0,-1};
	int32_t diry[4]={1,0,-1,0};
	printf("Pleae enter the width:");
	scanf("%d",&width);
	printf("Please enter the heigh:");
	scanf("%d",&heigh);
	//偵錯
	if(width<1 || heigh<1){
		printf("Error");
	}else{
		int32_t map[heigh][width];
	//	map[heigh][width] = {0};
	//初始化記憶體
		memset(map, 0, sizeof(map));
	//第一格算不到，直接assign
		map[0][0] = 1;
	//用迴圈printf和判斷方向
		for(int32_t i = 1;i<width*heigh;i++){	//???
			judgex = nowx + dirx[index];	//照上次紀錄的方向前進
			judgey = nowy + diry[index];
			if(judgex<0 || judgex>heigh-1 || judgey<0 || judgey>width-1 || map[judgex][judgey]!=0){
				index = index + 1;	//如果碰壁or遇到有走過的格子則轉向
			}
			if(index == 4){
				index = 0;	//蛤
			}
			nowx += dirx[index];	//確認方向正確後，設立下一格的索引值
			nowy += diry[index];
			map[nowx][nowy] = i+1;	//啥鬼
		}
		for(int32_t j = 0;j<heigh;j++){	//printf好貴
			for(int32_t k = 0;k<width;k++){
				printf("%4d",map[j][k]);
			}
			printf("\n");
		}
	}
	return 0;
}
