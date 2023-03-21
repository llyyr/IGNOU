// Q2. Write the functions in C for the following:
// (a) To calculate the power without using the pow(x,y) function of <;math.h>.
// (b) To calculate the cube of a given number.
// (c) To calculate the LCM of two given numbers

// (a)
int Pow(int a, int b)
{
    int ret = 1, i;
    for (i = 1; i <= b; ++i) {
        ret *= a;
    }
    return ret;
}

// (b)
double Cube(double n)
{
    return (n * n * n);
}

// (c)
int LCM(int n1, int n2)
{
    int max = (n1 > n2) ? n1 : n2;
    while (1) {
        if ((max % n1 == 0) && (max % n2 == 0)) {
            return max;
        }
        ++max;
    }
}
