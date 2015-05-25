#define MAX_INT_VALUE 6
#define PRECISION 1000
#define NUM_DECIMAL_VALUES (10*PRECISION)

double sinTable[MAX_INT_VALUE + NUM_DECIMAL_VALUES];
double cosTable[MAX_INT_VALUE + NUM_DECIMAL_VALUES];
void   tableSet();
double sin(double angle);
double cos(double angle);
double arctan(double angle);
double sqrt(double angle);

