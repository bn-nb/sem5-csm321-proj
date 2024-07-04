% FIRST ORDER ODE

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 4th October 2023

syms y(t);
ode = diff(y, t) == t*y;
cond = y(0) == 2;
ySol = dsolve(ode, cond);

cond1 = y(0) == 10;
ySol1 = dsolve(ode, cond1);

% Plot in terminal

hold on
fplot(ySol)
fplot(ySol1)
legend('Soln for y0=2', 'Soln for y0=10')
xlabel('T')
ylabel('Y')


% Clear the variables in environment
% clear all
% Clear outputs
% clc

