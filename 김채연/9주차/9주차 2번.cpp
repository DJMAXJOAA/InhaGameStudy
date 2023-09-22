lass Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //bitset 
        bitset<32> bs;
        int count = 0;
        //들어온 값을 2진수로 바꾸는 과정
        while (n != 0)
        {
            bs.set(count, n % 2);
            n /= 2;
            ++count;
        }
        //bitset을 다시 문자열로 바꾸고
        string result = bs.to_string();
        //역순으로 바꿔버립니다.
        reverse(result.begin(), result.end());
        //2진수를 다시 숫자로 바꾸기 위해서 bitset에 다시 넣고
        bitset<32> resultbs(result);
        //숫자로 바꿔버립니다.
        uint32_t find = resultbs.to_ulong();

        return find;
    }
};