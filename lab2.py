# NAME: B Niranjan
# ROLL: 21124015
# DATE: 18th Aug 2023

import numpy as np

# Probabilities of D, H, R
P, Q, R = 0.4, 0.5, 0.1


############################################################
#                                                          #
#             When any two parents can cross               #
#                                                          #
############################################################


# Chance of offspring type in column When Two
# parents given by matrix and row are crossed
# D = 0; H = 1; R = 2
gene_chances = np.array([
    [#    D       H     R
         [1,      0,    0], # D*D
         [0.5,  0.5,    0], # D*H
         [0,      1,    0], # D*R
    ],
    [
         [0.5,  0.5,    0], # H*D
         [0.25, 0.5, 0.25], # H*H
         [0,    0.5,  0.5], # H*R
    ],
    [
         [0,      1,    0], # R*D
         [0,    0.5,  0.5], # R*H
         [0,      0,    1], # R*R
    ]
])


# Chance of getting Parents in row and column
# independent events -> take product
parent_probs = np.array([
    #  D    H    R
    [P*P, Q*P, R*P], # D
    [P*Q, Q*Q, R*Q], # H
    [P*R, Q*R, R*R]  # R
])


############################################################
#                                                          #
#     When atleast 1 parent has to be of specific type     #
#                                                          #
############################################################


# D = 0; H = 1; R = 2
def restricted_chances(index: int):
    restr_chances = gene_chances * 0  # Chances
    restr_parents = parent_probs * 0  # Parents 
 
    restr_chances[index,0] = gene_chances[index,0]
    restr_chances[0,index] = gene_chances[0,index]
    restr_parents[index,0] = parent_probs[index,0]
    restr_parents[0,index] = parent_probs[0,index]

dom_chance, dom_parents = restricted_chances(0)
hyb_chance, hyb_parents = restricted_chances(1)
rec_chance, rec_parents = restricted_chances(2)


for i in range(3):
    for j in range(3):
        c[i][j] = (a[:,:,i] *  a[:,:,j] * b).sum()

