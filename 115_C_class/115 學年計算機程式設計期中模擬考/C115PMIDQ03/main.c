/* Problem C115PMIDQ03: Properties of Two Vectors
 *
 * Input:
 * The first line of input is an integer `T (T < 50)` that indicates the number of test cases. Each case is a line consisting of two 3D vectors. The two vectors are represented as "`(a,b,c),(d,e,f)`" without any space between the parentheses or commas.
 *
 * Output:
 * For each case, output the case number in one line and followed by each result (addition, subtraction and dot product) in separated lines. Adhere to the sample for exact format. Each floating number in the results should be rounding to two decimal places.
 */
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input_count = 0;
    if (scanf("%d", &input_count) == -1 || input_count >= 50 || input_count <= 0)
    {
        return 0;
    }
    for (int i = 0; i < input_count; i++)
    {
        double a_v[3] = {0.0}, b_v[3] = { 0.0 };
        if (scanf("\n(%lf,%lf,%lf),(%lf,%lf,%lf)",&a_v[0], &a_v[1], &a_v[2], &b_v[0], &b_v[1], &b_v[2]) != -1)
        {
            printf("Case %i:\n", i + 1);
            printf("  Addition: (%.2lf,%.2lf,%.2lf)\n", a_v[0] + b_v[0],a_v[1] + b_v[1],a_v[2] + b_v[2]);
            printf("  Subtraction: (%.2lf,%.2lf,%.2lf)\n", a_v[0] - b_v[0],a_v[1] - b_v[1],a_v[2] - b_v[2]);
            printf("  Dot: %.2lf", a_v[0] * b_v[0] + a_v[1] * b_v[1] + a_v[2] * b_v[2]);
            if (i + 1 < input_count)
            {
                printf("\n");
            }
        }
    }
    //int n;
    //double point[10][2];

    //if (scanf("%d", &n) != 1 || n <= 0 || n > 10)
    //    return 0;

    //for (int i = 0; i < n; i++)
    //{
    //    if (scanf("%lf %lf", &point[i][0], &point[i][1]) != 2)
    //        return 0;
    //}
    //// Write your solution here
    //return 0;
}
