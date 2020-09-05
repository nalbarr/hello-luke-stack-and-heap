from value_holders import IntHolder

def loop_heap(size):
    xs = []
    for i in range(0,size):
        print("i: {}".format(i) )
        xs.append(i)

    return size

def loop_heap2(size):
    xs = []
    for i in range(0,size):
        print("i: {}".format(i) )
        xs.append(IntHolder(i))

    return size

def main():

    print("*** loop_heap(5)")
    xs1 = loop_heap(5)

    print("*** loop_heap2(5)")
    xs2 = loop_heap2(5)

if  __name__ == '__main__':
    main()
