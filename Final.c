#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1
#define origin 10
#define destin 10
struct Train
{
    char Trainname[50];
    char train_no[50];
    char Time[50];
};

void findPath(int s, int v );
void Dijkstra(int s);
int min_temp( );
void create_graph();

int n=9;   
int adj[MAX][MAX];
int predecessor[MAX];   
int pathLength[MAX];
int status[MAX];

int main()
{
        int s,v;

        create_graph();

        printf("\nEnter the source: ");
        printf("\n0 Mumbai: ");
        printf("\n1 Delhi: ");
        printf("\n2 Kolkata: ");
        printf("\n3 Bhubneshvar: ");
        printf("\n4 Kerela:");
        printf("\n5 Bangalore:");
        printf("\n6 Hyderabad :");
        printf("\n7 Bhopal :");
        printf("\n8 Ranchi :\n");
        scanf("%d",&s);

        Dijkstra(s);

        while(1)
        {
                printf("\nEnter destination vertex(-1 to quit): ");
                scanf("%d",&v);
                if(v == -1)
                        break;
                if(v < 0 || v >= n )
                        printf("\nThis vertex does not exist\n");
                else if(v == s)
                        printf("\nSource and destination vertices are same\n");
                else if( pathLength[v] == infinity )
            printf("\nThere is no path from source to destination vertex\n");
                else
                        findPath(s,v);
        
        }
        return 0;
        exit(0);
        
}/*End of main()*/

void Dijkstra( int s)
{
        int i,current;
        for(i=0; i<n; i++)
        {
                predecessor[i] =  NIL;
                pathLength[i] = infinity;
                status[i] = TEMP;
        }
        
        pathLength[s] = 0;

        while(1)
        {
                
                current = min_temp( );

                if( current == NIL )
                        return;

                status[current] = PERM;

                for(i=0; i<n; i++)
                {
                        
                        if ( adj[current][i] !=0 && status[i] == TEMP )
                                if( pathLength[current] + adj[current][i] < pathLength[i] )
                                {
                                        predecessor[i] = current;  /*Relabel*/
                                        pathLength[i] = pathLength[current] + adj[current][i];
                                }
                }
        }
}


int min_temp( )
{
        int i;
        int min = infinity;
        int k = NIL;
        for(i=0;i<n;i++)
        {
                if(status[i] == TEMP && pathLength[i] < min)
                {
                        min = pathLength[i];
                        k = i;
                }
        }
        return k;
}

void findPath(int s, int v )
{
            struct Train T1;
        strcpy(T1.Trainname, "Paschim Express");
        strcpy(T1.train_no, "12137");
        strcpy(T1.Time,"31hr"); 
        struct Train T2;
        strcpy(T2.Trainname, "Sealdah Express");
        strcpy(T2.train_no, "12314");
        strcpy(T2.Time,"17hr");
        struct Train T3;
        strcpy(T3.Trainname, "ShatabdiExpress");
        strcpy(T3.train_no, "12277");
        strcpy(T3.Time,"7hr");
        struct Train T4;
        strcpy(T4.Trainname, "Prasanthi Express");
        strcpy(T4.train_no, "18463");
        strcpy(T4.Time,"30hr");
        struct Train T5;
        strcpy(T5.Trainname, "Mysuru Express");
        strcpy(T5.train_no, "16316");
        strcpy(T5.Time,"15hr");
        struct Train T6;
        strcpy(T6.Trainname, "Gareeb Rath");
        strcpy(T6.train_no, "02735");
        strcpy(T6.Time,"11hr");
        struct Train T7;
        strcpy(T7.Trainname, "Duronto Spl");
        strcpy(T7.train_no, "02285");
        strcpy(T7.Time,"13hr");
        struct Train T8;
        strcpy(T8.Trainname, "Rajdhani");
        strcpy(T8.train_no, "02285");
        strcpy(T8.Time,"13hr");
        struct Train T9;
        strcpy(T9.Trainname, "Gareeb Rath");
        strcpy(T9.train_no, "12832");
        strcpy(T9.Time,"23hr");
        struct Train T10;
        strcpy(T10.Trainname, "Puri HTE Spl");
        strcpy(T10.train_no, "=08452");
        strcpy(T10.Time,"13hr");
        struct Train T11;
        strcpy(T11.Trainname, "Howrah Ranchi Spl");
        strcpy(T11.train_no, "=02285");
        strcpy(T11.Time,"13hr");
        struct Train T12;
        strcpy(T12.Trainname, "Humsafar Spl");
        strcpy(T12.train_no, "=02497");
        strcpy(T12.Time,"23hr");
        int i,u,l,m;
        l=s;
        int path[MAX];          
        int shortdist = 0;      
        int count = 0;         
        char *buff[10] = {"Mumbai","Delhi","Kolkata","Bhubneshwar","Kerela","Bengaluru","Hyderabad","Bhopal","Ranchi"};
        
        while( v != s )
        {
                count++;
                path[count] = v;
                u = predecessor[v];
                shortdist += adj[u][v];
                v = u;
        }
        count++;
        path[count]=s;
        printf("Source is %s and destination is %s",buff[s],buff[v]);

        printf("\nShortest Path is : ");
        for(i=count; i>=1; i--)
        {
                printf("%s-->  ",buff[path[i]]); 
        }
        printf("\nShortest distance is: %dkm\n", shortdist);


        printf("\n********Train details*******\n");
        for(i=count; i>=1; i--)
        {

                m=path[i]; 
        if((l==0&&m==2) || (l==2&&m==0))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T1.Trainname,T1.train_no,T1.Time);
        else if((l==1&&m==2) || (l==2&&m==1))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T2.Trainname,T2.train_no,T2.Time);
        else if((l==2&&m==3) || (l==3&&m==2))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T3.Trainname,T3.train_no,T3.Time);
        else if((l==3&&m==5) || (l==5&&m==3))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T4.Trainname,T4.train_no,T4.Time);
        else if((l==4&&m==5) || (l==5&&m==4))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T5.Trainname,T5.train_no,T5.Time);
        else if((l==6&&m==5) || (l==5&&m==6))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T6.Trainname,T6.train_no,T6.Time);
        else if((l==6&&m==7) || (l==7&&m==6))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\\n",T7.Trainname,T7.train_no,T7.Time);
        else if((l==1&&m==7) || (l==7&&m==1))
        printf("Train Name:%s\nTrain no.:%s\nTTraveling Time:%s\n\n",T8.Trainname,T8.train_no,T8.Time);
        else if((l==7&&m==8) || (l==8&&m==7))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T9.Trainname,T9.train_no,T9.Time);
        else if((l==3&&m==8) || (l==8&&m==3))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T10.Trainname,T10.train_no,T10.Time);
        else if((l==8&&m==2) || (l==2&&m==8))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T11.Trainname,T11.train_no,T11.Time);
        else if((l==0&&m==5) || (l==5&&m==0))
        printf("Train Name:%s\nTrain no.:%s\nTraveling Time:%s\n\n",T12.Trainname,T12.train_no,T12.Time);
        l=m;
        }
        
        
          
}


void create_graph()
{
        {
        adj[0][1]=1414;
        adj[0][5]=981;
        adj[1][0]=1414;
        adj[1][7]=788;
        adj[1][5]=980;
        adj[1][2]=1534;
        adj[5][0]=981;
        adj[2][1]=1534;
        adj[2][3]=440;
        adj[2][8]=401;
        adj[3][2]=440;
        adj[3][5]=1433;
        adj[3][8]=477;
        adj[4][5]=462;
        adj[5][1]=980;
        adj[5][3]=1433;
        adj[5][4]=462;
        adj[5][6]=569;
        adj[6][5]=569;
        adj[6][7]=850;
        adj[7][1]=788;
        adj[7][6]=850;
        adj[7][8]=1016;
        adj[8][2]=401;
        adj[8][3]=477;
        adj[8][7]=1016;


        
        };
}