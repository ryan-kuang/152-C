#include "color.h"

void evidence_make_color()
{
    printf("*** testing make_color\n");
    printf("- expecting {1, 0, 0.3}:\n");
    color *test_color = make_color(1, 0, 0.3);
    printf("{%lf %lf %lf}", test_color->r, test_color->g, test_color->b);
    printf("\n");
}

void evidence_color_new()
{
    printf("*** testing color_new\n");
    printf("- expecting {1, 0, 0.3}:\n");
    //color *test_color = color_new(1, 2, 3);
    //error tested
    color *test_color1 = color_new(1, 0, 0.3);
    printf("{%lf %lf %lf}", test_color1->r, test_color1->g, test_color1->b);
    printf("\n");
}

void evidence_color_dup()
{
    color *c1 = make_color(0.5, 1, 1.5);
    printf("*** testing color_dup\n");
    printf("- expecting {0.5, 1, 1.5}:\n");
    color *test_color = color_dup(c1);
    printf("{%lf %lf %lf}", test_color->r, test_color->g, test_color->b);
    printf("\n");
}

void evidence_color_modulate()
{
    color *c1 = make_color(1, 2, 3);
    color *c2 = make_color(2, 1, 4);
    printf("*** testing color_modulate\n");
    printf("- expecting {2, 2, 12}:\n");
    color *test_color = color_modulate(c1, c2);
    printf("{%lf %lf %lf}", test_color->r, test_color->g, test_color->b);
    printf("\n");
}

void evidence_within_bounds()
{
    printf("*** testing within_bounds\n");
    printf("- expecting 0: %lf \n", -2.0);
    printf("- expecting 1: %lf \n", 3.0);
    printf("\n");
}

void evidence_color_scale()
{
    color *c3 = make_color(3, 0, 1);
    printf("*** testing color_scale\n");
    printf("- expecting {1, 0, 0.5}: \n");
    color *test_color = color_scale(0.5, c3);
    printf("{%lf %lf %lf}", test_color->r, test_color->g, test_color->b);
    printf("\n");
}

void evidence_color_add()
{
    color *c3 = make_color(3, 0, 1);
    color *c4 = make_color(-2, 0.2, -0.5);
    printf("*** testing color_add\n");
    printf("- expecting {1, 0.2, 0.5}: \n");
    color *test_color = color_add(c3, c4);
    printf("{%lf %lf %lf}", test_color->r, test_color->g, test_color->b);
    printf("\n");
}

void evidence_color_tos()
{
    color *c1 = make_color(0.5, 1, 1.5);
    printf("*** testing color_tos\n");
    printf("- expecting {0.5, 1, 1.5}: \n");
    char* color_str = color_tos(c1);
    int i = 0;
    while (color_str[i] != '\0') {
        printf("%c", color_str[i]);
        i++;
    }
    printf("\n");
}

void evidence_color_print()
{
    color *c1 = make_color(0.5, 1, 1.5);
    printf("*** testing color_print\n");
    printf("- expecting {0.5, 1, 1.5}: \n");
    color_print(c1);
}

void evidence_color_print_bytes()
{
    color *c1 = make_color(0.5, 1, 1.5);
    printf("*** testing color_print_bytes\n");
    printf("- expecting {128, 255, 255}: \n");
    color_print_bytes(c1);
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_make_color();
    evidence_color_new();
    evidence_color_dup();
    evidence_color_modulate();
    evidence_color_scale();
    evidence_color_add();
    evidence_color_tos();
    evidence_color_print();
    evidence_color_print_bytes();
    return 0;
}
