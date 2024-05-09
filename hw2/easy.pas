program test;
var 
(* one line comment *)
  i, j, k: integer;
  ans: array[0 .. 81] of integer;
begin
    write(i, '*', j, '=', ans[i*9+j], ' ');

    ans[i*9+j] := i mod 2;
    for i:=1 to 9 do 
    begin
        for j:=1 to i do
            k:= i+j;
    end;

    i := 63+1;
    j := 7;
    ans[0] := 7;
end.
