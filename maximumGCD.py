from  math import gcd

## 0 < test_sz < 100 , 2 < n < 10^6
def read_input():
    test_sz = int(input())
    tests = []
    for i in range(test_sz):
        tests.append(int(input()))
    return test_sz, tests
    

def maximum_gcd():
    test_sz, tests = read_input()
    for number in tests:
        max_val = 0
        for num1 in range(2,number+1):
            for num2 in range(1,num1):
                temp = gcd(num1,num2)
                if temp > max_val :
                    max_val = temp
        print(max_val)
    

if __name__ == "__main__":
    
    maximum_gcd()    


