#include <stdio.h>

int main()
{
    int ajtok[600]={0};

    for(int i=1; i<=600; i++)
    {
        for(int j=0; j<600; j++)
        {
            if((j+1)%i==0)
            {
                if(ajtok[j]==0)
                {
                    ajtok[j]=1;
                }
                else
                {
                    ajtok[j]=0;
                }
            }
        }
    }
    int nyitottak[600]={0};
    int ny=0;
    for(int i=0; i<600; i++)
    {
        if(ajtok[i]==1)
        {
            nyitottak[ny]=i+1;
            ny++;
        }
    }

    for(int i=0; i<ny-1; i++)
    {
        printf("%d, ",nyitottak[i]);
    }
    printf("%d\n",nyitottak[ny-1]);

    return 0;
}
