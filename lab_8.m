% ALLEN'S SPECULATIVE MODEL

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 11th October 2023

% display format
format shortEng;

% DEBT, PRICE AND SUPPLY
syms t p(t) d(t) s(t);

a0 = 0.5684;
a1 = -.5137;
a2 = 0.5874;

b0 = 0.5478;
b1 = 0.5712;
b2 = -.5932;

% DEMAND == SUPPLY FOR EQUILIBRIUM
% eliminate redundancy
eqn = a0 + a1*p + a2*diff(p,t) == b0 + b1*p + b2*diff(p,t);
cnd = p(0) == 10;


p(t) = dsolve(eqn, cnd);
d(t) = a0 + a1*p + a2*diff(p,t);
s(t) = b0 + b1*p + b2*diff(p,t);

fplot(p);
hold on
fplot(d);
legend("Price", "Demand=Supply");

p
d
s