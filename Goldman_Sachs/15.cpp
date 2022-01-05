bool canPair(vector<int> arr, int k) {
    int n = arr.size();
    if (n % 2 != 0)
        return false;
    map<int, int> map;
    for (int val : arr)
        ++map[val % k];

    for (int val : arr) {
        int rem = val % k;
        int rest = (k - rem) % k;
        if (rem == 0 || (k % 2 == 0 && rem == k / 2))
            if (map[rem % k] % 2 != 0)
                return false;
        if (!(map.find(rest) != map.end() && map[rest] > 0 && map.find(rem) != map.end() && map[rem] > 0 && map[rest] == map[rem]))
            return false;
    }
    return true;
}