#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#define eps 0.0001

double f(double x);
double method_hord(double x1, double x2, unsigned int N, unsigned int debug);
double method_halfDiv(double x1, double x2, unsigned int N, unsigned int debug);


int main()
{

    double x1, x2, root;
    unsigned int var;
    unsigned int N, debug;


    printf("Choose variant ");
    scanf_s("%u", &var);
    printf("\nN=");
    scanf_s("%u", &N);
    printf("\ndebug=");
    scanf_s("%u", &debug);

    do {
 printf("Choose x1=");
        scanf_s("%lf", &x1);
        printf("Choose x2=");
        scanf_s("%lf", &x2);
    } while (f(x1) * f(x2) > 0);



    while ( var != 1 && var != 2){
        printf("\nERROR. Choose Method: 1 or 2 ");
        scanf_s("%u", &var);
    }
    if (var == 1) {
        root = method_hord(x1, x2, N, debug);
        printf("\n\nx=%lf   f(x)=%lf", root, f(root));
    }
    else if (var == 2) {

        root = method_halfDiv(x1, x2, N, debug);
        printf("\n\nx=%lf   f(x)=%lf", root, f(root));


    }
    while (debug != 0 && debug != 1)
    {
        printf("\nERROR. Choose debug: 0 or 1 ");
        scanf_s("%u", &debug);}
    return 0;
}


//-----------------------------------------------------------------
double f(double x)
{
    return sqrt(pow(x,9)+7);
}
//------------------------------------------------------------------

double method_hord(double x1, double x2, unsigned int N, unsigned int debug)
{
   double xi;
    int n=1;

    do{
       xi = (f(x2)*x1-f(x1)*x2) / ( f(x2)-f(x1) );

       if ( f(xi)*f(x1) > 0 )
            x1 = xi;
       else
            x2 = xi;


       if(debug == 1){
               printf("\n%d  %lf    %lf", n, xi, f(xi));

       n++;

    }

  else if (debug == 0) {

        xi = (f(x2) * x1 - f(x1) * x2) / (f(x2) - f(x1));

        if (f(xi) > 0)
            x1 = xi;
        else
            x2 = xi;}

    } while (fabs(f(xi)) > eps);



    return xi;
}



double method_halfDiv(double x1, double x2, unsigned int N, unsigned int debug)
{
    //double eps = 0.0001;
    double xi;
    int n = 1;

    while (debug != 0 && debug != 1)
    {
        printf("\nERROR. Choose debug: 0 or 1 ");
        scanf_s("%u", &debug);
    }

    if (debug == 0) {

        do {
            xi = (x1 + x2) / 2;

            if (f(xi) > 0)
                x1 = xi;
            else
                x2 = xi;

        } while ((fabs(f(x1) - f(x2))) > eps);

    }


    else if (debug == 1) {

        do {
            xi = (x1 + x2) / 2;

            if (f(xi) > 0)
                x1 = xi;
            else
                x2 = xi;
            printf("\n%d  %lf    %lf", n, xi, f(xi));

            n++;
        } while ((fabs(f(x1) - f(x2))) > eps);

    }
    return xi;
}
