#include <stdio.h>

double solve_k(int [], double [], int, double, int);
double min(double, double);

void test1(void);

int
main(void)
{
    test1();

    return(0);
}

void 
test1(void)
{
    int num[] = { 3 , 2 };
    double price[] = { 4.00, 2.50 };
    int num_schemes = 2;
    double unit_price = 1.75;
    int num_items = 4;

    double ret;

    ret = solve_k(num, price, num_schemes, unit_price, num_items);

    printf("%f\n", ret);
}

/* [ 3 , 2 ]  ,  [ 4.00 , 2.50 ] , 2 , 1.75 , 1 */
/* [ 3 , 2 ]  ,  [ 4.00 , 2.50 ] , 2 , 1.75 , 4 */
double 
solve_k(int num[], double price[], int num_schemes, 
        double unit_price, int num_items)
{
    double best, result;
    int i;
    if(num_items == 0)
        return(0);
    else{
        result = solve_k(num, price, num_schemes, unit_price,
                              num_items - 1);
        best = result + unit_price;
        for(i = 0; i < num_schemes; i++)
            if(num_items - num[i] >= 0){
                result = solve_k(num, price, num_schemes, unit_price,
                                      num_items - num[i]);
                best = min(best, result + price[i]);
            }
        return(best);
    }
}

double
min(double v1, double v2)
{
    if(v1 < v2)
        return(v1);
    else
        return(v2);
}
