#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <pthread.h>
struct sched_param param1,param2,param3;
struct timespec sea1,sea2,sea3;
pthread_t thr1,thr2,thr3;
struct timespec ele1,ele2,ele3;
void* A(){
    
    param1.sched_priority = 0;
    int exp=32;
    double result = 1;
    while (exp != 0) {
        result *= 2;
        --exp;
    }
      int i=0;
    while(i<result){
        i++;
    }
    return NULL; 
}
void* B(){
    param2.sched_priority = 10;
    int exp=32;
    double result = 1;
    while (exp != 0) {
        result *= 2;
        --exp;
    }
      int i=0;
    while(i<result){
        i++;
    }
    return NULL;
}
void* C(){
    param3.sched_priority = 20;
    int exp=32;
    double result = 1;
    while (exp != 0) {
        result *= 2;
        --exp;
    }
      int i=0;
    while(i<result){
        i++;
    }
    return NULL; 
}
int main(void){
    int opa1=1;
    int opa2=2;
    int opa3=3;
    pthread_setschedparam(thr1,SCHED_OTHER,&param1);
    pthread_setschedparam(thr2,SCHED_RR,&param2); pthread_setschedparam(thr3,SCHED_FIFO,&param3); 
    clock_gettime(CLOCK_REALTIME,&sea1);pthread_create(&thr1,NULL,A,&opa1); clock_gettime(CLOCK_REALTIME,&sea2);pthread_create(&thr2,NULL,B,&opa2); clock_gettime(CLOCK_REALTIME,&sea3); pthread_create(&thr3,NULL,C,&opa3);
    pthread_join(thr1,NULL); clock_gettime(CLOCK_REALTIME,&ele1);
    pthread_join(thr2,NULL); clock_gettime(CLOCK_REALTIME,&ele2);
    pthread_join(thr3,NULL); clock_gettime(CLOCK_REALTIME,&ele3);
    double num= 1000000000.0;
    double time11=(ele1.tv_sec - sea1.tv_sec);
    double time12=(ele1.tv_nsec - sea1.tv_nsec);
    double thr1 = time11 + (time12/num);
    double time21=(ele2.tv_sec - sea2.tv_sec);
    double time22=(ele2.tv_nsec - sea2.tv_nsec);
    double thr2 = (time21) + (time22/num);
    double time31=(ele3.tv_sec - sea3.tv_sec);
    double time32=(ele3.tv_nsec - sea3.tv_nsec);
    double thr3 = (time31) + (time32/num);
    printf(" %lf \n",thr1);printf(" %lf \n",thr2);printf(" %lf \n",thr3);
}
