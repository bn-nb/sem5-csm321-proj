% RICHARDSON'S ARMS RACE MODEL
% 01 November 2023

syms t x(t) y(t);

% X is arms expenditure of A
% Y is arms expenditure of B

% mn - ab > 0 for stable equilibrium
% Initially, both countries spend at same rate

a = 1.24;
b = 1.43;
m = 1.45;
n = 1.36;
r = -5.1;
s = -4.9;

eq1 = diff(x, t) == a*y - m*x + r;
eq2 = diff(y, t) == b*x - n*y + s;

% Initially Both countries had same budget
c1 = x(0) == 10;
c2 = y(0) == 10;

soln = dsolve([eq1, eq2], [c1, c2]);

% Plot x,y separately
hold on 
fplot(soln.x); fplot(soln.y);
xlim([0,80]); ylim([0,100]);
legend("Country A", "Country B");
