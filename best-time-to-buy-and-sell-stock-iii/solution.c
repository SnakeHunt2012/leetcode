#define max(A, B) A > B ? A : B
#define min(A, B) A < B ? A : B

int maxProfit(int* prices, int pricesSize) {
    int i, min_price, max_price, max_profit, pre_profit[pricesSize], post_profit[pricesSize];
    if (pricesSize < 2)
        return 0;
    for (i = 1, min_price = prices[0], pre_profit[0] = 0; i < pricesSize; ++i) {
        pre_profit[i] = max(pre_profit[i - 1], prices[i] - min_price);
        min_price = min(min_price, prices[i]);
    }
    for (i = pricesSize - 2, max_price = prices[pricesSize - 1], post_profit[pricesSize - 1] = 0; i >= 0; --i) {
        post_profit[i] = max(post_profit[i + 1], max_price - prices[i]);
        max_price = max(max_price, prices[i]);
    }
    for (i = max_profit = 0; i < pricesSize; ++i)
        max_profit = max(max_profit, pre_profit[i] + post_profit[i]);
    return max_profit;
}
