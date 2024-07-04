% DOMAR FIRST DEBT MODEL

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 11th October 2023

syms t d(t) y(t);
a = 0.01;
b = 10;

eqn2 = diff(d,t) == a*y;
eqn1 = diff(y,t) == b;

odes = [eqn1, eqn2];
c1 = d(0) == 1;
c2 = y(0) == 10;

soln = dsolve(odes, [c1, c2]);
d = soln.d;
y = soln.y;

fplot(d);
hold on
fplot(y);
xlim([0,250]);
legend("Debt", "Income");
