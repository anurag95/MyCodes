import math

def calc(n, r):
	fac = math.factorial 
	return fac(n)/(fac(r)*fac(n-r))
t = raw_input()
t = int(t)

for counter in range(0, t):
	line = raw_input()
	line = line.split('-')
	p = int(line[0]);
	q = int(line[1]);
	res1 = ((p-q)*calc(p+q, p)/(p+q)) % 1000000007
	res2 = 0
	for i in range(0, q):
		var = ((q-i)*calc(i+q, i)/(q+i)) % 1000000007
		res2 = (res2 + var) % 1000000007
	
	print "Case #%d: %d %d" %(counter+1, res1, res2)
		
	
