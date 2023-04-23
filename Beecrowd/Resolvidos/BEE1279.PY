FLAG = False
while True:
    try:
        year = int(input())
        if FLAG:
            print()
        is_leap = False
        is_hulu = False
        is_bulu = False

        if year % 400 == 0:
            is_leap = True
        elif year % 100 == 0:
            is_leap = False
        elif year % 4 == 0:
            is_leap = True

        if year % 15 == 0:
            is_hulu = True

        if year % 55 == 0 and is_leap:
            is_bulu = True

        if is_leap:
            print("This is leap year.")
        if is_hulu:
            print("This is huluculu festival year.")
        if is_bulu:
            print("This is bulukulu festival year.")
        if not is_leap and not is_hulu and not is_bulu:
            print("This is an ordinary year.")
        FLAG = True
    except EOFError:
        break
