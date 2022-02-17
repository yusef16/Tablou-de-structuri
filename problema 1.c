#include <stdio.h>
#include <conio.h>
#include <string.h>


    typedef struct crypto
    {
        char denumire[50];
        float pret;
        int anul;


    }crypto;

int main()
{
    system("cls");
    crypto tablou[100];


    int n;
    printf("Dati numarul de elemente din tablou:\n");
    scanf("%d",&n);
    int i;
    system("cls");

    // citire
    for(i=0; i<n; i++)
    {
        printf("Dati denumirea %d cryptomonede\n",i+1);
        scanf("%s",&tablou[i].denumire);
        printf("Dati pretul %d cryptomonede\n",i+1);
        scanf("%f",&tablou[i].pret);
        printf("Dati anul %d cryptomonede\n",i+1);
        scanf("%d",&tablou[i].anul);
        system("cls");

    }

    // afisare

    for(i=0; i<n; i++)
    {
        printf("%d moneda\n",i+1);
        printf("Denumirea --- %s\n",tablou[i].denumire);
        printf("Pret      --- %.3f$\n",tablou[i].pret);
        printf("Anul      --- %d\n",tablou[i].anul);

        printf("------------------------------------- \n");
    }
    printf("\n");

    printf("\n");


    int v = 0;
    int criteriu = 0;
    char verificare[50];
    int k = 0;
    printf("Doriti sa cautati o moneda dupa un anumit criteriu?\n");
    printf("Tastati 1 daca DA \n");
    printf("Tastati 2 daca NU \n");
    scanf("%d",&v);
    system("cls");
    switch(v)
    {
        case 1:
            {
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
            case 2:
                {
                    return 0;
                }

    }


    return 0;
}
