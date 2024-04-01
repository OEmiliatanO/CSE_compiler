program test;
var
  i32: longword;
  i64: cardinal;
  i : integer;
  f : real;
  s : string;
begin
  (* this is 
    a comment *)
  read(i);
  (******)
  (*
     *)
  *)
  read(i);
  f := 0.00;
  f := 0..0;
  f := 1e1;
  f := 1e1.;
  f := 2.e3.;
  s := ab';
  s := 'ab;
  s := 'hello []]1''''''';
  s := 'ab'a';
  s := ''a''
  i := i + 001;
  i := i + 0100;
  f := f + 0.1;
  f := f + .1;
  f := f + .0001;
  f := f + 1.;
end;
