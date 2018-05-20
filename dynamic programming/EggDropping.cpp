// egg dropping puzzle

// floors and eggs
int d[n+1][k+1];

for i = 0:n
	d[i][1] = i; // if eggs are 1, then chances = number of floors

for i = 0:k
	d[0][i] = 0;	// 0 chances for 0 floors
	d[1][i] = 1;	// 1 chances for 1 floors

for floors: 1:n
	for eggs: 1:k
		d[floors][eggs] = 1 + max(d[floors-1][eggs-1] + d[n-floors][eggs]); // taking the worst case

	result = min (result, d[floors][eggs]);

return result;



/*
For puzzle question of 100 floors and 2 eggs 
take x + x-1 + x-2 + ... + 1 = 100
*/
