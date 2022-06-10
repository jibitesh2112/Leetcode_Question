int reverse(int x) {
    long long val = 0;
	do 
	{
		val = val * 10 + x % 10;
		x = x/10;
	} while (x);
	
	return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}