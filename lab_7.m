% DOMAR'S SECOND DEBT MODEL

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 11th October 2023

syms t y(t) d(t);

a = 0.01;
b = 0.1;

eqn1 = diff(y,t) == b*y;
eqn2 = diff(d,t) == a*y;

odes = [eqn1, eqn2];
c1 = d(0) == 1;
c2 = y(0) == 10;

soln = dsolve(odes, [c1, c2]);
d = soln.d;
y = soln.y;

fplot(d);
hold on
fplot(y);
xlim([0,20]);
ylim([0,100]);
legend("Debt", "Income");