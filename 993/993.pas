var
	Q:longint;
	tc:longint;
	N:longint;
	i:longint;
	a:array[0..9] of longint;

function factors():boolean;
var
	i,j:longint;
begin
	for i:=2 to 9 do a[i]:=0;
	for i:=9 downto 2 do begin
		while N mod i=0 do begin
			N:=N div i;
			a[i]:=a[i]+1;
		end;
	end;
	if N<>1 then exit(false);
	Q:=0;
	for i:=2 to 9 do 
		for j:=1 to a[i] do Q:=Q*10+i;
	exit(true);
end;

begin
	readln(tc);
	for i:=1 to tc do begin
		readln(N);
		if N=1 then
			writeln(1)
		else if factors() then
			writeln(Q)
		else
			writeln(-1);
	end;
end.
