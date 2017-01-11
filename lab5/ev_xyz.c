#include "xyz.h"

/* Definitions */
void evidence_xyz_new()
{
    printf("*** testing xyz_new\n");
    printf("- expecting {1, 2, 3}:\n");
    xyz *test_vect = xyz_new(1, 2, 3);
    printf("{%lf %lf %lf}", test_vect->x, test_vect->y, test_vect->z);
    printf("\n");
}

void evidence_xyz_dup()
{
    printf("*** testing xyz_dup\n");
    printf("- expecting {2, 3, 4}:\n");
    xyz *vect1 = xyz_new(2, 3, 4);
    xyz *test_vect1 = xyz_dup(vect1);
    printf("{%lf %lf %lf}", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("\n");
}

void evidence_xyz_add()
{
    printf("*** testing xyz_add\n");
    printf("- expecting {5, 1, 6}:\n");
    xyz *vect1 = xyz_new(2, 3, 4);
    xyz *vect2 = xyz_new(3, -2, 2);
    xyz *test_vect1 = xyz_add(vect1, vect2);
    printf("{%lf %lf %lf}", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("\n");
}

void evidence_xyz_sub()
{
    printf("*** testing xyz_sub\n");
    printf("- expecting {10, 2, 0}: \n");
    xyz *vect1 = xyz_new(20, 2, 9);
    xyz *vect2 = xyz_new(10, 0, 9);
    xyz *test_vect1 = xyz_sub(vect1, vect2);
    printf("{%lf %lf %lf}", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("\n");
}

void evidence_xyz_neg()
{
    printf("*** testing xyz_neg\n");
    printf("- expecting {-20, 0, 9}: \n");
    xyz *vect1 = xyz_new(20, 0, -9);
    xyz *test_vect1 = xyz_neg(vect1);
    printf("{%lf %lf %lf}", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("\n");
}

void evidence_xyz_scale()
{
    printf("*** testing xyz_scale\n");
    printf("- expecting {-40, 0, 100}: \n");
    xyz *vect1 = xyz_new(-4, 0, 10);
    xyz *test_vect1 = xyz_scale(10.0, vect1);
    printf("{%lf %lf %lf}", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("\n");
}


void evidence_xyz_dot()
{
    printf("*** testing xyz_dot\n");
    printf("- expecting 50: \n");
    xyz *vect1 = xyz_new(-4, 0, 10);
    xyz *vect2 = xyz_new(10, 0, 9);
    printf("%lf", xyz_dot(vect1, vect2));
    printf("\n");
}

void evidence_xyz_mag()
{
    printf("*** testing xyz_mag\n");
    printf("- expecting 10: \n");
    xyz *vect1 = xyz_new(0, 0, 10);
    printf("%lf", xyz_mag(vect1));
    printf("\n");
}

void evidence_xyz_norm()
{
    printf("*** testing xyz_norm\n");
    printf("- expecting {0, 0, 1}: \n");
    xyz *vect1 = xyz_new(0, 0, 10);
    xyz *vect2 = xyz_new(5, 5, 5);
    xyz *test_vect1 = xyz_norm(vect1);
    xyz *test_vect2 = xyz_norm(vect2);
    printf("{%lf %lf %lf} \n", test_vect1->x, test_vect1->y, test_vect1->z);
    printf("- expecting {0.577, 0.577, 0.577}: \n");
    printf("{%lf %lf %lf} \n", test_vect2->x, test_vect2->y, test_vect2->z);
}

void evidence_xyz_tos()
{
    printf("*** testing xyz_tos\n");
    printf("- expecting {5, 5, 5}: \n");
    xyz *vect1 = xyz_new(5, 5, 5);
    char* vect_str = xyz_tos(vect1);
    int i = 0;
    while (vect_str[i] != '\0') {
        printf("%c", vect_str[i]);
        i++;
    }
    printf("\n");
}

void evidence_xyz_print()
{
    printf("*** testing xyz_print\n");
    printf("- expecting {5, 5, 5}: \n");
    xyz *vect1 = xyz_new(5, 5, 5);
    xyz_print(vect1);
    printf("\n");
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_xyz_new();
    evidence_xyz_dup();
    evidence_xyz_add();
    evidence_xyz_sub();
    evidence_xyz_neg();
    evidence_xyz_scale();
    evidence_xyz_dot();
    evidence_xyz_mag();
    evidence_xyz_norm();
    evidence_xyz_tos();
    evidence_xyz_print();
    return 0;
}
