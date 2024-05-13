program test;

function findMin: integer;
var
    x, y, z: integer;
begin
    x := 1 + 2;
    y := x;
end;

var 
(* one line comment *)
  i, j, k: integer;
  ans: array[0 .. 81] of integer;
  fa : array[0 .. 97,0 .. 8] of array[0 .. 8] of real;
  s : string;

begin
    write(i, '*', j, '=', ans[i*9+j], ' ');

    ans[i*9+j] := i mod 2;
    for i:=1 to 9 do 
    begin
        for j:=1 to i do
            k:= i+j+findMin;
    end;
    i := 63+ans[0]+fa[0][0][0];
    k := not fa[0][0][0];
    i := 'asb';
    s := 'ss';
    j := 7*3+5*'2';
    ans[0] := 7+8;
end.
