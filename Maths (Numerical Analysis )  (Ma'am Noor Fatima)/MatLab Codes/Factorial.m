
function Factorial(number)
f=1;
if number<0
    disp('negative number!');
else
    for i = 1:number
        f=f*i;
    end
    fprintf('the factorial of %d is %d\n', number,f);
end
