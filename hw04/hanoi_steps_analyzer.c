#include "hanoi_steps_analyzer.h"

void hanoi_steps_recrusive(int32_t spare_disk_num,int32_t source,int32_t target,int32_t spare){
    if(spare_disk_num == 1){
        printf("move disk 1 to rod %d\n",target);
    }else{
        hanoi_steps_recrusive(spare_disk_num-1,source,spare,target);
        printf("move disk %d to rod %d\n",spare_disk_num,target);
        hanoi_steps_recrusive(spare_disk_num-1,spare,target,source);
    }
}

void hanoi_steps_iterative(int32_t spare_disk_num){
    int32_t A[21] = {21,0}; //3 arrays as 3 rods
    int32_t B[21] = {21,0}; //{21,3,2,1}
    int32_t C[21] = {21,0}; //{0,1,2,3}
    int32_t A_top = spare_disk_num;
    int32_t B_top = 0;
    int32_t C_top = 0;
    for(int32_t load = 1;load<=spare_disk_num;load++){
        A[load] = spare_disk_num - load + 1 ;
    }
    if(spare_disk_num % 2 == 0){    //even number
        while(1){

            //A<=>C

            if(A[A_top]<C[C_top]){  //A=>C
                C[C_top+1] = A[A_top];
                printf("move disk %d to rod 3\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                C_top++;
            }else{  //C=>A
                A[A_top+1] = C[C_top];
                printf("move disk %d to rod 1\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                A_top++;
            }

            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }

            //A<=>B

            if(A[A_top]<B[B_top]){  //A=>B
                B[B_top+1] = A[A_top];
                printf("move disk %d to rod 2\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                B_top++;
            }else{  //B=>A
                A[A_top+1] = B[B_top];
                printf("move disk %d to rod 1\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                A_top++;
            }

            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }

            //C<=>B

            if(C[C_top]<B[B_top]){  //C=>B
                B[B_top+1] = C[C_top];
                printf("move disk %d to rod 2\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                B_top++;
            }else{  //B=>C
                C[C_top+1] = B[B_top];
                printf("move disk %d to rod 3\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                C_top++;
            }

            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }

        }
    }else{
        while(1){

            //A<=>B

            if(A[A_top]<B[B_top]){  //A=>B
                B[B_top+1] = A[A_top];
                printf("move disk %d to rod 2\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                B_top++;
            }else{  //B=>A
                A[A_top+1] = B[B_top];
                printf("move disk %d to rod 1\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                A_top++;
            }

            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }

            //A<=>C

            if(A[A_top]<C[C_top]){  //A=>C
                C[C_top+1] = A[A_top];
                printf("move disk %d to rod 3\n",A[A_top]);
                A[A_top] = 0;
                A_top--;
                C_top++;
            }else{  //C=>A
                A[A_top+1] = C[C_top];
                printf("move disk %d to rod 1\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                A_top++;
            }

            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }

            //B<=>C

            if(C[C_top]<B[B_top]){  //C=>B
                B[B_top+1] = C[C_top];
                printf("move disk %d to rod 2\n",C[C_top]);
                C[C_top] = 0;
                C_top--;
                B_top++;
            }else{  //B=>C
                C[C_top+1] = B[B_top];
                printf("move disk %d to rod 3\n",B[B_top]);
                B[B_top] = 0;
                B_top--;
                C_top++;
            }
            
            //break condition

            if(B[spare_disk_num] == 1){
                break;
            }
        }
    }
}