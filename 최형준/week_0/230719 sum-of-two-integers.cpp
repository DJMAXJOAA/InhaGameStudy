class Solution {
public:
	int getSum(int a, int b)
	{
		int _xor = a ^ b;
		unsigned int _and = (a & b);
		_and = _and << 1;
		while (1)
		{
			int xor_temp = _xor;
			unsigned int and_temp = _and;

			_xor = xor_temp ^ and_temp;
			_and = (xor_temp & and_temp) << 1;
			if (_and == 0)
				return _xor;
		}
	}
};