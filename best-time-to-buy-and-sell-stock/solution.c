int maxProfit(int* prices, int pricesSize) {
    int i, min_price, max_profit = 0;
    if (pricesSize < 2)
        return 0;
    for (i = 1, min_price = prices[0]; i < pricesSize; ++i) {
        max_profit = (prices[i] - min_price > max_profit) ? prices[i] - min_price : max_profit;
        min_price = (prices[i] < min_price) ? prices[i] : min_price;
    }
    return max_profit;
}
