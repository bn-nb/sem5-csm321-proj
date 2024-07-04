/*

NAME: B Niranjan
ROLL: 21124015
DATE: 18th Aug 2023

*/


#include <bits/stdc++.h>
#define NUM_GENES 3
using namespace std;

typedef vector< vector< vector<double> > > CUBE;
typedef vector< vector<double> > MATRIX;


MATRIX& get_next_gen(MATRIX& V_old, CUBE& M_g) {

    // Returns V_new, probabilities of gene types in i+1 th gen

    // V_old has probabilities of gene-types in ith generation
    // Dimension 0 -> 0,1,2... Gene type of parent 1
    // Dimension 1 -> 0,1,2... Gene type of parent 2
    // Elt -> Probability of Parent Combination DOxD1

    // M_g has probabilities of offspring type given parents type
    // Dimension 0 -> 0,1,2... Gene type of parent 1
    // Dimension 1 -> 0,1,2... Gene type of parent 2
    // Dimension 2 -> 0,1,2... Offspring Type
    // Elt -> Prob of getting Off in D3, when parents are D1xD2

    static MATRIX V_new(NUM_GENES, vector<double>(NUM_GENES));

    double FACTOR {0.0};

    for (auto& x : V_old)
        for (auto& y : x)
            FACTOR += y;
    
    for (size_t i = 0; i < NUM_GENES; i++)
        for (size_t j = 0; j < NUM_GENES; j++)
            V_new[i][j] = 0;

    for (size_t i = 0; i < NUM_GENES; i++)
        for (size_t j = 0; j < NUM_GENES; j++)
            for (size_t k = 0; k < NUM_GENES; k++)
                for (size_t l = 0; l < NUM_GENES; l++)
                    V_new[i][j] += (M_g[k][l][i] * M_g[k][l][j] * V_old[k][l]) / FACTOR;

    return V_new;
}

void print_Gen_Matrix(MATRIX& V) {
    puts("");
    for (auto& y : V)    {
        printf("\t");
        for (auto& z : y)    {
            printf("%.5lf\t", z);
        }
        puts("");
    }
    puts("");
}

int main(int argc, char const *argv[])    {
    
    double P{0.4}, Q{0.5}, R{0.1};
    // cout << "Probability of D: "; cin >> P;
    // cout << "Probability of H: "; cin >> Q;

    // if (P+Q <= 1 && P+Q >= 0) {
    //     R = 1 - (P+Q);
    //     cout << "Probability of R: " << R << "\n";
    // } else {
    //     cout << "Invalid Values\n";
    //     return -1;
    // }
    
    int N; cout << "Number of Generations: "; cin >> N;

    // Ratios of offsprings when Parents breed
    // Index 0     -> cube for all breed cross
    // Index (i+1) -> cube if one parent has to be 'i'
    // Here, 0-> ALL, 1->D, 2->H, 3->R


    CUBE GENE_RATIOS[NUM_GENES+1] {
        {
            { /* D */   /* D     H   R */
                /* D */ {1,      0,  0}, 
                /* H */ {0.5,  0.5,  0},
                /* R */ {0,      1,  0},
            },
            { /* H */   /* D     H   R */
                /* D */ {0.5,  0.5,  0}, 
                /* H */ {0.25, 0.5,  0.25},
                /* R */ {0,    0.5,  0.5},
            },
            { /* R */   /* D     H   R */
                /* D */ {0,      1,  0}, 
                /* H */ {0,    0.5,  0.5},
                /* R */ {0,      0,  1},
            },
        },

        {
            { /* D */   /* D     H   R */
                /* D */ {1,      0,  0}, 
                /* H */ {0.5,  0.5,  0},
                /* R */ {0,      1,  0},
            },
            { /* H */   /* D     H   R */
                /* D */ {0.5,  0.5,  0}, 
                /* H */ {0, 0, 0},
                /* R */ {0, 0, 0},
            },
            { /* R */   /* D     H   R */
                /* D */ {0, 1, 0}, 
                /* H */ {0, 0, 0},
                /* R */ {0, 0, 0},
            },
        },

        {
            { /* D */   /* D     H   R */
                /* D */ {0,      0,  0}, 
                /* H */ {0.5,  0.5,  0},
                /* R */ {0,      0,  0},
            },
            { /* H */   /* D     H   R */
                /* D */ {0.5,  0.5,  0}, 
                /* H */ {0.25, 0.5,  0.25},
                /* R */ {0,    0.5,  0.5},
            },
            { /* R */   /* D     H   R */
                /* D */ {0,      0,  0}, 
                /* H */ {0,    0.5,  0.5},
                /* R */ {0,      0,  0},
            },
        },

        {
            { /* D */   /* D     H   R */
                /* D */ {0,      0,  0}, 
                /* H */ {0,  0,  0},
                /* R */ {0,      1,  0},
            },
            { /* H */   /* D     H   R */
                /* D */ {0,  0,  0}, 
                /* H */ {0, 0,  0},
                /* R */ {0,    0.5,  0.5},
            },
            { /* R */   /* D     H   R */
                /* D */ {0,      1,  0}, 
                /* H */ {0,    0.5,  0.5},
                /* R */ {0,      0,  1},
            },
        },
    };

    // Ratios of genetypes in population at some generation
    // Index 0     -> cube for all breed cross
    // Index (i+1) -> cube if one parent has to be 'i'
    // Here, 0-> ALL, 1->D, 2->H, 3->R

    MATRIX POP_PROBS[NUM_GENES+1] {
        {
            /*  D    H    R */
            {  P*P, Q*P, R*P}, /* D */ 
            {  P*Q, Q*Q, R*Q}, /* H */ 
            {  P*R, Q*R, R*R}, /* R */ 
        },

        {
            /*  D    H    R */
            {  P*P, Q*P, R*P}, /* D */ 
            {  P*Q,   0,   0}, /* H */ 
            {  P*R,   0,   0}, /* R */ 
        },

        {
            /*  D    H    R */
            {    0, Q*P,   0}, /* D */ 
            {  P*Q, Q*Q, R*Q}, /* H */ 
            {    0, Q*R,   0}, /* R */ 
        },

        {
            /*  D    H    R */
            {    0,   0, R*P}, /* D */ 
            {    0,   0, R*Q}, /* H */ 
            {  P*R, Q*R, R*R}, /* R */ 
        },
    };

    // print_Gen_Matrix(get_next_gen(POP_PROBS[0], GENE_RATIOS[0]));

    for (int i = 0; i < N; i++)    {
        printf("Generation : %d\n", i+1);
        for (int j = 0; j < NUM_GENES+1; j++)    {
            POP_PROBS[j] = get_next_gen(POP_PROBS[j], GENE_RATIOS[j]);
            print_Gen_Matrix(POP_PROBS[j]);
        }
    }

    return 0;
}
