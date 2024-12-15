safe_registers = 0

exceeded = False
inverted = False

increasing = False
decreasing = False

with open("adventOfCode2024/inputs/day2.txt", 'r') as file:
    for line in file:

        increasing = False
        decreasing = False

        exceeded = False
        inverted = False

        if line != None:
            numbers = line.split(' ')
            
            for i in range(len(numbers)):
                numbers[i] = int(numbers[i])
            
            for i in range(len(numbers) - 1):

                if numbers[i] > numbers[i + 1]:
                    decreasing = True

                if numbers[i] < numbers[i + 1]:
                    increasing = True
                    
                difference = abs(numbers[i] - numbers[i + 1])
                if difference == 0 or difference > 3:
                    exceeded = True
            
            if decreasing != increasing and decreasing != increasing and not exceeded:
                safe_registers += 1

print(safe_registers)