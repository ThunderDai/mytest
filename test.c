#include "stdio.h"
#include "string.h"

#define AA               (1)
#define AAAA             (1)
#define CCCCCCCCCCCCCCCC (1)
// test define after comment
#define EEEE (0)

#define DD (1) // test define after empty line

struct A {
    int            a;
    int            bbbbb;
    long int       c;
    unsigned char* d;
    // test after comment
    int e;

    int f; // test across empty line
};

// test these empty lines need to be removed and keep just one line

enum B {
    B_1,
    B_222222 = 100,
    B_333333 = 101,
    B_44444444444444444 = 105,
};

union C {
    int            a;
    int            bbbbb;
    long int       c;
    unsigned char* d;
};
typedef struct complex_struct {
    unsigned int a;
    int          b;
    int          c;
    union aa {
        int  d;
        int  e;
        char c;
    } aa_inst;
    struct inline_struct {
        int                i;
        int                j;
        int                kkkkkkkkkkkk;
        unsigned long long v;
    } bb_inst;
    int       m;
    int       d;
    short int jjj;
} complex;

int test_func(int a, int ccccccccccccccccccccccccccccc, int dddddddddddddddddddddddddddddddd,
              int ggggggggggggggggggggggggggggggggggggggggg, int vvv, int mmm)
{ // long argment need to be aligned
    int first_arg;
    int second_arg = 0;
    long long* third_arg = NULL;
    return 0;
}

struct CCCC {
    int                   test_mid_1;
    char                  test_mid_2;
    struct complex_struct mid_arg_3;
};

int g_a; // extra space need to be removed
int g_b;
const static int g_c = 10000;

int test_func2(int d)
{
    int first_arg;
    int second_arg = 0;
    long long* third_arg = NULL;
    // test for complex struct alignment
    complex v[] = {
        {
            .a = 10,
            .b = 1000,
            .c = 20,
            .aa_inst =
                {
                    .c = 10,
                },
            .bb_inst = {.i = 1, .j = 2, .kkkkkkkkkkkk = 10, .v = 400000},
            .m = 100,
            .d = 1,
        },
        {
            .a = 10,
            .b = 1000,
            .c = 20,
            .m = 100,
            .d = 1,
            .bb_inst = {.i = 1, .j = 2, .kkkkkkkkkkkk = 10, .v = 400000},
        },
        {
            .a = 10,
            .b = 1000,
            .c = 20,
            .aa_inst =
                {
                    .c = 10,
                },
            .m = 100,
            .d = 1,
        },
    };
    int v_arr[4][16] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16},
        {0x100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600},
        {11, 12, 31, 41, 15, 16, 17, 18, 19, 110, 111, 112, 113, 114, 115, 116},
        {91, 92, 9993, 9994, 5999, 9996, 9997, 9998, 9999, 1990, 1991, 1299, 1399, 1994, 1599, 1996},
    };

    if (second_arg == 0) {
        printf("not ok\n");
    } else if (second_arg == 1) {
        printf("second try\n");
    } else {
        printf("argument check ok\n");
    }
    switch (first_arg) {
        case 100: {
            printf("This is normal");
            break;
        }
        default:
            break;
    }
    for (int i = 0; i < 100; i++) {
        printf("Loop i %d\n", i);
        if (i < 50)
            continue;
        if (i > 60)
            break;
    }
    return 0;
}

void main()
{
    printf("Hello world\n");
}
