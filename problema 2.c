#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


typedef struct crypto
{
    char denumire[50];
    float pret;
    int anul;


}crypto;



int citire_elemente_tablou(crypto * tablou,int n);
int afisare_elemente_tablou(crypto * tablou,int n);
int cautare(crypto * tablou,int n);
int inserare_capat(crypto * tablou,int n);
int inserare_inceput(crypto * tablou,int n);
int inserare(crypto *tablou,int n);
int stergere(crypto *tablou,int n);
int sortare(crypto *tablou,int n);

int main()
{
    system("cls");
    int n;
    printf("Dati numarul de elemente din tablou:\n");
    scanf("%d",&n);
    crypto * monede = calloc(n,sizeof(crypto));

    system("cls");

    system("cls");
    int num;
    Menu:
    printf("Meniu\n");
    printf("Apasa:\n");
    printf("1 -- pentru citire de la tastatura a elementelor tabloului\n");
    printf("2 -- pentru afisare a elementelor din tablou\n");
    printf("3 -- pentru cautarea unui element si afisarea lui\n");
    printf("4 -- pentru eliberarea memoriei tabloului\n");
    printf("5 -- sortarea elementelor dupa un camp al structurii\n");
    printf("6 -- pentru inserarea unui element nou la capatul tabloului\n");
    printf("7 -- pentru inserarea unui element nou la inceputul tabloului\n");
    printf("8 -- pentru insearea unui element la o pozitie X (introdusa de la tastatura) in cadrul tabloului\n");
    printf("9 -- pentru stergerea unui element de pe o pozitie X ( introdusa de la tastatura) din cadrul tabloului\n");
    printf("0 -- pentru a iesi din program\n");
    printf("\n");
    scanf("%d",&num);
    system("cls");
    switch(num)
    {
        case 1:
            {
                citire_elemente_tablou(monede,n);
                goto Menu;

            }
        case 2:
            {
                char c;
                afisare_elemente_tablou(monede,n);
                goto Menu;

            }
        case 3:
            {
                cautare(monede,n);
                goto Menu;
            }
        case 4:
            {
                free(monede);
                goto Menu;
            }
        case 5:
            {
                sortare(monede,n);
                goto Menu;
            }
        case 6:
            {
                inserare_capat(monede,n);
                goto Menu;
            }
        case 7:
            {
                inserare_inceput(monede,n);
                goto Menu;
            }
        case 8:
            {
                inserare(monede,n);
                goto Menu;
            }
        case 9:
            {
               stergere(monede,n);
               goto Menu;
            }
        case 0:
        {
            return 0;
        }
    }




    return 0;
}



int citire_elemente_tablou(crypto * tablou,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Dati denumirea %d cryptomonede\n",i+1);
        scanf("%s",&tablou[i].denumire);
        printf("Dati pretul %d cryptomonede\n",i+1);
        scanf("%f",&tablou[i].pret);
        printf("Dati anul %d cryptomonede\n",i+1);
        scanf("%d",&tablou[i].anul);
        system("cls");

    }

}


int afisare_elemente_tablou(crypto * tablou,int n)
{
    int i;
    char c;
    for(i=0; i<n; i++)
    {
        printf("%d moneda\n",i+1);
        printf("Denumirea --- %s\n",tablou[i].denumire);
        printf("Pret      --- %.3f$\n",tablou[i].pret);
        printf("Anul      --- %d\n",tablou[i].anul);

        printf("------------------------------------- \n");
    }

    printf("Apasati orice tasta pentru a continua\n");
    getch();
    system("cls");



}

int cautare(crypto * tablou,int n)
{   int i,k;
    int criteriu;
    char verificare[50];
        printf("Introduceti criteriul de cautare:\n denumire - 1 \n pret - 2 \n anul - 3\n");
                scanf("%d",&criteriu);
                switch(criteriu)
                    {
                    case 1:
                            {
                                printf("Introdu denumirea monedei:\n");
                                scanf("%s",verificare);
                                for(i=0;i<n;i++)
                                {
                                    for(int j=0; j<strlen(tablou[i].denumire);j++)
                                    if(verificare[j] == tablou[i].denumire[j])
                                        k++;
                                    if(k == strlen(tablou[i].denumire))
                                    {
                                        printf("A fost gasit un element in pozitia %d\n",i+1);
                                        printf("Denumirea --- %s\n",tablou[i].denumire);
                                        printf("Pret      --- %.3f$\n",tablou[i].pret);
                                        printf("Anul      --- %d\n",tablou[i].anul);
                                        return 0;
                                    }
                                    else
                                    {
                                        printf("Nu a fost gasit acest element\n");
                                        return 0;
                                    }
                                }
                            }

                    case 2:
                        {
                            float pret;
                            printf("Introdu pretul monedei\n");
                            scanf("%f",&pret);

                            for(i=0;i<n;i++)
                            {
                                if (pret == tablou[i].pret)
                                {
                                    printf("A fost gasit un element in pozitia %d\n",i+1);
                                    printf("Denumirea --- %s\n",tablou[i].denumire);
                                    printf("Pret      --- %.3f$\n",tablou[i].pret);
                                    printf("Anul      --- %d\n",tablou[i].anul);
                                    return 0;
                                }
                                else
                                {
                                    printf("Nu a fost gasit acest element\n");
                                    return 0;
                                }
                            }


                        }
                    case 3:
                        {
                            int an;
                            printf("Introdu anul monedei\n");
                            scanf("%d",&an);

                            for(i=0;i<n;i++)
                            {
                                if (an == tablou[i].anul)
                                {
                                    printf("A fost gasit un element in pozitia %d\n",i+1);
                                    printf("Denumirea --- %s\n",tablou[i].denumire);
                                    printf("Pret      --- %.3f$\n",tablou[i].pret);
                                    printf("Anul      --- %d\n",tablou[i].anul);
                                    return 0;
                                }
                                else
                                {
                                    printf("Nu a fost gasit acest element\n");
                                    return 0;
                                }
                            }


                        }

                    }


}


int inserare_capat(crypto * tablou,int n)
{

    int i;
    char c;
    tablou = realloc(tablou,n+1);

    printf("Dati denumirea %d cryptomonede\n",n+1);
    scanf("%s",&tablou[n].denumire);
    printf("Dati pretul %d cryptomonede\n",n+1);
    scanf("%f",&tablou[n].pret);
    printf("Dati anul %d cryptomonede\n",n+1);
    scanf("%d",&tablou[n].anul);
    system("cls");


    afisare_elemente_tablou(tablou, n+1);
    printf("Apasati orice tasta pentru a continua\n");
    getch();
    system("cls");


}


int inserare_inceput(crypto * tablou,int n)
{
	int i;
	tablou = realloc(tablou,n+1);

	for(i=n;i>0;i--)
	{
        tablou[i] = tablou[i-1];

	}

    printf("Dati denumirea %d cryptomonede\n",1);
    scanf("%s",&tablou[0].denumire);
    printf("Dati pretul %d cryptomonede\n",1);
    scanf("%f",&tablou[0].pret);
    printf("Dati anul %d cryptomonede\n",1);
    scanf("%d",&tablou[0].anul);
    system("cls");

	afisare_elemente_tablou(tablou, n+1);
	printf("Apasati orice tasta pentru a continua\n");
    getch();
}

int inserare(crypto * tablou,int n)
{
    int x;
    tablou = realloc(tablou,n+1);
    printf("Dati o pozitie dorita\n");
    citire:
        scanf("%d",&x);
        if(x>n+1)
        {   printf("Elementul e prea mare");
            goto citire;
        }

    int i;
    for (i = (n+1)-1; i >= x; i--)
        tablou[i] = tablou[i - 1];

    printf("Dati denumirea %d cryptomonede\n",x);
    scanf("%s",&tablou[x-1].denumire);
    printf("Dati pretul %d cryptomonede\n",x);
    scanf("%f",&tablou[x-1].pret);
    printf("Dati anul %d cryptomonede\n",x);
    scanf("%d",&tablou[x-1].anul);
    system("cls");

    afisare_elemente_tablou(tablou, n+1);
    printf("Apasati orice tasta pentru a continua\n");
    getch();
    system("cls");

}

int stergere(crypto *tablou,int n)
{
    int x;
        printf("Dati o pozitie dorita\n");
    citire:
        scanf("%d",&x);
        if(x>n)
        {   printf("Elementul e prea mare");
            goto citire;
        }
        int i;

        for (i = x - 1; i < n - 1; i++)
            tablou[i] = tablou[i+1];

        for(i=0; i<n-1; i++)
        {
            printf("%d moneda\n",i+1);
            printf("Denumirea --- %s\n",tablou[i].denumire);
            printf("Pret      --- %.3f$\n",tablou[i].pret);
            printf("Anul      --- %d\n",tablou[i].anul);

            printf("------------------------------------- \n");
        }
        printf("Apasati orice tasta pentru a continua\n");
        getch();
        system("cls");


}

int sortare(crypto * tablou,int n)
{
    int num;
    printf("Alege campul pentru sortare:\n");
    printf("\n denumire - 1 \n pret - 2 \n anul - 3\n");
    scanf("%d",&num);


    int i,j;

    switch(num)
    {
        case 1:
            {
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(strcmp(tablou[i].denumire,tablou[j].denumire) == -1 )
                            tablou[i] = tablou[j];
                    }
                }
                break;

            }
        case 2:
            {
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(tablou[i].pret > tablou[j].pret)
                            tablou[i] = tablou[j];
                    }
                }
                break;
            }
        case 3:
            {
                for(i=0;i<n;i++)
                {
                    for(j=i+1;j<n;j++)
                    {
                        if(tablou[i].anul > tablou[j].anul)
                            tablou[i] = tablou[j];
                    }
                }
                break;

            }

    }



}
