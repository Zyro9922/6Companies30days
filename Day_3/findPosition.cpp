int findPosition(int N , int M , int K) {
        int a = (M + K - 1) % N;
        return a == 0 ? N : a;
}