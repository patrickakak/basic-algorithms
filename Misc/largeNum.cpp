/**
 * Large number calculation (integer w/ more than 1000 digits)
 */
#include <cstdio>
#include <cstring>

#define maxn 1010
struct largeNum {
	int d[maxn];
	int len;
	largeNum() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

// change string into bunch of digits (inversely)
largeNum change(char str[])
{
	largeNum a;
	a.len = strlen(str);
	for (int i=a.len-1, j=0; i >= 0; i--, j++)
		a.d[j] = str[i] - '0';
	return a;
}

int compare(largeNum a, largeNum b)
{
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len-1; i >= 0; i--)
			if (a.d[i] > b.d[i]) return 1;
			else if (a.d[i] < b.d[i]) return -1;
		return 0;
	}
}

largeNum add(largeNum a, largeNum b)
{
	largeNum c;
	int carry = 0;
	for (int i = 0; i < a.len || i < b.len; i++) {
		int tmp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry != 0)
		c.d[c.len++] = carry;
	return c;
}

// Caution: a >= b by default
largeNum sub(largeNum a, largeNum b)
{
	largeNum c;
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	while (c.len-1 >= 1 && c.d[c.len-1] == 0)
		c.len--;
	return c;
}

// since we add one 'whole' integer b at a time, we must 
// use loop when handling carry digits
largeNum multi(largeNum a, int b)
{
	largeNum c;
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int tmp = a.d[i] * b + carry;
		c.d[c.len++] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry != 0) {
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}

// r: remainder (should be 0 when invoking divide())
// c: quotient
largeNum divide(largeNum a, int b, int &r)
{
	largeNum c;
	c.len = a.len;
	for (int i = a.len-1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		if (r < b) c.d[i] = 0;
		else {
			c.d[i] = r / b;
			r = r % b;
		}
	}
	while (c.len-1 >= 1 && c.d[c.len-1] == 0)
		c.len--;
	return c;
}

void print(largeNum a)
{
	for (int i = a.len-1; i >= 0; i--)
		printf("%d", a.d[i]);
}

int main()
{
	// freopen("tst.txt", "r", stdin);
	char str[maxn];
	int num;

	scanf("%s", str);
	scanf("%d", &num);
	largeNum a = change(str);
	largeNum b = multi(a, num);
	print(b);

	return 0;
}


