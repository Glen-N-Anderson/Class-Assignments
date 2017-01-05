
bool is_valid_dimensions(char *m, char *n);
struct mult_div_values** create_table(char *m, char *n);
void set_mult_values(int **array, int rows, int cols);
void set_div_values(int **array, int rows, int cols);

struct mult_div_values{
        int mult;
        float div;
};

