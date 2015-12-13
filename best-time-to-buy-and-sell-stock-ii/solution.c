int maxProfit(int* prices, int pricesSize) {
    int i, last_price, profit = 0;
    if (pricesSize < 2)
        return 0;
    for (i = 1, last_price = prices[0]; i < pricesSize; ++i) {
        if (prices[i] > last_price)
            profit += prices[i] - last_price;
        last_price = prices[i];
    }
    return profit;
}
