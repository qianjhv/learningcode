#include <stdio.h>
#include <math.h>

#define HARMONIC_MEAN(x, y) (1.0 / ((1.0 / (x) + 1.0  / (y)) / 2.0))

typedef struct {
    double r;
    double theta;
} Polar;

typedef struct {
    double x;
    double y;
} Rectangular;

Rectangular polar_to_rect(Polar *p);

int main(void) {

    printf("%f\n", HARMONIC_MEAN(5, 2));
    printf("-------------------------------------------\n");

    Polar p;
    Rectangular r;
    while (scanf("%lf %lf", &p.r, &p.theta) == 2) {
        r = polar_to_rect(&p);
        printf("%lf, %lf\n", r.x, r.y);
    }

    return 0;
}

Rectangular polar_to_rect(Polar *p) {
    Rectangular rect;
    const double ANGLE = M_PI / 180.0 * (p -> theta);

    rect.x = (p -> r) * cos(ANGLE);
    rect.y = (p -> r) * sin(ANGLE);

    return rect;
}

