#include<stdio.h>
#include<stdio.h>

typedef struct
{
    int marked, s, f;
    char name[100];
}activity;

activity ac[100];

void print(int *v, int no)
{
    printf("I chose %d activities!\n", no);
    for(int i = 0; i < no; i++)
        printf("(%2d) %2d : %2d %s", v[i], ac[v[i]].s, ac[v[i]].f, ac[v[i]].name);
}

void selection(int *v, int *ac_no, int n)
{
    int ok = n, k = 0;
    while(ok)
    {
        int sf = 101, auxi = 0;
        for(int i = 0; i < n; i++)
        {
            if(sf > ac[i].f && ac[i].marked == 0)
            {
                ac[i].marked = 1;
                sf = ac[i].f;
                auxi = i;
                ok--;
            }
        }
        v[k++] = auxi;
        (*ac_no)++;
    }
}

int main()
{
    FILE *f = fopen("date_activitati.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        ac[i].marked = 0;
        fscanf(f, "%d %d", &ac[i].s, &ac[i].f);
        fgets(ac[i].name, 100, f);
    }
    fclose(f);

    int v[100] = {};
    int ac_no = 0;
    selection(v, &ac_no, n);
    print(v, ac_no);

    return 0;
}
