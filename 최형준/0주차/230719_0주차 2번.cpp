//============================================================
// 비트 연산으로 +, -사용하지 않고 XOR, AND 연산
// 비트 시프트도 적절히 사용하기
// 1의 보수, 2의 보수법(음수 계산)
// unsigned 범위 체크
//============================================================

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