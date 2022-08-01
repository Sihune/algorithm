from collections import Counter

def solution(participant, completion):
    participant.sort()
    completion.sort()

    print(Counter(participant))
    print(Counter(completion))

    for i in range(0, len(completion)):
        if participant[i] != completion[i]:
            return participant[i]

    return participant[len(completion)]

solution(["leo", "kiki", "eden"], ["eden", "kiki"]	)