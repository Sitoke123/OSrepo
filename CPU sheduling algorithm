a) FCFS with and without arrival time 
with arrival time:
#include <iostream>
using namespace std;
int booblesort(int pro[],int Bt[], int At[],int n)
{	int i,j,temp_pro,temp_Bt,temp_At;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(At[j]>At[j+1])
			{
				temp_At=At[j];
				At[j]=At[j+1];
				At[j+1]=temp_At;
				temp_pro=pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=temp_pro;
				temp_Bt=Bt[j];
				Bt[j]=Bt[j+1];
				Bt[j+1]=temp_Bt;
			}
		}
	}
}
int main()
{
int n,avg_tat=0,avg_wt=0,gt;
cout<<"This Program is made by Pranay Sitoke";
cout<<"enter no. of proccess: ";
cin>>n;
int pro[n],At[n],Bt[n],wt[n],Tat[n];
wt[0]=0;
for(int i =0;i<n;i++)
{
pro[i]=i;
cout<<"enter arival and brust time of process "<<i<<endl;
cin>>At[i]>>Bt[i];
}
booblesort(pro,Bt,At,n);
gt=At[0];
for(int i =1;i<n;i++)
{gt=gt+Bt[i-1];
	if (gt>At[i])
	{ 
	wt[i]=gt-At[i];
	}
	else{
	wt[i]=0;
	gt=At[i];
	}
}
cout<<endl<<"gt : "<<gt<<endl;
for(int i =0;i<n;i++)
{
Tat[i]=Bt[i]+wt[i];
}
cout<<"pro   ,Tat   , Wt :"<<endl;
for(int i =0;i<n;i++)
{cout<<pro[i]<<"    , "<<Tat[i]<<"    , "<<wt[i]<<endl;
avg_tat=Tat[i]+avg_tat;
avg_wt=wt[i]+avg_wt;
}
avg_tat=avg_tat/n;
avg_wt=avg_wt/n;
cout<<"avg_tat : "<<avg_tat<<endl;
cout<<"avg_wt : "<<avg_wt<<endl;
return 0;
}

Without arrival time:
#include <iostream>
using namespace std;
int main()
{
	int n,avg_tat=0,avg_wt=0;
	cout<<"This Program is made by pranay Sitoke";
	cout<<"enter no. of proccess: ";
	cin>>n;
	int pro[n],At[n],Bt[n],wt[n],Tat[n];
	wt[0]=0;
	for(int i =0;i<n;i++)
	{
		pro[i]=i;
		cout<<"enter arival and brust time of process "<<i<<endl;
		cin>>At[i]>>Bt[i];
	}
	for(int i =1;i<n;i++)
	{
	wt[i]=Bt[i-1]+wt[i-1];
	}
	for(int i =0;i<n;i++)
	{
	Tat[i]=Bt[i]+wt[i];
	}
	cout<<"Tat , Wt :"<<endl;
	for(int i =0;i<n;i++)
	{cout<<Tat[i]<<" , "<<wt[i]<<endl;
	avg_tat=Tat[i]+avg_tat;
	avg_wt=wt[i]+avg_wt;
	}
	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;
	cout<<"avg_tat : "<<avg_tat<<endl;
	cout<<"avg_wt : "<<avg_wt<<endl;
	return 0;
}

b) SJF with and without arrival time 
with arrival time:
def arrangeArrival(n, array):
    for i in range(0, n):
        for j in range(i, n-i-1):
            if array[1][j] > array[1][j+1]:
                for k in range(0, n):
                    array[k][j], array[k][j+1] = array[k][j+1], array[k][j]
def CompletionTime(n, array):
    value = 0
    array[3][0] = array[1][0] + array[2][0]
    array[5][0] = array[3][0] - array[1][0]
    array[4][0] = array[5][0] - array[2][0]
    for i in range(1, n):
        temp = array[3][i-1]
        mini = array[2][i]
        for j in range(i, n):
            if temp >= array[1][j] and mini >= array[2][j]:
                mini = array[2][j]
                value = j
        array[3][value] = temp + array[2][value]
        array[5][value] = array[3][value] - array[1][value]
        array[4][value] = array[5][value] - array[2][value]
        for k in range(0, 6):
            array[k][value], array[k][i] = array[k][i], array[k][value 
n = 4
arr = [[int(i) for i in range(1, n+1)], [2, 0, 4, 5],[3, 4, 2, 4], [0]*n, [0]*n, [0]*n]
arrangeArrival(n, arr)
CompletionTime(n, arr)
print("Process  Arrival  Burst  Completion  \tWaiting  \tTurnaround ")
waitingtime = 0
turaroundtime = 0
for i in range(0, n):
        print(arr[0][i], "\t\t", arr[1][i], "\t\t", arr[2][i],
              "\t\t", arr[3][i], "\t\t", arr[4][i], "\t\t\t", arr[5][i])
        waitingtime += arr[4][i]
        turaroundtime += arr[5][i]
print("Average waiting time is ", (waitingtime/n))
print("Average Turnaround Time is  ", (turaroundtime/n))

without arrival time:
def turnaround_time(p,n):
   ct=0
   tat=[0]
   for i in range(1,n+1):
       ct=ct+p[i][0] 
       tat.append(ct)
   return tat
def waiting_time(p,tat,n):
    wat=[0]
    for i in range(1,n+1):
        wt=tat[i]-p[i][0]
        wat.append(wt)
    return wat
def find_avg(p,n):
    tat=turnaround_time(p,n)
    print(tat)
    tat_average=sum(tat)/n
    wat=waiting_time(p,tat,n)
    print(wat)
    wat_average=sum(wat)/n
    print('AVERAGE TURN AROUND TIME IS GIVEN BY: {}'.format(tat_average))
    print('AVERAGE WAITING TIME IS GIVEN BY: {} '.format(wat_average))
n=int(input('ENTER THE NUMBER OF PROCESSES: '))
p=[[0,0]]
#[[burst time, processid]]
for i in range(1,n+1):
    b=int(input('ENTER THE BURST TIME OF : %d  '%i))
    p.append([b,i])
p.sort()
find_avg(p,n)
c) Round Robin with and without arrival time 
with arrival time:
#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <queue> 
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};
bool compare1(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
}
bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}
int main() {
    int n;
    int tq;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int burst_remaining[100];
    int idx;
    cout << setprecision(2) << fixed;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>tq;
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        burst_remaining[i] = p[i].burst_time;
        p[i].pid = i+1;
        cout<<endl;
    }
    sort(p,p+n,compare1);
    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark,0,sizeof(mark));
    mark[0] = 1;
    while(completed != n) {
        idx = q.front();
        q.pop();
        if(burst_remaining[idx] == p[idx].burst_time) {
            p[idx].start_time = max(current_time,p[idx].arrival_time);
            total_idle_time += p[idx].start_time - current_time;
            current_time = p[idx].start_time;
        }
        if(burst_remaining[idx]-tq > 0) {
            burst_remaining[idx] -= tq;
            current_time += tq;
        }
        else {
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;
            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
        }

        for(int i = 1; i < n; i++) {
            if(burst_remaining[i] > 0 && p[i].arrival_time <= current_time && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(burst_remaining[idx] > 0) {
            q.push(idx);
        }
        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(burst_remaining[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((p[n-1].completion_time - total_idle_time) / (float) p[n-1].completion_time)*100;
    throughput = float(n) / (p[n-1].completion_time - p[0].arrival_time);
    sort(p,p+n,compare2);
    cout<<endl;
    cout<<"#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
    for(int i = 0; i < n; i++) {  cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;
}
d) Priority with and without arrival time
#include <iostream>
#include <algorithm> 
#include <iomanip>
#include <string.h> 
using namespace std;
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};
int main() {
	cout<<"this program is made by Pranay Sitoke;
    int n;
    struct process p[100];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    float cpu_utilisation;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));
    cout << setprecision(2) << fixed;
    cout<<"Enter the number of processes: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        cout<<"Enter priority of the process "<<i+1<<": ";
        cin>>p[i].priority;
        p[i].pid = i+1;
        cout<<endl;
    }
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while(completed != n) {
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1) {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            p[idx].response_time = p[idx].start_time - p[idx].arrival_time;
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            total_response_time += p[idx].response_time;
            total_idle_time += p[idx].start_time - prev;
            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else {
            current_time++;
        }
    }
    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for(int i = 0; i < n; i++) {
        min_arrival_time = min(min_arrival_time,p[i].arrival_time);
        max_completion_time = max(max_completion_time,p[i].completion_time);
    }
    avg_turnaround_time = (float) total_turnaround_time / n;
    avg_waiting_time = (float) total_waiting_time / n;
    avg_response_time = (float) total_response_time / n;
    cpu_utilisation = ((max_completion_time - total_idle_time) / (float) max_completion_time )*100;
    throughput = float(n) / (max_completion_time - min_arrival_time);

    cout<<endl<<endl;
cout<<"#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
    for(int i = 0; i < n; i++) { cout<<p[i].pid<<"\t"<<p[i].arrival_time<<"\t"<<p[i].burst_time<<"\t"<<p[i].priority<<"\t"<<p[i].start_time<<"\t"<<p[i].completion_time<<"\t"<<p[i].turnaround_time<<"\t"<<p[i].waiting_time<<"\t"<<p[i].response_time<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_turnaround_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;
    cout<<"Average Response Time = "<<avg_response_time<<endl;
    cout<<"CPU Utilization = "<<cpu_utilisation<<"%"<<endl;
    cout<<"Throughput = "<<throughput<<" process/unit time"<<endl;
}
e) Designing your own Scheduling Algorithm and its implementation
ize = 8
disk_size = 200
def CLOOK(arr, head):
    seek_count = 0
    distance = 0
    cur_track = 0
    left = []
    right = []

    seek_sequence = []
    for i in range(size):
        if (arr[i] < head):
            left.append(arr[i])
        if (arr[i] > head):
            right.append(arr[i])
    left.sort()
    right.sort()
    for i in range(len(right)):
        cur_track = right[i]
        seek_sequence.append(cur_track)
        distance = abs(cur_track - head)
        seek_count += distance
        head = cur_track
    seek_count += abs(head - left[0])
    head = left[0]
    for i in range(len(left)):
        cur_track = left[i]

        seek_sequence.append(cur_track)
        distance = abs(cur_track - head)
        seek_count += distance
        head = cur_track
    print("Total number of seek operations =",
          seek_count)
    print("Seek Sequence is")
    for i in range(len(seek_sequence)):
        print(seek_sequence[i])
arr = [176, 79, 34, 60,
       92, 11, 41, 114]
head = 50
print("Initial position of head:", head)
CLOOK(arr, head)
