m = menu('choose any method:','Lagranges Linear ','Lagranges Quadratic ', ...
    'Lagranges Cubic ');
switch m
    case 1
         Lagranges_Linear(X,Y,x);
    case 2
        Lagranges_Quadratic(X,Y,x);
    case 3
        Lagranges_Cubic(X,Y,x);
end   