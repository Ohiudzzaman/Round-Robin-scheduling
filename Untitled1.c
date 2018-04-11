#include<stdio.h>
#include<conio.h>

int main()
{
    int n,Extime[50],BT[50],PO[50],TT[50],WT[50],W1=0,_TAT=0;
    int i,j,s;
    float AWT,ATAT;
    printf("Enter Number of processes= ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("The process %d :\n",i+1);
        printf("Enter The Burst Time of Process= ");
        scanf("%d",&BT[i]);
        printf("Enter the priority of process%d= ",i+1);
        scanf("%d",&PO[i]);
        Extime[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(PO[i]<PO[j])
            {
                s=PO[i];
                PO[i]=PO[j];
                PO[j]=s;
                s=BT[i];
                BT[i]=BT[j];
                BT[j]=s;
                s=Extime[i];
                Extime[i]=Extime[j];
                Extime[j]=s;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        WT[0]=0;
        TT[0]=BT[0];
            WT[i+1]=BT[i]+WT[i];
            TT[i+1]=TT[i]+BT[i+1];
            W1=W1+WT[i];
            _TAT=_TAT+TT[i];
            AWT =W1/n;
            ATAT = _TAT/n;
    }

    printf("\n process\tBT\tTWT\tTAT\tPO\n");
    for(i=0;i<n;i++)
        printf("%d \t %d \t %d \t %d \t %d\n",Extime[i],BT[i],WT[i],TT[i],PO[i]);
        printf("AW=%f\t AT=%f \n",AWT,_TAT);
    return 0;
}

