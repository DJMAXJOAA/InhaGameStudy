lass Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //bitset 
        bitset<32> bs;
        int count = 0;
        //���� ���� 2������ �ٲٴ� ����
        while (n != 0)
        {
            bs.set(count, n % 2);
            n /= 2;
            ++count;
        }
        //bitset�� �ٽ� ���ڿ��� �ٲٰ�
        string result = bs.to_string();
        //�������� �ٲ�����ϴ�.
        reverse(result.begin(), result.end());
        //2������ �ٽ� ���ڷ� �ٲٱ� ���ؼ� bitset�� �ٽ� �ְ�
        bitset<32> resultbs(result);
        //���ڷ� �ٲ�����ϴ�.
        uint32_t find = resultbs.to_ulong();

        return find;
    }
};