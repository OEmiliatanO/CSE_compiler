program test;
var 
(* one line comment *)
  i, j, k: integer;
  ans: array[0 .. 81] of integer;
  fa : array[0 .. 97,0 .. 8] of array[0 .. 8] of real;
  s : string;
  i : integer;

begin
    write(i, '*', j, '=', ans[i*9+j], ' ');

    ans[i*9+j] := i mod 2;
    for i:=1 to 9 do 
    begin
        for j:=1 to i do
            k:= i+j;
    end;
    i := 63+ans[0]+fa[0][0][0];
    i := fa[0];
    k := not fa[0][0][0];
    i := 'asb';
    s := 'ss';
    j := 7*3+5*'2';

    if (i = j)
        write(i)
    else
        write(j);
    ans[0] := 7+8;
end.
