#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Wrong number of arguments\n");
        printf("Usage: name <a> <b> <c>\n");
    }
    
    double a,b,c;
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]);
    if (a == 0) {
        if (b == 0) {
            printf("Phuong trinh vo nghiem!");
        } else {
            printf("Phuong trinh co mot nghiem: x = %f", (-c / b));
        }
}
    float delta = b*b - 4*a*c;
    float x1;
    float x2;
   	if (delta > 0) {
        x1 = (float) ((-b + sqrt(delta)) / (2*a));
        x2 = (float) ((-b - sqrt(delta)) / (2*a));
        printf("Phuong trinh co 2 nghiem la: x1 = %f va x2 = %f", x1, x2);
    } else if (delta == 0) {
        x1 = (-b / (2 * a));
        printf("Phong trinh co nghiem kep: x1 = x2 = %f", x1);
    } else {
        printf("Phuong trinh vo nghiem!");
    }
	return 0;
}
