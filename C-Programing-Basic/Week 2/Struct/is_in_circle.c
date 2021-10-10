#include <stdio.h>
#include<math.h>

typedef struct point
{
    double x, y;
} point_t;

typedef struct circle
{
    point_t center;
    double radius;
} circle_t;

int is_in_circle(point_t *A, circle_t *C)
{
    double x_dist = A->x - C->center.x;
    double y_dist = A->y - C->center.y;
    return x_dist*x_dist + y_dist*y_dist <= C->radius * C->radius;  
}
int main()
{
    point_t p;
    circle_t c;
    
    printf("Enter point x = y = : ");
    scanf("%lf %lf", &p.x, &p.y);
    printf("\nEnter circle center x = y =:");
    scanf("%lf %lf", &c.center.x, &c.center.y);
    printf("\nEnter circle radius = ");
    scanf("%lf", &c.radius);
    if (is_in_circle(&p, &c))
    {
        printf("Point is in circle\n");
    }
    else printf("Point is out of circle\n");
    

    return 0;
}
