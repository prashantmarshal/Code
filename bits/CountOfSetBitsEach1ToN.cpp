// Idea is to use count of bits in a smaller value


// 1. 
// For a number x, count of set bits = count in x/2 + (x%2)

// 2.
// For a number x, count of set bits = 1 + count in (x - 2^(nearest K)


/* Obviously, when number i equals to math.Pow(2, n), the number of 1's is 1, so when i is between math.Pow(2, n) and math.Pow(2, n + 1), then number of 1's is just 1 + numberOf(i - math.Pow(2, n))

func countBits(num int) []int {
    ans := make([]int, num + 1)
    
    ans[0] = 0
    if num == 0 {
        return ans
    }
    
    ans[1] = 1
    power := 0
    
    for i := 2; i <= num; i++ {
        if i == (int)(math.Pow(2, (float64)(power + 1))) {
            power++
            ans[i] = 1
        } else {
            ans[i] = 1 + ans[i - (int)(math.Pow(2, (float64)(power)))]
        }
    }
    
    return ans
} */