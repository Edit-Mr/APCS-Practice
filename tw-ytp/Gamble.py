def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def mod_inverse(a, mod):
    g, x, y = extended_gcd(a, mod)
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % mod

def calculate_probability(m, n, p):
    MOD = 998244353
    q = 100 - p

    # 用來儲存概率的動態規劃表格
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # 邊界條件
    for i in range(m + 1):
        dp[i][0] = 1  # 如果 Bob 的錢是 0，Alice 獲勝概率是 1
    
    for j in range(1, n + 1):
        dp[0][j] = 0  # 如果 Alice 的錢是 0，Alice 獲勝概率是 0
    
    # 動態規劃計算概率
    inv_100 = mod_inverse(100, MOD)
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            dp[i][j] = (p * dp[i][j - 1] + q * dp[i - 1][j]) % MOD
            dp[i][j] = dp[i][j] * inv_100 % MOD
    
    # 返回結果
    result = dp[m][n]
    return result

# 測試輸入
m, n, p = map(int, input().split())
result = calculate_probability(m, n, p)
print(result)
