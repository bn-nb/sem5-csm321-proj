% HOMOGENEOUS SYSTEM OF FIRST ORDER ODE

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 4th October 2023

syms v(t) u(t)

ode1 = diff(u,t) == 4*u - 7*v;
ode2 = diff(v,t) == -8*u + 5*v;
odes = [ode1, ode2];

c1 = u(0) == 1;
c2 = v(0) == 0;
conds = [c1,c2];

% s = dsolve(odes);
% uSol(t) = s.u;
% vSol(t) = s.v;

[uSol(t), vSol(t)] = dsolve(odes);
[usol(t), vsol(t)] = dsolve(odes, conds);

fplot(usol);
hold on
fplot(vsol);
% legend('usol', 'vsol');
xlim([-10 10]);
ylim([-5 5]);