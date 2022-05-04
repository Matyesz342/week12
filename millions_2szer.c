#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2000
#define MULTIPLIER 1.5

typedef struct
{
    int *szamok;
    int elemszam;
    int capacity;
}DynArray;

DynArray * da_create()
{
    DynArray *result=malloc(sizeof(DynArray));
    if(result==NULL)
    {
        exit(2);
    }

    int initial_capacity=20;

    result->szamok=malloc(initial_capacity * sizeof(int));
    if(result->szamok==NULL)
    {
        exit(2);
    }
    result->elemszam=0;
    result->capacity=initial_capacity;
    return result;
}

void da_append(DynArray *self, int data)
{
    if(self->elemszam==self->capacity)
    {
        int new_capacity=(int)(MULTIPLIER*self->capacity);
        self->szamok=realloc(self->szamok, new_capacity*sizeof(int));
        if(self->szamok==NULL)
        {
            exit(2);
        }
        self->capacity=new_capacity;
    }
    self->szamok[self->elemszam]=data;
    self->elemszam++;
}

void da_clear(DynArray *self)
{
    free(self->szamok);
    free(self);
}

void da_destroy(DynArray *self)
{
    free(self->szamok);
    self->szamok= malloc(new_capacity * sizeof(int));
}

void gyorsrendez(int tomb[], int min, int max) 
{
   double vezer = tomb[(min+max)/2]; /* vezérelem: középső */
   int i = min, j = max;
   while (i <= j) {                  /* piros/kék válogatás */
      while (tomb[i] < vezer) ++i;
      while (tomb[j] > vezer) --j;
      if (i <= j) {
         double tmp = tomb[i];
         tomb[i] = tomb[j];
         tomb[j] = tmp;
         ++i;
         --j;
      }
   }
 
   if (min < j) gyorsrendez(tomb, min, j); /* rekurzió */
   if (i < max) gyorsrendez(tomb, i, max);
}

void gyorsrendez_indit(int tomb[], int meret) 
{
   gyorsrendez(tomb, 0, meret-1);
}


void tomb_kiir(int n, int tomb[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", tomb[i]);
    }
    
}

int main()
{
    for (int j = 0; j < 2; j++)
    {
        char* fajlnev="proba.txt";
        int i = 0;
        int *szam = NULL;
        char buffer[MAX];

        FILE *fp=fopen(fajlnev,"r");

        if(fp==NULL)
        {
            printf("Hiba tortent  a %s nevű fajl megnyitasakor!\n",fajlnev);
            exit(1);
        }

        DynArray *li=da_create();

        while(fgets(buffer, MAX, fp)!=NULL)
        {
            szam = realloc(szam, (i+1) * sizeof(int));
            szam[i]= atoi(buffer);

            da_append(li,szam[i]);
            i++;
        }
        da_clear(li);
        fclose(fp);
        gyorsrendez_indit(szam,i);
        tomb_kiir(i,szam);
        da_destroy(li);
        free(szam);
    }
    return 0;
}