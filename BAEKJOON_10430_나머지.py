#(A+B)%C
def cal_1(A, B, C):
    return (A+B)%C

#((A%C)+(B%C))%C
def cal_2(A, B, C):
    return ((A%C)+(B%C))%C

#(A*B)%C
def cal_3(A, B, C):
    return (A*B)%C

#((A%C)*(B%C))%C
def cal_4(A, B, C):
    return ((A%C)*(B%C))%C

if __name__ == "__main__":
    A,B,C = map(int, input().split(' '))

    print(cal_1(A,B,C))
    print(cal_2(A,B,C))
    print(cal_3(A,B,C))
    print(cal_4(A,B,C))