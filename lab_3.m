% HARDY-WEINBURG THEOREM

% B Niranjan
% IDD M&C Part 3
% Roll : 21124015
% 4th October 2023

syms r
p(r) = (1-r^0.5)^2;
q(r) = 2 * r^0.5 * (1 - r^0.5);

fplot(q, [0,1])
hold on
fplot(p, [0,1])
legend('q', 'p')