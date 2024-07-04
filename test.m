a = [[1 2 3 4]; [5 6 7 8]; [9 0 1 2]];

for i=1:3
    for j=1:4
        disp(a(i,j))
        
    end
    disp('y')
end

[b, c, d, e] = a(1,:)
