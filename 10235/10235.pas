var
	a:array[0..1000000] of longint;
	N:longint;

procedure init();
var
	i,j:longint;
begin
	for i:=0 to 1000000 do a[i]:=1;
	for i:=2 to 1000000 do begin
		if a[i]=0 then continue;
		j:=2;
		while i*j<1000000 do begin
			a[i*j]:=0;
			j:=j+1;
		end;
	end;
end;

function reverse(v:longint):longint;
var
	t:longint;
begin
	t:=0;
	while v<>0 do begin
		t:=t*10+v mod 10;
		v:=v div 10;
	end;
	exit(t);
end;

function prime(n:longint):longint;
begin
	if a[n]=0 then exit(0)
	else if n=reverse(n) then exit(1)
	else if a[reverse(n)]=0 then exit(1)
	else exit(2);
end;

begin
	init();
	while not eof do begin
		readln(N);
		case prime(N) of 
			0:writeln(N,' is not prime.');
			1:writeln(N,' is prime.');
			2:writeln(N,' is emirp.');
		end;
	end;
end.
