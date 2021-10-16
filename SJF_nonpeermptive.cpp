#include<Stdio.h>
#include<stdbool.h>
#include<limits.h>

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct,wt,tat,rt,start_time;

}ps[100];


int findmax(int a,int b){
 return a>b ? a:b;
}
int findmin(int a, int b){
 return a<b ?a:b;
 }

int main(){
  int n;
  printf("Enter total number of process : ");
  scanf("%d",&n);
  bool is_completed[100]={false},is_first_process=true;
  int current_time=0;
  int completed=0;
  float sum_tat=0,sum_wt=0,sum_rt=0;
  int length_cycle,total_idle_time=0 ,prev=0;
  float cpu_utilization;
  int max_completion_time ,min_arrival_time;

  for(int i=0;i<n;i++){
    printf("\nEnter process %d Arrival time :",i);
    scanf("%d",&ps[i].at);
    ps[i].pid=i;
  }
 for(int i=0;i<n;i++){
    printf("\nEnter process %d Burst time :",i);
    scanf("%d",&ps[i].bt);
  }
//sort
                                           // qsort((void*)ps,n,sizeof(struct process_struct),comparatorAT);

 while(completed!=n){                     //find process with min burst time in ready queue
    int min_indx=-1;
    int minimum =INT_MAX;

    for(int i=0;i<n;i++){
        if(ps[i].at <= current_time && is_completed[i]==0){
            if(ps[i].bt <minimum){
                minimum = ps[i].bt;
                min_indx =i;
            }
            if(ps[i].bt == minimum){
                if(ps[i].at<ps[min_indx].at){
                    minimum =ps[i].bt;
                    min_indx=i;
                }
            }
        }
    }

     if(min_indx == -1){current_time++;}
     else{                                                        //calculation sum
        ps[min_indx].start_time =current_time;
        ps[min_indx].ct  = ps[min_indx].start_time + ps[min_indx].bt;
        ps[min_indx].tat =ps[min_indx].ct -ps[min_indx].at;
        ps[min_indx].wt= ps[min_indx].tat - ps[min_indx].bt;
        ps[min_indx].rt = ps[min_indx].wt;


       sum_tat+= ps[min_indx].tat;
       sum_wt+=ps[min_indx].wt;
       sum_rt+=ps[min_indx].rt;
       total_idle_time+=(is_first_process==true)? 0 :(ps[min_indx].start_time - prev);


       completed++;
       is_completed[min_indx]=true;
       current_time = ps[min_indx].ct;
       prev = current_time;
       is_first_process = false;
     }
 }
                                    //calculations length of process completion cycle
   max_completion_time =INT_MIN;
   min_arrival_time =INT_MAX;

   for(int i=0;i<n;i++){
    max_completion_time = findmax(max_completion_time ,ps[i].ct);
    min_arrival_time = findmin(min_arrival_time, ps[i].at);

   }
   length_cycle = max_completion_time - min_arrival_time;

  //OUTPUT

  printf("\processNo.\tAt\tBT \tCT\tTAT\tWT\t RT\n");

  for(int i=0;i<n;i++){
    printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
    printf("\n");
  }

cpu_utilization =(float )(length_cycle - total_idle_time)/length_cycle;
// Ouputs
printf("\n Average turn around time %.2f",(float)sum_tat/n);
printf("\n Average waiting time%.2f",(float)sum_wt/n);
printf("\n Average  response time%.2f",(float)sum_rt/n);

printf("\n Throughput %f",n/(float)length_cycle);
printf("\n Cpu utilization = %f %",cpu_utilization * 100);
printf("\n");

return 0;
}
