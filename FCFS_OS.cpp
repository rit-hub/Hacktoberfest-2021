#include<Stdio.h>
#include<stdlib.h>

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
int comparatorAT(const void *a ,const void * b)
{
    int x=((struct process_struct *)a)->at;
    int y=((struct process_struct *)b)->at;
    if(x<y)
         return -1; //no sorting
    else if(x>=y)
         return 1; //sort = is for stable sort
}

int comparatorPID(const void * a,const void * b){
  int x=((struct process_struct *)a)->pid;
  int y=((struct process_struct *)b)->pid;
  if(x<y)
    return -1; //no sort
  else if(x>=y)
       return 1;//sort

}

int main(){
  int n;
  printf("Enter total number of process");
  scanf("%d",&n);
  float sum_tat=0,sum_wt=0,sum_rt=0;
  int length_cycle,total_idle_time=0;
  float cpu_utilization;

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
  qsort((void*)ps,n,sizeof(struct process_struct),comparatorAT);

  //calculations

  for(int i=0;i<n;i++){
    ps[i].start_time=(i==0)? ps[i].at : findmax(ps[i].at,ps[i-1].ct);

   ps[i].ct=ps[i].start_time + ps[i].bt;
   ps[i].tat =ps[i].ct -ps[i].at;
   ps[i].wt=ps[i].tat -ps[i].bt;
   ps[i].rt =ps[i].wt;

   sum_tat +=ps[i].tat;
   sum_wt+=ps[i].wt;
   sum_rt+=ps[i].rt;

   total_idle_time +=(i==0)? 0:(ps[i].start_time - ps[i-1].ct);
  }
  length_cycle = ps[n-1].ct - ps[0].start_time;
  //sort so that process ID in output comes in original order
   qsort((void*)ps,n,sizeof(struct process_struct), comparatorPID);

  //OUTPUT

  printf("\processNo.\tAt\tCPU BT \tCT\tTAT\tWT\t RT\n");

  for(int i=0;i<n;i++){
    printf("%d\t\t%d\t%d\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
    printf("\n");
  }

cpu_utilization =(float )(length_cycle - total_idle_time)/length_cycle;

printf("\n Average turn around time %.2f",(float)sum_tat/n);
printf("\n Average waiting time%.2f",(float)sum_wt/n);
printf("\n Average  response time%.2f",(float)sum_rt/n);

printf("\n Throughput %f",n/(float)length_cycle);
printf("\n Cpu utilization = %f %",cpu_utilization * 100);
printf("\n");

return 0;
}
