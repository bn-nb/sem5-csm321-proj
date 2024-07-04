% DOMAR'S MACRO MODEL

% B Niranjan IDD M&C Part 3 Roll : 21124015 11th October 2023

syms t s(t) i(t) y(t);

% a: proportion of national income
% b: factor of y'

a = 0.035;
b = 0.92;

eqn1 = s == a*y;
eqn2 = i == b*diff(y,t);
eqn3 = s == i;

% s == i, eliminate redundant eqns
ode(t) = a*y == b*diff(y,t);
c1 = y(0) == 100;

y = dsolve(ode, c1);
fplot(y, [0, 100])