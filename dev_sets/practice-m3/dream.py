from itertools import islice

def main():

    events = {}
    curIndex = 0

    for _ in range(int(input())):
        fullLine = input().split()
        if fullLine[0] == 'E':
            events[fullLine[1]] = curIndex
            curIndex += 1
        elif fullLine[0] == 'D':
            for _ in range(int(fullLine[1])):
                events.popitem()
                curIndex -= 1
        else:
            scenes = islice(fullLine, 2, None)
            remove = 0
            remain = -1
            earlybreak = False
            for scene in scenes:
                if (scene[0] == '!'):
                    cut = scene[1:]
                    if cut in events:
                        remove = max(remove, len(events)-events[cut])
                else:
                    if (scene not in events):
                        print('Plot Error')
                        earlybreak = True
                    else:
                        remain = max(remain, events[scene])
            if earlybreak:
                continue
            if remove == 0:
                print('Yes')
            elif remain >= len(events)-remove:
                print('Plot Error')
            else:
                print(f'{remove} Just A Dream')


if __name__ == "__main__":
    main()