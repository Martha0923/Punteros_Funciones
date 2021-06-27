#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user
{
    char username[100];
    int id;
    int register_year;
};

struct user server[] = {
    "jesse", 2312, 2021,
    "annk", 4331, 2021,
    "oroboros", 3952, 2017,
    "dokuro", 4316, 2019,
    "kkjus", 5332, 2011,
    "marvest", 9912, 2010,
    "eillek", 1092, 2020,
    "tuomas", 1292, 2015,
    "marko", 4131, 2016,
    "tarja", 1314, 2014};

/*
TODO
@function compare_username
@desc compares username of two user records.
*/
int compare_username(const void *a, const void *b)
{
    // La funcion de comparacion debe de devolver un entero menor que, igual o  mayor que cero.
    // tomando en cuenta si el primer valor el menor, igual o mayor que el segundo valor.
  
    // Creamos punteros

    struct user* stra = (struct user*)a;
    struct user* strb = (struct user*)b;

    // Usamos la funcion strcmp para calcular y devolver 
    // comparacion de ambos valores devuelve strcmp
    // cero si ambos valores son iguales.
    // un valor negativo si el primer valor es menor que el segundo.
    // un valor positivo si el primero valor es mayor que el segundo.

    return strcmp(stra->username, strb->username); // le pedimos que returne.
}

/*
TODO
@function compare_id
@desc compares id of two user records.
*/
int compare_id(const void *a, const void *b) 
{
    // Creamos punteros
    struct user* stra = (struct user*)a;
    struct user* strb = (struct user*)b;

    // Se pide que retorne  stra->id - strb->id, si valor a es menor que valor b
    // Sera negativo, de lo contario sera valor positivo.
   
    return stra->id - strb->id;
}

/*
TODO
@function compare_register_year
@desc compares register date of two user records.
*/
int compare_register_year(const void *a, const void *b)
{
    // creamos punteros.
    struct user* stra = (struct user*)a;
    struct user* strb = (struct user*)b;

    // Que retorne  stra->register_year - strb->register_year si a es menor que b
    // sera valor negativo, de lo contrario sera valor positivo.
   
    return stra->register_year - strb->register_year;
}

/*
@function printrec
@desc prints user record
*/
void printrec(void *prec, void *arg)
{
    struct user *pstud = (struct user *)prec;
    printf("%-20s %d %d\n", pstud->username, pstud->id, pstud->register_year);
}

/*!
@function apply
@desc applies
*/
void apply(struct user *sarr, int nrec, void (*fp)(void *prec, void *arg), void *arg)
{
    int i = 0;
    for (i = 0; i < nrec; i++)
    {
        /*callback*/
        fp(&sarr[i], arg);
    }
}

/*
@function isolder
@desc prints user record only if the user register is older than *((int*)arg)
*/
void isolder(void *prec, void *arg)
{
    struct user *pstud = (struct user *)prec;
    if (pstud->register_year > *((int*)arg))
        printf("%-20s %d %d\n", pstud->username, pstud->id, pstud->register_year);
}

int main()
{
    int nusers = sizeof(server) / sizeof(struct user);
    int n;

    puts("All user records:");
    puts("-------------------------------");
    apply(server, nusers, printrec, NULL);

    /*sort based on username*/
    puts("Sorted by username:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_username);
    apply(server, nusers, printrec, NULL);

    /*sort based on ID*/
    puts("Sorted by ID:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_id);
    apply(server, nusers, printrec, NULL);

    /*sort based on register date */
    puts("Sorted by register date:");
    puts("-------------------------------");
    qsort(server, nusers, sizeof(struct user), compare_register_year);
    apply(server, nusers, printrec, NULL);

    /*print people older than n*/
    puts("People older than n:");
    int age;
    scanf("%d", &age); // input age
    puts("-------------------------------");
    n = 0;
    apply(server, nusers, isolder, &age);
    return 0;
}
