string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int n = s.length();
    int cycle = 2 * numRows - 2;
    string result;
    for (int i = 0; i < numRows; ++i) {
        for (int j = i; j < n; j += cycle) {
            result += s[j];
            int second = j + cycle - 2 * i;
            if (i != 0 && i != numRows - 1 && second < n) {
                result += s[second];
            }
        }
    }
    return result;
}